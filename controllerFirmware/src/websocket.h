#ifndef __WEBSOCKETS__
#define __WEBSOCKETS__

#include <ArduinoWebsockets.h>
#include <WiFi.h>

const char* websockets_server_host = "serverip_or_name"; //Enter server adress
const uint16_t websockets_server_port = 8080; // Enter server port

using namespace websockets;

WebsocketsClient client;
void ws_send(String data) {
    // client.send(data);
} 
void ws_send(const char* data) {
    // client.send(data);
} 

bool ws_setup() {
    // try to connect to Websockets server
    
    // bool connected = client.connect("wss://log.antonchristensen.net/ws");
    // if(connected) {
    //     client.send("Flipdot");
    //     return true;
    // } else {
    //     return false;
    // }
}

// void ws_loop() {
//     // let the websockets client check for incoming messages
//     if(client.available()) {
//         client.poll();
//     }
// }

#endif