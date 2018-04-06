#ifndef __FLIP_SILENT__
#define __FLIP_SILENT__

#include "screenprogram.h"

class FlipSilent : public ScreenProgram {
  public:
    FlipSilent(FlipScreen* _sign) : ScreenProgram(_sign) {}

    void start() {
      sign->clear();
    }

    void stop() {}

    void loop() {}
};

#endif