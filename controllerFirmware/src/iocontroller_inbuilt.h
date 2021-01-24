#ifndef __IO_CONTROLLER_inbuilt__
#define __IO_CONTROLLER_inbuilt__

#include "iocontroller.h"
#include <Arduino.h>

class IOController_inbuilt : public IOController {
  public:
    IOController_inbuilt() : IOController() {}

    void DigitalWrite(unsigned char pin, unsigned char state) {
    	digitalWrite(pin, state);
    }

    void PinMode(unsigned char pin, unsigned char mode) {
      pinMode(pin, mode);
    }


};

#endif