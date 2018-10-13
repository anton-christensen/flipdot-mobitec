#include "flipscreen.h"

int FlipScreen::index_to_bitpattern(int index) {
  return 1+index + (index/7);
}

void FlipScreen::_digitalWrite(unsigned char pin, unsigned char state) {
  if(this->gpiostate[pin] == state) return;
  this->gpiostate[pin] = state;
  io->digitalWrite(pin, state);
}

FlipScreen::FlipScreen(IOController* _io) {
  font1 = new Font(10,18, (const uint16_t*)font_terminus_10x12);
  font2 = new Font(  4, 6, (const uint16_t*)font_tom_thumb_4x6);
  font  = font1;
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
  io->pinMode(this->color_pin, OUTPUT);
  for(int i = 0; i < 4; i++) {
    io->pinMode(this->panel_triggers[i], OUTPUT);
  }
  for(int i = 0; i < 5; i++) {
    io->pinMode(this->row_addr_pins[i], OUTPUT);
    io->pinMode(this->col_addr_pins[i], OUTPUT);
  }

  io->pinMode(backlight_pin, OUTPUT);
  io->digitalWrite(backlight_pin, backlight_state);

  // clear the screen
  for(int x = 0; x < PANEL_WIDTH; x++) {
    for(int y = 0; y < PANEL_HEIGHT; y++) {
      screenState[x][y] = 0xFF;
      screenBuffer[x][y] = BLACK;
    }
  }
}

void FlipScreen::flip() {
  for(int x = 0; x < PANEL_WIDTH; x++) {
    for(int y = 0; y < PANEL_HEIGHT; y++) {
      _setDot(x,y,screenBuffer[x][y]);
    }
  }
}

void FlipScreen::putPixel(unsigned int x, unsigned int y, unsigned char color, unsigned char* altBuffer) {
  if(altBuffer == NULL) {
    if(x < 0 || y < 0 || x >= PANEL_WIDTH || y >= PANEL_HEIGHT) return;
    screenBuffer[x][y] = color;
  }
  else {
    if(y < 0 || y > PANEL_HEIGHT) return;
    altBuffer[y+x*PANEL_HEIGHT] = color;
  }
}
void FlipScreen::_setDot(unsigned int x, unsigned int y, unsigned char color) {
  if(x < 0 || y < 0 || x >= PANEL_WIDTH || y >= PANEL_HEIGHT || color > 1 || this->screenState[x][y] == color) return;
  this->screenState[x][y] = color;

  int panel = x/28;
  x %= 28;

  for(int i = 0; i < 5; i++) {
    _digitalWrite(this->row_addr_pins[i], index_to_bitpattern_map[y]&(1<<i));
    _digitalWrite(this->col_addr_pins[i], index_to_bitpattern_map[x]&(1<<i));
  }
  _digitalWrite(this->color_pin, color);

  _digitalWrite(this->panel_triggers[panel], HIGH);
  delayMicroseconds(350); 
  _digitalWrite(this->panel_triggers[panel], LOW);
  delayMicroseconds(10);
}

void FlipScreen::fillRect(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, unsigned char color) {
  for(int y = y1; y <= y2; y++) {
    for(int x = x1; x <= x2; x++) {
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

void FlipScreen::putChar(unsigned int x, unsigned int y, char c, unsigned char inverted, unsigned char* altBuffer) {
  for(int _x = 0; _x < font->getCharWidth(c); _x++) {
    for(int _y = 0; _y < font->getCharHeight(); _y++) {
      if(!inverted)
        this->putPixel(x+_x, y+_y, (font->getCharBit(c,_x,_y)) ? WHITE : BLACK, altBuffer);
      else
        this->putPixel(x+_x, y+_y, (font->getCharBit(c,_x,_y)) ? BLACK : WHITE, altBuffer);
    }
  }
}

void FlipScreen::write(const char* str, int x, int y, unsigned char inverted, unsigned char* altBuffer) {
  int strlen = 0;
  int strwidth = 0;
  unsigned int index = 0;
  while(str[strlen] != '\0') { strwidth += font->getCharWidth(str[strlen++]); };
  
  int _x = x;
  int _y = y;

  if(x < 0)
    _x = -1 + PANEL_WIDTH/2 - (strwidth/2);
  if(y < 0)
    _y = (PANEL_HEIGHT-font->getCharHeight())/2;
  
  char c;
  while((c = str[index++]) != '\0') {
    this->putChar(_x, _y, c, inverted, altBuffer);
    _x += font->getCharWidth(c);
  }
}

void FlipScreen::setBacklight(bool state) {
  backlight_state = state;
  io->digitalWrite(backlight_pin, state);
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
  flip();
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