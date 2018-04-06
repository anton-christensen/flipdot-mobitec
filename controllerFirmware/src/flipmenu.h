#ifndef __FLIP_MENU__
#define __FLIP_MENU__

#include "screenprogram.h"
#include <map>

class FlipMenu : public ScreenProgram {
  private:
    std::map<std::string, ScreenProgram*>::iterator current;
    std::map<std::string, ScreenProgram*> menuItems;

  public:
    FlipMenu(FlipScreen* _sign, std::map<std::string, ScreenProgram*> _menuItems) : ScreenProgram(_sign) {
      menuItems = _menuItems;
      current = menuItems.begin();
    }

    void start() {
      sign->write(current->first.c_str());
    }

    void stop() {}

    void loop() {}
};

#endif