#ifndef __IO_CONTROLLER__
#define __IO_CONTROLLER__

class IOController {
  public:
    IOController() {}
    virtual void DigitalWrite(unsigned char pin, unsigned char state) = 0;
    virtual void PinMode(unsigned char pin, unsigned char mode) = 0;
};

#endif
