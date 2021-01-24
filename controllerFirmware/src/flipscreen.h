#ifndef __FLIPSCREEN__
#define __FLIPSCREEN__

#include <Arduino.h>

#include <tuple>
#include <vector>

#include "iocontroller.h"
#include "fonts/font.h"
#include "fonts/terminus12b.h"
#include "fonts/tomthumb4x6.h"
// #include "2dbitmap.h"


#define DONOTHING 3
#define TOGGLE 2
#define BLACK 1
#define WHITE 0

#define ON true
#define OFF false

#define PANEL_WIDTH 112
#define PANEL_HEIGHT 20
// Yellow config
// #define PANEL_WIDTH 112
// #define PANEL_HEIGHT 16

class FlipScreen {
  private:
    unsigned char index_to_bitpattern_map[28];
    unsigned char gpiostate[40];
    unsigned char backlight_state = OFF;

    // Bitmap2D _screenState(PANEL_WIDTH, PANEL_HEIGHT);
    // Bitmap2D _screenBuffer(PANEL_WIDTH, PANEL_HEIGHT);

    unsigned char screenState[PANEL_WIDTH][PANEL_HEIGHT] PROGMEM;
    unsigned char screenBuffer[PANEL_WIDTH][PANEL_HEIGHT] PROGMEM;

    const unsigned char panel_triggers[4] = {13,14,15,16};
    const unsigned char row_addr_pins[5] =  {25,26,27,32,33};
    const unsigned char col_addr_pins[5] =  {18,19,21,22,23};
    const unsigned char color_pin = 17;
    const unsigned char backlight_pin = 24;

    // // unsigned short blackToWhiteMicroseconds = 120; // 150
    // unsigned short blackToWhiteMicroseconds = 300;
    unsigned short blackToWhiteMicroseconds = 1000;
    // // unsigned short WhiteToBlackMicroseconds = 100;
    // unsigned short WhiteToBlackMicroseconds = 300;
    unsigned short WhiteToBlackMicroseconds = 1000;



    Font* font; 
    Font* font1; 
    Font* font2;
    IOController* io;



    int index_to_bitpattern(int index);
    void _digitalWrite(unsigned char pin, unsigned char state);

  public:
    FlipScreen(IOController* _io);
    void flip(unsigned long transitionTime = 0, bool longForcing = false);
    void _setDot(unsigned int x, unsigned int y, unsigned char color, bool longForcing = false);
    void putPixel(unsigned int x, unsigned int y, unsigned char color, unsigned char* screenBuffer = NULL);
    void fillRect(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, unsigned char color);
    void clear(unsigned char color = BLACK);
    void putChar(unsigned int x, unsigned int y, char c, unsigned char color = WHITE, unsigned char* screenBuffer = NULL);
    void write(const char* str, int x = -1, int y = -1, unsigned char color = WHITE, unsigned char* screenBuffer = NULL);
    void setBacklight(bool state);
    void setFont(int fontIndex);
    void redraw();
    void idle();
    bool getBacklight();
    void screenToUart();
};





#endif

