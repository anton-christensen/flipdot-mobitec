#ifndef __FLIP_CLOCK__
#define __FLIP_CLOCK__

#include "screenprogram.h"
#include <Arduino.h>
#include <NTPtimeESP.h>
#include <WiFi.h>

class FlipClock : public ScreenProgram {
  private:
    /*
     * The structure contains following fields:
     * struct strDateTime
    {
      byte hour;
      byte minute;
      byte second;
      int year;
      byte month;
      byte day;
      byte dayofWeek;
      boolean valid;
    };
     */
    NTPtime* NTP;
    strDateTime dateTime;
    unsigned long syncTime = 0;

  public:
    FlipClock(FlipScreen* _sign) : ScreenProgram(_sign) {
      sync();
    }

    void sync() {
      if(WiFi.status() != WL_CONNECTED) return;
      NTP = new NTPtime("0.dk.pool.ntp.org");
      int retries = 10;
      do {
        dateTime = NTP->getNTPtime(1.0, 1);
      } while(dateTime.valid == false && retries--);
      if(dateTime.valid) {
        syncTime = millis();
        Serial.println("Synchronized clock");  
        NTP->printDateTime(dateTime);
        srand(dateTime.unixtime);
      }
    }

    void start() {
      if(syncTime == 0)
        sync();
      sign->clear();
    }
    void stop() {}

    void loop(char* input) {
      char time[10];
      sprintf(time, "%02u%c%02u", dateTime.hour, dateTime.second%2 ? ':' : ' ', dateTime.minute);
      sign->write(time);sign->flip();
      // sign->screenToUart();
      while(syncTime - millis() >= 1000) {
        syncTime+=1000;
        dateTime.unixtime++;
        NTP->updateTimestamp(&dateTime);
      }
    }
};

#endif