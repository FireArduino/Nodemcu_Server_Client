#include "Wifi_AP.h"


IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 9);
IPAddress subnet(255, 255, 255, 0);

// wIP = WiFi.softAPIP().toString();
// wMac = WiFi.softAPmacAddress();
String wGate = gateway.toString();

void Wifi_AP::make_softAP(int wait_time)
{
    #ifdef DEBUG_SAP1
        Serial.print("Setting soft-AP configuration ... ");
    #endif
    bool isCon = WiFi.softAPConfig(local_IP, gateway, subnet);
    if (isCon)
    {
        #ifdef DEBUG_SAP2
            Serial.println("Ready");
        #endif
    }
    else
    {
        #ifdef DEBUG_SAP2
            Serial.println("Failed!");
        #endif
    }
    #ifdef DEBUG_SAP1
        Serial.print("Setting soft-AP ... ");
    #endif
    bool isConnected = WiFi.softAP(ssid, password);
    for (int i = 0; i < wait_time; i++)
    {
        if (isConnected != true)
        {
            #ifdef DEBUG_SAP2
                Serial.print("Waiting for softap creation : " + String(i));
            #endif
            delay(1000);
        }
        else
        {
            #ifdef DEBUG_SAP2
                Serial.pritnln("Break...");
            #endif
            break;
        }
    }
    if (isConnected)
    {
        #ifdef DEBUG_SAP1
            Serial.print("Ready");
        #endif
        wIP = WiFi.softAPIP().toString();
        wMac = WiFi.softAPmacAddress();
        #ifdef DEBUG_SAP1
            Serial.pritn("\nSoftAPIP : "+ String(wIP));
            Serial.pritn("\tSoftAPMAC : "+ String(wMac));
        #endif
    }
    else
    {
        #ifdef DEBUG_SAP1
            Serial.print("Failed!");
        #endif
    }
}



