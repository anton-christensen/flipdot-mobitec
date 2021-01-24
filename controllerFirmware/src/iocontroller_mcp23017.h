#ifndef __IO_CONTROLLER_MCP23017__
#define __IO_CONTROLLER_MCP23017__

#include "iocontroller.h"
#include <Wire.h>
#include <Arduino.h>

#define MCP23017_I2CADDR 0x27
#define MCP23017_PORT_B_REG_BIT 0x10
#define MCP23017_REG_IODIR 0x00
#define MCP23017_REG_GPPUA 0x0C
#define MCP23017_REG_OLATA 0x14

class IOController_MCP23017 : public IOController {
  private:
    unsigned short portABState = 0;

    void _set_reg(unsigned char reg, unsigned short value) {
      unsigned char error = 0;
      unsigned char retries = 10;
      do {
        if(error != 0) {
          Serial.print("MCP23017 error: ");
          Serial.println(error);
          Serial.print("MCP23017 reg: ");
          Serial.println(reg);
          Serial.print("MCP23017 val: ");
          Serial.println(value);
          delay(1);
          Wire.begin();
        }
        // Serial.print("setting reg ");
        // Serial.print(reg);
        // Serial.print(" to val ");
        // Serial.print(value);
        // Serial.println();
        Wire.beginTransmission(MCP23017_I2CADDR); 
        Wire.write(reg);
        Wire.write(value);
        error = Wire.endTransmission(true);
      }
      while(error != 0 && --retries);
    }
  public:
    IOController_MCP23017() : IOController() {
      Wire.begin();
      Serial.println("GPIO controller configuring");
      Wire.begin();
      Wire.setClock(100000);
      Serial.println("GPIO controller setting reg 0");
      _set_reg(MCP23017_REG_IODIR, 0x00);
      Serial.println("GPIO controller setting reg 2");
      _set_reg(MCP23017_REG_GPPUA, 0xFF);
      Serial.println("GPIO controller setting reg 4");
      _set_reg(MCP23017_REG_OLATA, 0x00);
    }

    void DigitalWrite(unsigned char pin, unsigned char state) {
      if(state)
        portABState |= 1<<pin;
      else
        portABState &= ~(1<<pin);

      _set_reg(MCP23017_REG_OLATA, portABState);
    }

    void DinMode(unsigned char pin, unsigned char mode) {
      // TODO: 
    }


};

#endif