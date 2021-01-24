#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>

#include "flipscreen.h"
#include "iocontroller.h"
#include "iocontroller_inbuilt.h"
// #include "iocontroller_mcp23017.h"
#include "screenprogrammanager.h"
#include "websocket.h"

#include "programs/flipmenu.h"
#include "programs/flipclock.h"
#include "programs/flipsilent.h"
#include "programs/fliptetris.h"
#include "programs/flipsnake.h"
#include "programs/flipperlin.h"
#include "programs/flipnote.h"
#include "programs/flipsquares.h"
#include "programs/flipsines.h"
// #include "programs/flipsettingbacklight.h"

#define WIFI_RETRY_COUNT 50
#define HOST_NAME "flipdot"
FlipScreen* sign;
ScreenProgramManager* screenManager;

char ssid[64]     = "AChristensen";
char password[64] = "IngenTestUdenHest";

bool OTA_ongoing = false;

WiFiUDP udp;

void startWiFiServices() {
  if(WiFi.status() == WL_CONNECTED) {
    udp.begin(12345);
    Serial.println("Started UDP service");
  }

  ws_setup();


  ArduinoOTA.onStart([]() {    
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    ws_send("OTA started: " + type);

    screenManager->peek()->stop();
    OTA_ongoing = true;
    sign->setFont(2);
    sign->clear();
    sign->write("Updating...");
    sign->flip();
    delay(1000);


  }).onEnd([]() {
    ws_send("Update success");

    sign->write("Update success");
    sign->clear();
    sign->flip();
    delay(5000);
    sign->clear();
    sign->setFont(1);
    OTA_ongoing = false;


  }).onProgress([](unsigned int progress, unsigned int total) {
    static char str[10];
    unsigned char percentage = (progress / (total / 100));
    sprintf(str, "%u%%", percentage);
    sign->clear();
    sign->fillRect(0, percentage*PANEL_WIDTH/100, 5, PANEL_HEIGHT-6, WHITE);

    sign->write(str, -1, -1, TOGGLE);
    sign->flip();

  }).onError([](ota_error_t error) {
    
    String error_msg = String("Error(") + error + "): ";
    sign->clear();
    if (error == OTA_AUTH_ERROR) error_msg += "Auth Failed";
    else if (error == OTA_BEGIN_ERROR) error_msg += "Begin Failed";
    else if (error == OTA_CONNECT_ERROR) error_msg += "Connect Failed";
    else if (error == OTA_RECEIVE_ERROR) error_msg += "Receive Failed";
    else if (error == OTA_END_ERROR) error_msg += "End Failed";
    
    ws_send(error_msg);
    sign->write(error_msg.c_str());
    sign->flip();
    sign->clear();
    delay(5000);
    sign->setFont(1);
    
    OTA_ongoing = false;
    screenManager->peek()->start();
  })
  .setHostname(HOST_NAME)
  .setTimeout(3000);

  ArduinoOTA.begin();

  mdns_hostname_set(HOST_NAME);
}
void stopWiFiServices() {
    udp.stop();
}

void setupWifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // connecting to WiFi 
  if(strlen(password) == 0)
    WiFi.begin(ssid);
  else
    WiFi.begin(ssid, password);

  //wait until ESP32 connect to WiFi
  int retries = WIFI_RETRY_COUNT;
  while (WiFi.status() != WL_CONNECTED && retries-- > 0) {
      delay(250);
      Serial.print(".");
  }
  if(WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected!");
    startWiFiServices();
  }
}

void printNetworks(int numSsid) {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
  numSsid = WiFi.scanNetworks();

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);

  // print the network number and name for each network found:
  for (int i = 0; i < numSsid; i++) {
    Serial.print(i);
    Serial.print(")");
    Serial.print((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?"  ":"* ");
    Serial.print(WiFi.SSID(i));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(i));
    Serial.println(" dBm");
  }
}

void setup() {
  Serial.begin(115200);
  if (!MDNS.begin(HOST_NAME))
    Serial.println("Error setting up MDNS responder!");
  MDNS.addService("ctrl", "udp", 12345);

  IOController* ioctrl = new IOController_inbuilt();
  sign = new FlipScreen(ioctrl);

  // retrieve the screenManager instance
  screenManager = ScreenProgramManager::getInstance();

  // Create the menu
  std::map<std::string, ScreenProgram*> menu;
  menu[std::string("Silent")]     = new FlipSilent(sign);
  menu[std::string("Clock")]      = new FlipClock(sign);
  menu[std::string("Tetris")]     = new FlipTetris(sign);
  menu[std::string("Snake")]      = new FlipSnake(sign);
  menu[std::string("Perlin")]     = new FlipPerlin(sign);
  menu[std::string("Note")]       = new FlipNote(sign);
  menu[std::string("Squares")]    = new FlipSquares(sign);
  menu[std::string("Sines")]      = new FlipSines(sign);
  // menu[std::string("Backlight")]  = new FlipSettingBacklight(sign);

  screenManager->push(new FlipMenu(sign, menu), false);
  // ((FlipMenu*)(screenManager->peek()))->setProgram("Perlin");
}

void loop() {
  if(OTA_ongoing == false) {
    char* input = NULL;
    { //  check wifi connection
      wl_status_t status = WiFi.status();
      if(status != WL_CONNECTED) {
        screenManager->peek()->stop();

        //wait until ESP32 connect to WiFi
        sign->clear(BLACK);
        sign->setFont(2);
        sign->write("Connecting...");
        sign->setFont(1);
        sign->flip();

        while(WiFi.status() != WL_CONNECTED)
          setupWifi();
        
        screenManager->peek()->start();
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

  ArduinoOTA.handle();
}