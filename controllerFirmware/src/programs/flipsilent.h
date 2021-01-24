#ifndef __FLIP_SILENT__
#define __FLIP_SILENT__

#include "screenprogram.h"

class FlipSilent : public ScreenProgram {
  private:
    unsigned char color;
  public:
    FlipSilent(FlipScreen* _sign) : ScreenProgram(_sign) {
      color = BLACK;
    }

    void start() {
      if(sign) {
        sign->clear(color);
        sign->flip();
      }
    }

    void stop() {}

    void loop(char* input) {
      if(input == NULL) return;
      if(strcmp("up", input) == 0 || strcmp("down", input) == 0) {
        color = (color == BLACK ? WHITE : BLACK);
        if(!sign) return;
        sign->clear(color);
        sign->flip();
      }
    }
};

#endif