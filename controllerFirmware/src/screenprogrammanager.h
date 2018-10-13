#ifndef __SCREEN_PROGRAM_MANAGER__
#define __SCREEN_PROGRAM_MANAGER__

#include "programs/screenprogram.h"
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
      // delete programStack.top();
      programStack.pop();
      programStack.top()->start();
    }

    void pause(bool pause=false) {
      if(pause)
        programStack.top()->stop();
      else
        programStack.top()->start();
    }

    ScreenProgram* peek() {
      if(programStack.empty()) return NULL;
      return programStack.top();
    }

    void loop(char* input) {
      if(input != NULL && strcmp("q", input) == 0)
        this->pop();
      else if(input != NULL && strcmp("r", input) == 0)
        programStack.top()->redraw();
      else
        programStack.top()->loop(input);
    }
};

ScreenProgramManager* ScreenProgramManager::_inst = 0;

#endif