#ifndef __FLIP_CLOCK__
#define __FLIP_CLOCK__

#include "screenprogram.h"
#include "websocket.h"

#include <Arduino.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>

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
    NTPClient* NTP;
    WiFiUDP ntpUDP;

  public:
    FlipClock(FlipScreen* _sign) : ScreenProgram(_sign) {
      
    }

    void start() {
      sign->clear();
    }

    void stop() {
    }

    void loop(char* input) {
      static unsigned char initialized = false;
      if(!initialized && WiFi.status() == WL_CONNECTED) {
        NTP = new NTPClient(ntpUDP, "dk.pool.ntp.org", 3600*2, 60000);
        NTP->begin();
        initialized = true;
        srand(NTP->getEpochTime());
      } 
      else if(!initialized) return;


      if(!NTP->update()) {
        ws_send("NTP update failed");
      }

      // draw seconds indicator
      sign->fillRect(0,PANEL_WIDTH,PANEL_HEIGHT-1,PANEL_HEIGHT, BLACK);
      unsigned short secondsCounter = (PANEL_WIDTH/60.0)*NTP->getSeconds();
      // unsigned short secondsCounter = (PANEL_WIDTH/60.0)*(((NTP->getMilliseconds()-2000) % 60000)/1000.0);
      
      if(NTP->getMinutes() % 2) {
        sign->fillRect(0, secondsCounter, PANEL_HEIGHT-1, PANEL_HEIGHT, WHITE);
      }
      else {
        sign->fillRect(secondsCounter, PANEL_WIDTH, PANEL_HEIGHT-1, PANEL_HEIGHT, WHITE);
      }
      sign->flip();
      
      // draw time
      sign->fillRect(0,PANEL_WIDTH,0,PANEL_HEIGHT-1, BLACK);
      static char time[10];
      sprintf(time, "%02u%c%02u", NTP->getHours()%24, NTP->getSeconds()%2 ? ':' : ' ', NTP->getMinutes()%60);
      sign->write(time, -1, -1, WHITE);
      sign->flip(250);

    }
};

#endif