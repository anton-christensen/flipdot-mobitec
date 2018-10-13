#ifndef __FONT__
#define __FONT__

#include <Arduino.h>

class Font {
  private:
    int charWidth, charHeight, bitWidth, nchars;
    const uint16_t* bitmap;
  public:
    Font(unsigned int charWidth, unsigned int charHeight, const uint16_t* bitmap) {
      this->charWidth = charWidth;
      this->charHeight = charHeight;
      this->bitWidth = charWidth + (8-charWidth%8);
      this->bitmap = bitmap;
      this->nchars = 127;
    }

    bool getCharBit(char character, int x, int y) {
      return pgm_read_word(bitmap + character*(this->charHeight+1) + y+1) & (0x8000>>x);
    }

    int getCharWidth(char character) {
      return pgm_read_word(bitmap + character*(this->charHeight+1));
    }

    int getCharHeight() {
      return charHeight;
    }
};

#endif