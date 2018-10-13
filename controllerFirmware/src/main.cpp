#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include <BluetoothSerial.h>

#include "flipscreen.h"
#include "iocontroller.h"
#include "iocontroller_mcp23017.h"
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

char ssid[64]     = "FBI_Security Van #48";
char password[64] = "Minecraft";
// char ssid[64]     = "hal9k";
// char password[64] = "";

// const char* ssid     = "FCM";
// const char* password = "jsok815ogisk2200";

// // create a server and listen on port 8088
// // WiFiServer server(80);
// // ESP32WebServer server(80);

WiFiUDP udp;
BluetoothSerial* bt;

void startWiFiServices() {
  if(WiFi.status() == WL_CONNECTED) {

    udp.begin(12345);
  }
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
      Serial.println(WiFi.status());
      delay(500);
      Serial.print(".");
  }
  if(WiFi.status() == WL_CONNECTED)
    startWiFiServices();
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

// when wifi doesn't work
void configureWiFi() {
  // while not connected to wifi
  while(WiFi.status() != WL_CONNECTED) {
    sign->clear();
    sign->write("Set new WIFI");
    sign->flip();
    
    //    
    bt->begin("FlipDotConfig");
    while(!bt->hasClient());
    
    sign->clear();
    sign->write("Send new SSID");
    sign->flip();
    
    int numSsid = WiFi.scanNetworks();
    printNetworks(numSsid);
    
    bool ssidSet = false;
    bool passwordSet = false;
    static char packetBuffer[256];
    while(!ssidSet) {
      while(!bt->available());
      int len = bt->readBytesUntil('\n', packetBuffer, 255);
      packetBuffer[len]=0;
      Serial.println();
      Serial.print("Got ");
      Serial.println(packetBuffer);

      // print the network number and name for each network found:
      for (int i = 0; i < numSsid; i++) {
        if(String(WiFi.SSID(i)) == String(packetBuffer)) {
          WiFi.SSID(i).toCharArray(ssid, 64);

          ssidSet = true;
          if(WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
            passwordSet = true;
            password[0] = 0;
          }
          break;
        }
        else {
          Serial.print("'");
          Serial.print(WiFi.SSID(i));
          Serial.print("'");
          Serial.print(" != ");
          Serial.print("'");
          Serial.print(packetBuffer);
          Serial.print("'");
          Serial.println("");
        }
      }
    } 
    if(ssidSet && !passwordSet) {
      while(!bt->available());
      int len = bt->readBytesUntil('\n', packetBuffer, 255);
      packetBuffer[len]=0;
      String(packetBuffer).toCharArray(password, 64);

    }

    if(ssidSet && passwordSet)
      setupWifi();
  }
  sign->clear();
}

void scrollingBuffer() {
  sign->clear(BLACK);
  sign->flip();

  int bufferWidth = PANEL_WIDTH*2+25;
  unsigned char scrollingBuffer[PANEL_HEIGHT*bufferWidth];
  for (int x = 0; x < bufferWidth; ++x)
    for (int y = 0; y < PANEL_HEIGHT; ++y)
      scrollingBuffer[y+x*PANEL_HEIGHT] = BLACK;

sign->write("I'VE GOT GREAT",105,-1,false,(unsigned char*)&(scrollingBuffer[0]));

scrollingBuffer[0 + 7*PANEL_HEIGHT] = WHITE;
scrollingBuffer[0 + 8*PANEL_HEIGHT] = WHITE;
scrollingBuffer[0 + 9*PANEL_HEIGHT] = WHITE;

scrollingBuffer[1 + 5*PANEL_HEIGHT] = WHITE;
scrollingBuffer[1 + 6*PANEL_HEIGHT] = WHITE;
scrollingBuffer[1 + 7*PANEL_HEIGHT] = WHITE;
scrollingBuffer[1 + 8*PANEL_HEIGHT] = WHITE;
scrollingBuffer[1 + 9*PANEL_HEIGHT] = WHITE;
scrollingBuffer[1 + 10*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[1 + 11*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[2 + 4*PANEL_HEIGHT] = WHITE;
scrollingBuffer[2 + 5*PANEL_HEIGHT] = WHITE;
scrollingBuffer[2 + 6*PANEL_HEIGHT] = WHITE;
scrollingBuffer[2 + 7*PANEL_HEIGHT] = WHITE;
scrollingBuffer[2 + 8*PANEL_HEIGHT] = WHITE;
scrollingBuffer[2 + 9*PANEL_HEIGHT] = WHITE;
scrollingBuffer[2 + 10*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[2 + 11*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[2 + 12*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[3 + 3*PANEL_HEIGHT] = WHITE;
scrollingBuffer[3 + 4*PANEL_HEIGHT] = WHITE;
scrollingBuffer[3 + 5*PANEL_HEIGHT] = WHITE;
scrollingBuffer[3 + 7*PANEL_HEIGHT] = WHITE;
scrollingBuffer[3 + 8*PANEL_HEIGHT] = WHITE;
scrollingBuffer[3 + 9*PANEL_HEIGHT] = WHITE;
scrollingBuffer[3 + 12*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[4 + 1*PANEL_HEIGHT] = WHITE;
scrollingBuffer[4 + 2*PANEL_HEIGHT] = WHITE;
scrollingBuffer[4 + 3*PANEL_HEIGHT] = WHITE;
scrollingBuffer[4 + 4*PANEL_HEIGHT] = WHITE;
scrollingBuffer[4 + 11*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[4 + 12*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[5 + 4*PANEL_HEIGHT] = WHITE;
scrollingBuffer[5 + 5*PANEL_HEIGHT] = WHITE;
scrollingBuffer[5 + 9*PANEL_HEIGHT] = WHITE;
scrollingBuffer[5 + 10*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[5 + 11*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[5 + 12*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[5 + 13*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[6 + 5*PANEL_HEIGHT] = WHITE;
scrollingBuffer[6 + 6*PANEL_HEIGHT] = WHITE;
scrollingBuffer[6 + 7*PANEL_HEIGHT] = WHITE;
scrollingBuffer[6 + 8*PANEL_HEIGHT] = WHITE;
scrollingBuffer[6 + 9*PANEL_HEIGHT] = WHITE;
scrollingBuffer[6 + 10*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[6 + 11*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[6 + 12*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[6 + 13*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[6 + 14*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[6 + 15*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[6 + 16*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[7 + 5*PANEL_HEIGHT] = WHITE;
scrollingBuffer[7 + 10*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[7 + 11*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[7 + 12*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[7 + 13*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[7 + 14*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[7 + 17*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[8 + 5*PANEL_HEIGHT] = WHITE;
scrollingBuffer[8 + 9*PANEL_HEIGHT] = WHITE;
scrollingBuffer[8 + 10*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[8 + 11*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[8 + 12*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[8 + 13*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[8 + 14*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[8 + 16*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[8 + 17*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[8 + 18*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[8 + 19*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[9 + 4*PANEL_HEIGHT] = WHITE;
scrollingBuffer[9 + 8*PANEL_HEIGHT] = WHITE;
scrollingBuffer[9 + 9*PANEL_HEIGHT] = WHITE;
scrollingBuffer[9 + 10*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 11*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 12*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 13*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 16*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 17*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 18*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 19*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 20*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[9 + 21*PANEL_HEIGHT]  = WHITE;

scrollingBuffer[10 + 4*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[10 + 9*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[10 + 10*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 11*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 12*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 13*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 15*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 16*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 17*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 18*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 19*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 20*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 21*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 22*PANEL_HEIGHT] = WHITE;
scrollingBuffer[10 + 23*PANEL_HEIGHT] = WHITE;

scrollingBuffer[11 + 5*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[11 + 10*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 11*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 12*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 15*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 16*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 17*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 18*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 19*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 20*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 21*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 22*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 23*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 24*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 25*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 26*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 27*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 28*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 29*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 30*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 31*PANEL_HEIGHT] = WHITE;
scrollingBuffer[11 + 32*PANEL_HEIGHT] = WHITE;

scrollingBuffer[12 + 5*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[12 + 6*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[12 + 11*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 12*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 14*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 15*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 16*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 17*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 25*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 26*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 27*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 28*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 29*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 30*PANEL_HEIGHT] = WHITE;
scrollingBuffer[12 + 31*PANEL_HEIGHT] = WHITE;

scrollingBuffer[13 + 6*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[13 + 12*PANEL_HEIGHT] = WHITE;
scrollingBuffer[13 + 13*PANEL_HEIGHT] = WHITE;
scrollingBuffer[13 + 14*PANEL_HEIGHT] = WHITE;
scrollingBuffer[13 + 15*PANEL_HEIGHT] = WHITE;
scrollingBuffer[13 + 16*PANEL_HEIGHT] = WHITE;
scrollingBuffer[13 + 24*PANEL_HEIGHT] = WHITE;

scrollingBuffer[14 + 7*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[14 + 8*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[14 + 22*PANEL_HEIGHT] = WHITE;
scrollingBuffer[14 + 23*PANEL_HEIGHT] = WHITE;

scrollingBuffer[15 + 8*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[15 + 9*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[15 + 20*PANEL_HEIGHT] = WHITE;
scrollingBuffer[15 + 21*PANEL_HEIGHT] = WHITE;

scrollingBuffer[16 + 9*PANEL_HEIGHT]  = WHITE;
scrollingBuffer[16 + 10*PANEL_HEIGHT] = WHITE;
scrollingBuffer[16 + 11*PANEL_HEIGHT] = WHITE;
scrollingBuffer[16 + 12*PANEL_HEIGHT] = WHITE;
scrollingBuffer[16 + 18*PANEL_HEIGHT] = WHITE;
scrollingBuffer[16 + 19*PANEL_HEIGHT] = WHITE;

scrollingBuffer[17 + 13*PANEL_HEIGHT] = WHITE;
scrollingBuffer[17 + 14*PANEL_HEIGHT] = WHITE;
scrollingBuffer[17 + 15*PANEL_HEIGHT] = WHITE;
scrollingBuffer[17 + 16*PANEL_HEIGHT] = WHITE;
scrollingBuffer[17 + 17*PANEL_HEIGHT] = WHITE;

scrollingBuffer[18 + 14*PANEL_HEIGHT] = WHITE;
scrollingBuffer[18 + 17*PANEL_HEIGHT] = WHITE;

scrollingBuffer[19 + 13*PANEL_HEIGHT] = WHITE;
scrollingBuffer[19 + 16*PANEL_HEIGHT] = WHITE;



  int offset = 0;
  while(1) {
    for (int x = 0; x < PANEL_WIDTH; ++x)
    {
      for(int y = 0; y < PANEL_HEIGHT; y++) {
        sign->putPixel(x,y,scrollingBuffer[y+((x+offset)%bufferWidth)*PANEL_HEIGHT]);
      }
    }
    offset++;
    sign->flip();
    // delay(50);
  }
}

void setup() {
  Serial.println("STAGE 0");
  // bt = new BluetoothSerial();
  Serial.begin(115200);
  if (!MDNS.begin("flipdot"))
    Serial.println("Error setting up MDNS responder!");
  Serial.println("STAGE 1");
  MDNS.addService("ctrl", "udp", 12345);
  Serial.println("STAGE 2");
  // instantiate the sign api
  IOController* ioctrl = new IOController_MCP23017();
  sign = new FlipScreen(ioctrl);
  Serial.println("STAGE 3");
  // sign->clear(WHITE);
  // sign->flip();
  sign->clear(BLACK);
  sign->flip();
  
  Serial.println("STAGE 4");


  // retrieve the screenManager instance
  screenManager = ScreenProgramManager::getInstance();

  // Create the menu
  std::map<std::string, ScreenProgram*> menu;
  menu[std::string("Silent")]     = new FlipSilent(sign);
  menu[std::string("Clock")]      = new FlipClock(sign);
  menu[std::string("Tetris")]     = new FlipTetris(sign);
  menu[std::string("Snake")]      = new FlipSnake(sign);
  menu[std::string("Backlight")]  = new FlipSettingBacklight(sign);

  screenManager->push(new FlipMenu(sign, menu));
  ((FlipMenu*)(screenManager->peek()))->setProgram("Clock");
  Serial.println("STAGE 5");
}

void loop() {
  char* input = NULL;
  {
    wl_status_t status = WiFi.status();
    if(status != WL_CONNECTED) {
      //wait until ESP32 connect to WiFi
      sign->clear(BLACK);
      sign->setFont(2);
      sign->write("Connecting...");
      sign->setFont(1);
      sign->flip();

      setupWifi();

      // if still not connected
      if(status != WL_CONNECTED) {
        configureWiFi();
      }

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