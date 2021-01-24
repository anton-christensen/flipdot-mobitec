#ifndef __FLIP_PERLIN__
#define __FLIP_PERLIN__

#include "screenprogram.h"
#include "simplex.h"
#include <Arduino.h>
#include <math.h>

class FlipPerlin : public ScreenProgram {
  private:

    double t = 0;
    double tinc = 0.01;
    double scale = 0.08;
    bool dithered = true;
    unsigned long lastUpdate = 0;
    struct osn_context* context;
  public:
    FlipPerlin(FlipScreen* _sign) : ScreenProgram(_sign) {}

    void start() {
      open_simplex_noise(millis(), &context);
    }

    void stop() {
      open_simplex_noise_free(context);
    }

    void loop(char* input) {
      if(input != NULL) {
        if(strcmp("up", input) == 0) {
          tinc *= 1.1;
        }
        if(strcmp("down", input) == 0) {
          tinc *= 0.9;
        }
        if(strcmp("left", input) == 0) {
          scale *= 0.9;
        }
        if(strcmp("right", input) == 0) {
          scale *= 1.1;
        }
        if(strcmp(" ", input) == 0) {
          dithered = !dithered;
        }
      }
      if(micros()-lastUpdate < 10) return;
      t+=tinc;


      // Floyd–Steinberg dithering
      // static float tmp[PANEL_WIDTH][PANEL_HEIGHT] PROGMEM;

      // for(int y = 0; y < PANEL_HEIGHT; y++)
      //   for(int x = 0; x < PANEL_WIDTH; x++)
      //     tmp[x][y] = (open_simplex_noise3(context, (x-(PANEL_WIDTH/2))*scale, (y-(PANEL_HEIGHT/2))*scale, t)+1)/2.0;


      // for (int y = 0; y < PANEL_HEIGHT; y++){
      //   for (int x = 0; x < PANEL_WIDTH; x++){
      //     float oldpixel = tmp[x][y];
      //     float newpixel  = (oldpixel > 0.5) ? 1.0 : 0.0;
      //     tmp[x][y] = newpixel;
      //     float propagationErreur = oldpixel - newpixel;

      //     if(x < PANEL_WIDTH-1)                       tmp[x+1][y  ] = tmp[x+1][y  ]  + (7.0/16) * propagationErreur;
      //     if(x > 0 && y < PANEL_HEIGHT-1)             tmp[x-1][y+1] = tmp[x-1][y+1]  + (3.0/16) * propagationErreur;
      //     if(y < PANEL_HEIGHT-1)                      tmp[x  ][y+1] = tmp[x  ][y+1]  + (5.0/16) * propagationErreur;
      //     if(x < PANEL_WIDTH-1 && y < PANEL_HEIGHT-1) tmp[x+1][y+1] = tmp[x+1][y+1]  + (1.0/16) * propagationErreur;
      //   }
      // }
      
      // for(int y = 0; y < PANEL_HEIGHT; y++)
      //   for(int x = 0; x < PANEL_WIDTH; x++)
      //     sign->putPixel(x, y, tmp[x][y] > 0.5 ? WHITE : BLACK);
      
      static double ditherMatrix[4][4] = {{-1.0, 0.0, -0.75, 0.25}, {0.5, -0.5, 0.75, -0.25}, {-0.625, 0.375, -0.875, 0.125}, {0.875, -0.125, 0.625, -0.375}};
      // static double ditherMatrix[2][2] = {{-1.0, 0}, {0.5, -0.5}};

      for(int x = 0; x < PANEL_WIDTH; x++) {
        for(int y = 0; y < PANEL_HEIGHT; y++) {
          double sample = open_simplex_noise3(context, (x-(PANEL_WIDTH/2))*scale, (y-(PANEL_HEIGHT/2))*scale, t);
          char color;
          if(dithered) {
            double limit = ditherMatrix[x%4][y%4];
            color =  sample > (limit/8) ? WHITE : BLACK;
          }
          else {
            color = sample > 0 ? WHITE : BLACK;
          }
          sign->putPixel(x, y, color);
        }
      }


      sign->flip();
      lastUpdate = millis();
    }
};

#endif