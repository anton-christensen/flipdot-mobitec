#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include "flipscreen.h"
#include "flipmenu.h"
#include "flipsilent.h"
#include "flipclock.h"
#include "screenprogrammanager.h"

FlipScreen* sign;
ScreenProgramManager* screenManager;

const char* ssid     = "hal9k";
// const char* ssid     = "FCM";
// const char* password = "jsok815ogisk2200";

// /* create a server and listen on port 8088 */
// // WiFiServer server(80);
// // ESP32WebServer server(80);


WiFiUDP udp;

void setupWifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* connecting to WiFi */
  // WiFi.begin(ssid, password);
  WiFi.begin(ssid);

  /*wait until ESP32 connect to WiFi*/
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // if (!MDNS.begin("flipdot")) {
  //     Serial.println("Error setting up MDNS responder!");
  // }
  // MDNS.addService("ctrl", "udp", 1234);

  // udp.begin(1234);
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
  // std::map<std::string, ScreenProgram*> menu;
  // menu[std::string("Item A")] = new FlipSilent(sign);
  // menu[std::string("Item B")] = new FlipClock(sign);
  // menu[std::string("Item C")] = new FlipClock(sign);
  // screenManager->push(new FlipMenu(sign, menu));
  screenManager->push(new FlipClock(sign));
  // flipClock = new FlipClock(sign);
  sign->write("READY");
  sign->clear(BLACK);
}

void loop() {
  screenManager->loop();

  // static char packetBuffer[256];
  // int packetSize = udp.parsePacket();
  // if (packetSize) {
  //   int len = udp.read(packetBuffer, 255);
  //   if (len > 0) {
  //     packetBuffer[len] = '\0';
  //   }
  // }
  // screenManager->loop(packetBuffer);
  // packetBuffer[0] = '\0';
  // Serial.println("WHITE");
  // sign->clear(WHITE);
  // delay(1000);
  // Serial.println("BLACK");
  // sign->clear(BLACK);
  // delay(1000);
}


// void loop() {
//   MDNS.update();
// }