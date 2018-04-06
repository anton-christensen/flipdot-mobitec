#include "flipscreen.h"

int FlipScreen::index_to_bitpattern(int index) {
  return 1+index + (index/7);
}

void FlipScreen::_digitalWrite(unsigned char pin, unsigned char state) {
  if(this->gpiostate[pin] == state) return;
  this->gpiostate[pin] = state;
  digitalWrite(pin, state);
}

FlipScreen::FlipScreen() {
  // fill fast index-map
  for(int i = 0; i < 28; i++) {
    index_to_bitpattern_map[i] = index_to_bitpattern(i);
  }
  
  // reset lookup tables
  for(int i = 0; i < 40; i++) {
    this->gpiostate[i] = 0xFF;
  }

  // set control pins to output
  pinMode(this->color_pin, OUTPUT);
  for(int i = 0; i < 4; i++) {
    pinMode(this->panel_triggers[i], OUTPUT);
  }
  for(int i = 0; i < 5; i++) {
    pinMode(this->row_addr_pins[i], OUTPUT);
    pinMode(this->col_addr_pins[i], OUTPUT);
  }

  // clear the screen
  for(int x = 0; x < PANEL_WIDTH; x++) {
    for(int y = 0; y < PANEL_HEIGHT; y++) {
      screen[x][y] = 0xFF;
    }
  }
}

void FlipScreen::putPixel(unsigned int x, unsigned int y, unsigned char color) {
  if(x >= PANEL_WIDTH || y >= PANEL_HEIGHT || color > 1 || this->screen[x][y] == color) return;
  this->screen[x][y] = color;

  int panel = x/28;
  x %= 28;

  for(int i = 0; i < 5; i++) {
    _digitalWrite(this->row_addr_pins[i], index_to_bitpattern_map[y]&(1<<i));
    _digitalWrite(this->col_addr_pins[i], index_to_bitpattern_map[x]&(1<<i));
  }

  _digitalWrite(this->color_pin, color);

  _digitalWrite(this->panel_triggers[panel], HIGH);
  delay(1); // TODO: this may be more time than required
  _digitalWrite(this->panel_triggers[panel], LOW);
  delay(1); // TODO: this may be more time than required
}

void FlipScreen::fillRect(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, unsigned char color) {
  for(; y1 <= y2; y1++) {
    for(; x1 <= x2; x1++) {
      this->putPixel(x1,y1, color);
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

void FlipScreen::putChar(unsigned int x, unsigned int y, char c) {
  for(int _x = 0; _x < 10; _x++) {
    for(int _y = 0; _y < 18; _y++) {
      this->putPixel(x+_x, y+_y, (font[c][_y]&((1<<16)>>_x)) ? WHITE : BLACK);
    }
  }
}

void FlipScreen::write(const char* str) {
  int strlen = 0;
  unsigned int index = 0;
  while(str[strlen] != '\0') strlen++;
  
  int x = -1 + PANEL_WIDTH/2 - (strlen*10/2);
  
  char c;
  while((c = str[index++]) != '\0') {
    this->putChar(x, -2, c);
    x += 10;
  }
}

void FlipScreen::screenToUart() {
  Serial.println();
  for(int y = 0; y < PANEL_HEIGHT; y++) {
    for(int x = 0; x < PANEL_WIDTH; x++) {
      Serial.print(this->screen[x][y] ? '.' : '*');
    }
    Serial.println();
  }
  Serial.println();

}
