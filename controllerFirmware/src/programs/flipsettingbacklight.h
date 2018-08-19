#ifndef __FLIP_BACKLIGHT_SETTING__
#define __FLIP_BACKLIGHT_SETTING__

#include "screenprogram.h"
#include "screenprogrammanager.h"

class FlipSettingBacklight : public ScreenProgram {
  private:
  public:
    FlipSettingBacklight(FlipScreen* _sign) : ScreenProgram(_sign) {}
    void start() {}
    void stop() {}
    void loop(char* input) {
      sign->setBacklight(!sign->getBacklight());
      ScreenProgramManager::getInstance()->pop();
    }
};

#endif