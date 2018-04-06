#ifndef __SCREEN_PROGRAM__
#define __SCREEN_PROGRAM__

class ScreenProgram {
  public:
    ScreenProgram(FlipScreen* _sign) { sign = _sign; }
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void loop(char* input) = 0;

  protected:
    FlipScreen* sign;
};

#endif
