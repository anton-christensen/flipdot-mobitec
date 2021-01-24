#ifndef __FLIP_MENU__
#define __FLIP_MENU__

#include "screenprogram.h"
#include "screenprogrammanager.h"
#include <map>
#include <Arduino.h>

class FlipMenu : public ScreenProgram {
  private:
    std::map<std::string, ScreenProgram*>::iterator current;
    std::map<std::string, ScreenProgram*> menuItems;
    int menuIndex;

  public:
    FlipMenu(FlipScreen* _sign, std::map<std::string, ScreenProgram*> _menuItems) : ScreenProgram(_sign) {
      menuItems = _menuItems;
      menuIndex = 0;
      current = menuItems.begin();
    }

    void update() {
      sign->clear();
      int barHeight = PANEL_HEIGHT/menuItems.size();
      int barStart = barHeight*menuIndex;
      sign->fillRect(0,2, 0,PANEL_HEIGHT-1, WHITE);
      sign->fillRect(2, 4, barStart, barStart+barHeight, WHITE);
      sign->setFont(2);

      if(current != menuItems.begin())
        sign->write(prev(current)->first.c_str(), 10, 0);
      sign->write(current->first.c_str(), 10);
      if(next(current) != menuItems.end())
        sign->write(next(current)->first.c_str(), 10, 14);
      
      sign->setFont(1);
      sign->flip();
    }

    void start() {
      update();
    }

    void stop() {
      sign->clear();
    }

    void loop(char* input) {
      if(input != NULL) {
        if(strcmp("up", input) == 0 && menuIndex != 0) {
          current--; menuIndex--;
          update();
        }
        if(strcmp("down", input) == 0 && menuIndex != menuItems.size()-1) {
          current++; menuIndex++;
          update();
        }
        if(strcmp("\n", input) == 0) {
          ScreenProgramManager::getInstance()->push(current->second);
        }
      }
    }

    void setProgram(const char* name) {
      ScreenProgramManager::getInstance()->push(menuItems[name]);
    }
};

#endif