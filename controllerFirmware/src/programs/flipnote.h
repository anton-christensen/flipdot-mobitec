#ifndef __FLIP_NOTE__
#define __FLIP_NOTE__

#include "screenprogram.h"
#include "simplex.h"
#include <Arduino.h>
#include <math.h>

class FlipNote : public ScreenProgram {
  private:
    char noteText[128];
    unsigned char cursor = 0;
    unsigned char font = 1;

    void update() {
        sign->setFont(font);
        sign->clear();
        sign->write(noteText);
        sign->flip();
    }

  public:
    FlipNote(FlipScreen* _sign) : ScreenProgram(_sign) {
        noteText[0] = '_';
        noteText[1] = '\0';
    }

    void start() {
        update();
    }

    void stop() {
    }

    void loop(char* input) {
        if(input != NULL) {
            if(strlen(input) == 1) {
                noteText[cursor++] = input[0];
                noteText[cursor] = '\0';
            }
            
            if(strcmp("backspace", input) == 0 && cursor > 0) {
                cursor--;
                if(cursor == 0)
                    noteText[cursor] = '_';
                else {
                    noteText[cursor] = '\0';
                }
            }
            if(strcmp("up", input) == 0) {
                font = (font == 1 ? 2 : 1);
            }
            if(strcmp("down", input) == 0) {
                font = (font == 1 ? 2 : 1);
            }
            update();
        }
    }
};

#endif