

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
volatile uint8_t runcount = 0;
volatile uint8_t update = 0;

void timer_tick() {
    ticked = true;
    if(state == STATE_RANDOM_STARTED) {
        runcount++;
    }

}


void update_dimmer() {
    uint8_t rand = random(0,3);
    Serial.print("Lighting Lamp");
    Serial.print(rand);
    Serial.println("");
    for(int i = 0; i < 3; i ++ ) {
        if(i == rand) {
            dimmer_values[i] = 255;

        } else {
            dimmer_values[i] = 0;
        }
    }
}


void ISR_button_pressed() {
    Serial.println("Button pressed");
    if(state == STATE_CHASE) {
        state = STATE_RANDOM_STARTED;
        update = 1;
    }
    if(state == STATE_RANDOM_STARTED){
        state = STATE_BUTTON_PRESSED;
        update = 1;
    }
    return;
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
    timer.attach(2, timer_tick);

    attachInterrupt(PIN_BUTTON, ISR_button_pressed, FALLING);
    Serial.println();


    dmx.init(3);

}



// the loop function runs over and over again forever
void loop() {
    httpServer.handleClient();
    if(state == STATE_CHASE && update && ticked) {
        timer.attach(2, timer_tick);
        update = 0;
    }

    if(state == STATE_RANDOM_STARTED && update) {
        timer.attach(0.2, timer_tick);
        update = 0;

    }
    if(state == STATE_BUTTON_PRESSED && update && ticked) {
        timer.attach(0.2+runcount/10, timer_tick);
        runcount++;
        if(runcount == 6) {
            timer.attach(5, timer_tick);
            update = 1;
        }
    }


    if(ticked){
        Serial.println(state);
        update_dimmer();
        ticked = false;
    }


    for(int i = 1; i < 4; i++) {
        dmx.write(i, dimmer_values[i-1]);
    }
    dmx.update();
}