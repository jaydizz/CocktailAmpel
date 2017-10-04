

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include "ESP8266TrueRandom.h"
#include <Ticker.h>
#include <ESPDMX.h>

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

const char* host = "Cocktailampel Update";
const char* update_path = "/firmware";
const char* update_username = "bar";
const char* update_password = "boernerboerner";
const char* ssid = "Verwaltung";
const char* password = "dmxtest123";


#define PIN_BUTTON D7
#define STATE_CHASE 0
#define STATE_RANDOM_STARTED 1
#define STATE_BUTTON_PRESSED 2

Ticker timer;
DMXESPSerial dmx;

uint8_t state = 0;
uint8_t dimmer_values[] = {0,0,0};
volatile bool ticked = false;


void timer_tick() {
    ticked = true;
}


void update_dmx() {
    switch(state) {

        case 0: {   //State Chase. Just a random Chase.

            //timer.attach(1,timer_tick);
            //uint8_t rand = ESP8266TrueRandom.random(1, 4);
            uint8_t rand = 1;
            Serial.println();
            Serial.print("Updating DMX. Lighting Lamp:");
            Serial.print(rand);
            Serial.println();
            for(int i = 1; i < 4; i++) {
                if(i == rand) {
                    dmx.write(rand, 255);
                } else {
                    dmx.write(i, 0);
                }
            }
            Serial.println("Mark 2");
            dmx.update();
        }

        case 1: {
            timer.attach(0.2,timer_tick);
            uint8_t rand = ESP8266TrueRandom.random(1, 4);
            for(int i = 1; i < 4; i++) {
                if(i == rand) {
                    dmx.write(rand, 255);
                } else {
                    dmx.write(i, 0);
                }
            }
        }

        case 2: {
            for(int j = 0; j < 5; j++) {

                uint8_t rand = ESP8266TrueRandom.random(1, 4);

                for(int i = 1; i < 4; i++) {
                    if(i == rand) {
                        dmx.write(rand, 255);
                    } else {
                        dmx.write(i, 0);
                    }
                }

                timer.attach(0.2+(j*0.1),timer_tick);
            }
            timer.attach(10, timer_tick);
        }

    }
    Serial.println("Mark 3");

}


void ISR_button_pressed() {
    Serial.println("Button pressed");
    if(state == 0) {
        state = 1;
    } else if(state == 1){
        state = 2;
    }
}



void setup() {
    Serial.begin(115200);
    Serial.println("Starting");

    WiFi.mode(WIFI_AP_STA);
    WiFi.begin(ssid, password);
    Serial.println("Connecting to wifi");
    while(WiFi.waitForConnectResult() != WL_CONNECTED){
        WiFi.begin(ssid, password);
        Serial.print(".");
    }
    MDNS.begin(host);

    httpUpdater.setup(&httpServer, update_path, update_username, update_password);
    httpServer.begin();

    MDNS.addService("http", "tcp", 80);
    Serial.printf("HTTPUpdateServer ready! Open http://%s.local%s in your browser and login with username '%s' and password '%s'\n", host, update_path, update_username, update_password);

    pinMode(D7, INPUT_PULLUP);
    timer.attach(0.5, timer_tick);

    attachInterrupt(PIN_BUTTON, ISR_button_pressed, FALLING);
    Serial.println();


    dmx.init(3);

}



// the loop function runs over and over again forever
void loop() {
    httpServer.handleClient();
    if(ticked){
        Serial.println("lol2");
        update_dmx();
        ticked = false;
    }
}