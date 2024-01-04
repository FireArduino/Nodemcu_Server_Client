#include "Wifi_AP.h"


IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 9);
IPAddress subnet(255, 255, 255, 0);
String wGate = gateway.toString();

UTILS utils;




void Wifi_AP::make_softAP(int wait_time)
{
    #ifdef DEBUG_SAP1
        utils.Logger(__LINE__,__FUNCTION__,"Setting soft-AP configuration ... ");
    #endif
    bool isCon = WiFi.softAPConfig(local_IP, gateway, subnet);
    if (isCon)
    {
        #ifdef DEBUG_SAP2
            utils.Logger(__LINE__,__FUNCTION__,"Ready");
        #endif
    }
    else
    {
        #ifdef DEBUG_SAP2
            utils.Logger(__LINE__,__FUNCTION__,"Failed!");
        #endif
    }
    #ifdef DEBUG_SAP1
        utils.Logger(__LINE__,__FUNCTION__,"Setting soft-AP ... ");
    #endif
    bool isConnected = WiFi.softAP(ssid, password);
    for (int i = 0; i < wait_time; i++)
    {
        if (isConnected != true)
        {
            #ifdef DEBUG_SAP2
                utils.Logger(__LINE__,__FUNCTION__,"Waiting for softap creation : " + String(i));
            #endif
            delay(1000);
        }
        else
        {
            #ifdef DEBUG_SAP2
                utils.Logger(__LINE__,__FUNCTION__,"Break...");
            #endif
            break;
        }
    }
    if (isConnected)
    {
        #ifdef DEBUG_SAP1
            utils.Logger(__LINE__,__FUNCTION__,"Ready");
        #endif
        wIP = WiFi.softAPIP().toString();
        wMac = WiFi.softAPmacAddress();
        #ifdef DEBUG_SAP1
            utils.Logger(__LINE__,__FUNCTION__,"\nSoftAPIP : "+ String(wIP));
            utils.Logger(__LINE__,__FUNCTION__,"\tSoftAPMAC : "+ String(wMac));
        #endif
    }
    else
    {
        #ifdef DEBUG_SAP1
            Serial.print("Failed!");
        #endif
    }
}



