#include "flipscreen.h"

int FlipScreen::index_to_bitpattern(int index) {
  return 1+index + (index/7);
}

void FlipScreen::_digitalWrite(unsigned char pin, unsigned char state) {
  if(this->gpiostate[pin] == state) return;
  this->gpiostate[pin] = state;
  io->DigitalWrite(pin, state);
}

FlipScreen::FlipScreen(IOController* _io) {
  font1 = new Font(10,18, (const uint16_t*)font_terminus_10x12);
  font2 = new Font(  4, 6, (const uint16_t*)font_tom_thumb_4x6);
  font  = font2;

  this->io = _io;

  // fill fast index-map
  for(int i = 0; i < 28; i++) {
    index_to_bitpattern_map[i] = index_to_bitpattern(i);
  }
  
  // reset lookup tables
  for(int i = 0; i < 40; i++) {
    this->gpiostate[i] = 0xFF;
  }

  // set control pins to output
  io->PinMode(this->color_pin, OUTPUT);
  for(int i = 0; i < 4; i++) {
    io->PinMode(this->panel_triggers[i], OUTPUT);
  }
  for(int i = 0; i < 5; i++) {
    io->PinMode(this->row_addr_pins[i], OUTPUT);
    io->PinMode(this->col_addr_pins[i], OUTPUT);
  }

  // io->pinMode(backlight_pin, OUTPUT);
  // io->digitalWrite(backlight_pin, backlight_state);

  // clear the screen
  for(int x = 0; x < PANEL_WIDTH; x++) {
    for(int y = 0; y < PANEL_HEIGHT; y++) {
      screenState[x][y] = 0xFF;
      screenBuffer[x][y] = BLACK;
    }
  }
}

void FlipScreen::flip(unsigned long transitionTime, bool longForcing) {
  std::vector<std::tuple<int, int>> changes;
  for(int y = 0; y < PANEL_HEIGHT; y++) {
    for(int x = 0; x < PANEL_WIDTH; x++) {
      // _setDot(x,y,screenBuffer[x][y]);
      if(screenState[x][y] != screenBuffer[x][y]) {
        changes.push_back(std::make_tuple(x,y));
      }
    }
  }
  unsigned long nDots = changes.size();
  if(nDots == 0) return;

  std::random_shuffle ( changes.begin(), changes.end() );
  unsigned long lastFlip = 0;
  unsigned long delayTime = transitionTime / nDots;
  for(std::tuple<int,int> coord : changes) {
    _setDot(std::get<0>(coord), std::get<1>(coord), screenBuffer[std::get<0>(coord)][std::get<1>(coord)], longForcing);
    if(delayTime != 0 && millis() - lastFlip >= delayTime) {
      lastFlip = millis();
      delay(delayTime);
    }
  }
}

void FlipScreen::putPixel(unsigned int x, unsigned int y, unsigned char color, unsigned char* altBuffer) {
  if(altBuffer == NULL) {
    if(x < 0 || y < 0 || x >= PANEL_WIDTH || y >= PANEL_HEIGHT) return;
    screenBuffer[x][y] = (color == TOGGLE ? !screenBuffer[x][y] : color);
  }
  else {
    if(y < 0 || y > PANEL_HEIGHT) return;
    altBuffer[y+x*PANEL_HEIGHT] =  (color == TOGGLE ? !altBuffer[y+x*PANEL_HEIGHT] : color);
  }
}
void FlipScreen::_setDot(unsigned int x, unsigned int y, unsigned char color, bool longForcing) {
  if(x < 0 || y < 0 || x >= PANEL_WIDTH || y >= PANEL_HEIGHT || color > 1 || this->screenState[x][y] == color) return;
  this->screenState[x][y] = color;

  int panel = x/28;
  x %= 28;

  for(int i = 0; i < 5; i++) {
    _digitalWrite(this->row_addr_pins[i], index_to_bitpattern_map[y]&(1<<i));
    _digitalWrite(this->col_addr_pins[i], index_to_bitpattern_map[x]&(1<<i));
  }
  
  _digitalWrite(this->color_pin, color);

  delayMicroseconds(10);
  _digitalWrite(this->panel_triggers[panel], HIGH);
  // delayMicroseconds(color == BLACK ? 300 : 300); 
  
  delayMicroseconds(longForcing ? 1000 : color == BLACK ? this->WhiteToBlackMicroseconds : this->blackToWhiteMicroseconds); 
  _digitalWrite(this->panel_triggers[panel], LOW);
  delayMicroseconds(10);
}

void FlipScreen::fillRect(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, unsigned char color) {
  for(int y = y1; y < y2; y++) {
    for(int x = x1; x < x2; x++) {
      this->putPixel(x,y, color);
    }
  }
}

void FlipScreen::clear(unsigned char color /*= BLACK*/ ) {
  for(int y = 0; y < PANEL_HEIGHT; y++) {
    for(int x = 0; x < PANEL_WIDTH; x++) {
      this->putPixel(x,y, color);
    }
  }
}

void FlipScreen::putChar(unsigned int x, unsigned int y, char c, unsigned char color, unsigned char* altBuffer) {
  for(int _x = 0; _x < font->getCharWidth(c); _x++) {
    for(int _y = 0; _y < font->getCharHeight(); _y++) {
      if(font->getCharBit(c,_x,_y))
        this->putPixel(x+_x, y+_y, color, altBuffer);
    }
  }
}

void FlipScreen::write(const char* str, int x, int y, unsigned char color, unsigned char* altBuffer) {
  int strlen = 0;
  int strwidth = 0;
  unsigned int index = 0;
  while(str[strlen] != '\0') { 
    char c = str[strlen];
    strlen++;
    strwidth += font->getCharWidth(c);
  }
  int _x = x;
  int _y = y;

  if(x < 0)
    _x = -1 + PANEL_WIDTH/2 - (strwidth/2);
  if(y < 0)
    _y = (PANEL_HEIGHT-font->getCharHeight())/2;
  
  char c;
  while((c = str[index++]) != '\0') {
    this->putChar(_x, _y, c, color, altBuffer);
    _x += font->getCharWidth(c);
  }

}

void FlipScreen::setBacklight(bool state) {
  backlight_state = state;
  // io->digitalWrite(backlight_pin, state);
}

bool FlipScreen::getBacklight() {
  return backlight_state;
}

void FlipScreen::setFont(int fontIndex) {
  switch(fontIndex) {
    case 1: font = font1; break;
    case 2: font = font2; break;
  }
}

void FlipScreen::redraw() {
  for(int i = 0; i < PANEL_HEIGHT; i++) {
    for(int j = 0; j < PANEL_WIDTH; j++) {
      screenBuffer[j][i] = screenState[j][i];
      screenState[j][i] = -1;
    }
  }
  flip(0,true);
}

void FlipScreen::idle() {
  static unsigned long lastUpdate = 0;
  if(millis() - lastUpdate < 1000) return;
  lastUpdate = millis();
  // static unsigned char x = 0;
  // static unsigned char y = 0;
  unsigned char x = rand() % PANEL_WIDTH;
  unsigned char y = rand() % PANEL_HEIGHT;
  unsigned char oldState = this->screenState[x][y];
  this->screenState[x][y] = -1;
  this->_setDot(x,y,oldState, true);

  
  if(++x >= PANEL_WIDTH) { x = 0; y++; }
}

void FlipScreen::screenToUart() {
  Serial.println();
  for(int y = 0; y < PANEL_HEIGHT; y++) {
    for(int x = 0; x < PANEL_WIDTH; x++) {
      Serial.print(this->screenState[x][y] ? '.' : '*');
    }
    Serial.println();
  }
  Serial.println();

}