#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include <BluetoothSerial.h>

#include "flipscreen.h"
#include "screenprogrammanager.h"

#include "programs/flipmenu.h"
#include "programs/flipclock.h"
#include "programs/flipsilent.h"
#include "programs/fliptetris.h"
#include "programs/flipsnake.h"
#include "programs/flipsettingbacklight.h"

#define WIFI_RETRY_COUNT 10

FlipScreen* sign;
ScreenProgramManager* screenManager;

char* ssid     = "hal9k";
char* password = "";

// const char* ssid     = "FCM";
// const char* password = "jsok815ogisk2200";

// /* create a server and listen on port 8088 */
// // WiFiServer server(80);
// // ESP32WebServer server(80);

WiFiUDP udp;
BluetoothSerial bt;

void startWiFiServices() {
  if(WiFi.status() == WL_CONNECTED) {
    if (!MDNS.begin("flipdot")) {
        Serial.println("Error setting up MDNS responder!");
    }
    MDNS.addService("ctrl", "udp", 12345);

    udp.begin(12345);
  }
}
void stopWiFiServices() {
    // udp.stop();
}

// when wifi doesn't work
void configureWiFi() {

}

void setupWifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* connecting to WiFi */
  if(strlen(password) == 0)
    WiFi.begin(ssid);
  else
    WiFi.begin(ssid, password);

  /*wait until ESP32 connect to WiFi*/
  int retries = WIFI_RETRY_COUNT;
  while (WiFi.status() != WL_CONNECTED && retries-- > 0) {
      Serial.println(WiFi.status());
      delay(500);
      Serial.print(".");
  }
  
  startWiFiServices();
}

void setup() {
  Serial.begin(115200);
  setupWifi();

  // instantiate the sign api
  sign = new FlipScreen();
  sign->clear(BLACK);

  // retrieve the screenManager instance
  screenManager = ScreenProgramManager::getInstance();

  // Create the menu
  std::map<std::string, ScreenProgram*> menu;
  menu[std::string("Silent")]     = new FlipSilent(sign);
  menu[std::string("Clock")]      = new FlipClock(sign);
  menu[std::string("Tetris")]     = new FlipTetris(sign);
  menu[std::string("Snake")]      = new FlipSnake(sign);
  menu[std::string("Backlight")]  = new FlipSettingBacklight(sign);


  sign->write("READY");sign->flip();
  sign->clear(BLACK);
  screenManager->push(new FlipMenu(sign, menu));
  ((FlipMenu*)(screenManager->peek()))->setProgram("Clock");
}

void loop() {
  char* input = NULL;
  {
    wl_status_t status = WiFi.status();
    if(status != WL_CONNECTED && 
       status != WL_IDLE_STATUS) {

      /*wait until ESP32 connect to WiFi*/
      sign->clear(BLACK);
      sign->write("Connecting...");
      sign->flip();

      int retries = WIFI_RETRY_COUNT;
      while ((status = WiFi.status()) != WL_CONNECTED && retries-- > 0) {
          Serial.println(status);
          delay(500);
          Serial.print(".");
      }

      // if still not connected
      if(status != WL_CONNECTED && 
         status != WL_IDLE_STATUS) {
        configureWiFi();
      }

      stopWiFiServices();
      configureWiFi();      
    }
  }

  static char packetBuffer[256];
  int packetSize = udp.parsePacket();
  if (packetSize) {
    int len = udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = '\0';
      Serial.println(packetBuffer);
      input = packetBuffer;
    }
  }

  screenManager->loop(input);
}
