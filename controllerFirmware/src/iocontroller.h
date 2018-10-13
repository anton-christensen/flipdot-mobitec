#ifndef __IO_CONTROLLER__
#define __IO_CONTROLLER__

class IOController {
  public:
    IOController() {}
    virtual void digitalWrite(unsigned char pin, unsigned char state) = 0;
    virtual void pinMode(unsigned char pin, unsigned char mode) = 0;
};

#endif
