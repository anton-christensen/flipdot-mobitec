#ifndef __SCREEN_PROGRAM_MANAGER__
#define __SCREEN_PROGRAM_MANAGER__

#include "screenprogram.h"
#include <stack>

class ScreenProgramManager {
  private:
    static ScreenProgramManager* _inst;
    
    ScreenProgramManager() {}
    std::stack<ScreenProgram*> programStack;
  
  public:
    static ScreenProgramManager* getInstance() {
      if(!_inst) _inst = new ScreenProgramManager();
      return _inst;
    }

    void push(ScreenProgram* program) {
      if(!programStack.empty())
        programStack.top()->stop();
      programStack.push(program);
      programStack.top()->start();
    }

    void pop() {
      if(programStack.empty()) return;
      programStack.top()->stop();
      delete programStack.top();
      programStack.pop();
      programStack.top()->start();
    }

    void loop() {
      programStack.top()->loop();
    }
};

ScreenProgramManager* ScreenProgramManager::_inst = 0;

#endif