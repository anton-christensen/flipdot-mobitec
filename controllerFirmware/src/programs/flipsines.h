#ifndef __FLIP_SINES__
#define __FLIP_SINES__

#include "screenprogram.h"
#include <Arduino.h>
#include <math.h>

class FlipSines : public ScreenProgram {
  private:

    float t1 = 0;
    float t2 = 0;
    float tinc1 = 0.0001;
    float tinc2 = 0.0001;
    float scale = 0.08;
    unsigned long lastUpdate = 0;
    struct osn_context* context;
  public:
    FlipSines(FlipScreen* _sign) : ScreenProgram(_sign) {}

    void start() {
    }

    void stop() {
    }

    float round(float x) {
      float d = (x-(int)x);
      if(d < 0.5) return (int)x;
      return (int)x+1;
    }

    void loop(char* input) {
      if(input != NULL) {
        if(strcmp("up", input) == 0) {
          tinc1 *= 1.1;
        }
        if(strcmp("down", input) == 0) {
          tinc1 *= 0.9;
        }
        if(strcmp("left", input) == 0) {
          tinc2 *= 1.1;
        }
        if(strcmp("right", input) == 0) {
          tinc2 *= 0.9;
        }
      }
      if(millis()-lastUpdate < 1) return;
      t1+=tinc1;
      t2+=tinc2;

      sign->clear();
      for(int x = 0; x < PANEL_WIDTH; x++) {
        float y1 = round((PANEL_HEIGHT/5)*sin(-t1 + (x/10.0)));
        float y2 = round((PANEL_HEIGHT/3)*sin((-t2+PI/4) + (x/10.0)));
        sign->putPixel(x, PANEL_HEIGHT/2 + y1+y2, WHITE);
      }



      sign->flip();
      lastUpdate = millis();
    }
};

#endif