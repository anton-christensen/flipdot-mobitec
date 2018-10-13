#ifndef __FLIPSCREEN__
#define __FLIPSCREEN__

#include <Arduino.h>

#include "iocontroller.h"
#include "fonts/font.h"
#include "fonts/terminus12b.h"
#include "fonts/tomthumb4x6.h"

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

    unsigned char screenState[PANEL_WIDTH][PANEL_HEIGHT] PROGMEM;
    unsigned char screenBuffer[PANEL_WIDTH][PANEL_HEIGHT] PROGMEM;

    const unsigned char panel_triggers[4] = {6,9,7,8};
    const unsigned char row_addr_pins[5] =  {0,1,14,13,2};
    const unsigned char col_addr_pins[5] =  {3,12,4,11,5};
    const unsigned char color_pin = 10;
    const unsigned char backlight_pin = 15;
    // const unsigned char panel_triggers[4] = {16,9,8,10};
    // const unsigned char row_addr_pins[5] =  {19,21,36,39,22};
    // const unsigned char col_addr_pins[5] =  {23,25,18,26,17};
    // const unsigned char color_pin = 27;
    // const unsigned char backlight_pin = 7;

    Font* font; 
    Font* font1; 
    Font* font2;
    IOController* io;



    int index_to_bitpattern(int index);
    void _digitalWrite(unsigned char pin, unsigned char state);

  public:
    FlipScreen(IOController* _io);
    void flip();
    void _setDot(unsigned int x, unsigned int y, unsigned char color);
    void putPixel(unsigned int x, unsigned int y, unsigned char color, unsigned char* screenBuffer = NULL);
    void fillRect(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, unsigned char color);
    void clear(unsigned char color = BLACK);
    void putChar(unsigned int x, unsigned int y, char c, unsigned char inverted = false, unsigned char* screenBuffer = NULL);
    void write(const char* str, int x = -1, int y = -1, unsigned char inverted = false, unsigned char* screenBuffer = NULL);
    void setBacklight(bool state);
    void setFont(int fontIndex);
    void redraw();
    bool getBacklight();
    void screenToUart();
};





#endif

