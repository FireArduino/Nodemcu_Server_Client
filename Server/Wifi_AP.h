#ifndef WIFI_AP_H_
#define WIFI_AP_H_

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include "global_defines.h"
#include "utils.h"





class Wifi_AP
{
    private:
        const char *ssid = "FireESP8266";
        const char *password = "abc12345";
        String wIP = WiFi.softAPIP().toString();
        String wMac = WiFi.softAPmacAddress();
        int cNum = WiFi.softAPgetStationNum();
        bool isConnected;


    public:
        bool make_softAP(int wait_time);
};







#endif