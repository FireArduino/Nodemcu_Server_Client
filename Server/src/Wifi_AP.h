#ifndef WIFI_AP_H_
#define WIFI_AP_H_

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include "../global_defines.h"
#include "utils.h"





class Wifi_AP
{
    private:
        String ssid = "FireESP8266";
        String password = "abc12345";
        bool isConnected;


    public:
        bool make_softAP(int wait_time);
        void setSSID(String ss);
        void setPassKey(String pass);
        bool isSoftAP();
        String getMac();
        String getIP();
        String getGateWay();
        int getConnectinCount();
};







#endif