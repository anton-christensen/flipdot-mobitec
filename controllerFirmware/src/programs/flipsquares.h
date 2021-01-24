#ifndef __FLIP_SQUARES__
#define __FLIP_SQUARES__

#include "screenprogram.h"

class FlipSquares : public ScreenProgram {
  private:
    unsigned long transitionTime = 1000;
  public:
    FlipSquares(FlipScreen* _sign) : ScreenProgram(_sign) {
      
    }

    void start() {
      sign->clear();
    }

    void stop() {
    }

    void loop(char* input) {
      if(input != NULL) {
        if(strcmp(input, "up") == 0) {
          transitionTime += 100;
        }
        if(strcmp(input, "down") == 0) {
          transitionTime -= 100;
        }
      }

      static unsigned char color = BLACK;
      sign->fillRect(rand()%PANEL_WIDTH, rand()%(PANEL_WIDTH+1), rand()%PANEL_HEIGHT, rand()%(PANEL_HEIGHT+1), color);
      color = !color;
      sign->flip(transitionTime);
    }
};

#endif