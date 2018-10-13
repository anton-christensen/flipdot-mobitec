#ifndef __IO_CONTROLLER_MCP23017__
#define __IO_CONTROLLER_MCP23017__

#include "iocontroller.h"
#include <Wire.h>
#include <Arduino.h>

#define MCP23017_I2CADDR 0x27
#define MCP23017_PORT_B_REG_BIT 0x10
#define MCP23017_REG_IODIR 0x0
#define MCP23017_REG_GPPUA 0x6
#define MCP23017_REG_OLATA 0xA

class IOController_MCP23017 : public IOController {
  private:
    unsigned short portABState = 0;

    void _set_reg(unsigned char reg, unsigned char value) {
      unsigned char error = 0;
      do {
        if(error > 0) {
          Serial.print("MCP23017 error: ");
          Serial.println(error);
        }
        Serial.print("setting reg ");
        Serial.print(reg);
        Serial.print(" to val ");
        Serial.print(value);
        Serial.println();
        Wire.beginTransmission(MCP23017_I2CADDR); 
        Wire.write(reg);
        Wire.write(value);
      }
      while(!(error = Wire.endTransmission()));
    }
  public:
    IOController_MCP23017() : IOController() {
      Serial.println("GPIO controller configuring");
      Wire.begin();
      Wire.setClock(100000);
      Serial.println("GPIO controller setting reg 0");
      _set_reg(MCP23017_REG_IODIR, 0x00);
      Serial.println("GPIO controller setting reg 1");
      _set_reg(MCP23017_REG_IODIR | MCP23017_PORT_B_REG_BIT, 0x00);
      Serial.println("GPIO controller setting reg 2");
      _set_reg(MCP23017_REG_GPPUA, 0xFF);
      Serial.println("GPIO controller setting reg 3");
      _set_reg(MCP23017_REG_GPPUA | MCP23017_PORT_B_REG_BIT, 0xFF);
      Serial.println("GPIO controller setting reg 4");
      _set_reg(MCP23017_REG_OLATA, 0x00);
      Serial.println("GPIO controller setting reg 5");
      _set_reg(MCP23017_REG_OLATA | MCP23017_PORT_B_REG_BIT, 0x00);
      Serial.println("GPIO controller configured correctly");
    }

    void digitalWrite(unsigned char pin, unsigned char state) {
      if(state)
        portABState |= 1<<pin;
      else
        portABState &= ~(1<<pin);

      if(pin < 8) {
        _set_reg(MCP23017_REG_OLATA, portABState & 0xFF);
      }
      else {
        _set_reg(MCP23017_REG_OLATA | MCP23017_PORT_B_REG_BIT, portABState >> 8);
      }
    }

    void pinMode(unsigned char pin, unsigned char mode) {
      // TODO: 
    }


};

#endif