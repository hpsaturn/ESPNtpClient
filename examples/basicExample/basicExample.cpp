#include <Arduino.h>

#include "WifiConfig.h"
#include <ESPNtpClient.h>
#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#ifndef WIFI_CONFIG_H
#define YOUR_WIFI_SSID "YOUR_WIFI_SSID"
#define YOUR_WIFI_PASSWD "YOUR_WIFI_PASSWD"
#endif // !WIFI_CONFIG_H

#define SHOW_TIME_PERIOD 1000

const PROGMEM char* ntpServer = "es.pool.ntp.org";

boolean syncEventTriggered = false; // True if a time even has been triggered
NTPSyncEvent_t ntpEvent; // Last triggered event

void setup() {
    Serial.begin (115200);
    Serial.println ();
    WiFi.begin (YOUR_WIFI_SSID, YOUR_WIFI_PASSWD);
    NTP.setTimeZone (TZ_Europe_Madrid);
    NTP.begin (ntpServer);
}

void loop() {
    static int last = 0;

    if ((millis () - last) >= SHOW_TIME_PERIOD) {
         //Serial.println(millis() - last);
        last = millis ();
        Serial.println (NTP.getTimeDateStringUs ());
    }
}