#include "Wifi_AP.h"


IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 9);
IPAddress subnet(255, 255, 255, 0);
String wGate = gateway.toString();

UTILS utils;




bool Wifi_AP::make_softAP(int wait_time)
{
    #ifdef DEBUG_SAP1
        utils.Logger(__FUNCTION__,__LINE__,"Setting soft-AP configuration ... ",true);
    #endif
    bool isCon = WiFi.softAPConfig(local_IP, gateway, subnet);
    if (isCon)
    {
        #ifdef DEBUG_SAP2
            utils.Logger(__FUNCTION__,__LINE__,"Ready",true);
        #endif
    }
    else
    {
        #ifdef DEBUG_SAP2
            utils.Logger(__FUNCTION__,__LINE__,"Failed!",true);
        #endif
    }
    #ifdef DEBUG_SAP1
        utils.Logger(__FUNCTION__,__LINE__,"Setting soft-AP ... ",true);
    #endif
    bool isConnected = WiFi.softAP(ssid, password);
    for (int i = 0; i < wait_time &&((isCon) && (isConnected)); i++)
    {
        if (isConnected != true)
        {
            #ifdef DEBUG_SAP2
                utils.Logger(__FUNCTION__,__LINE__,"Waiting for softap creation : " + String(i),true);
            #endif
            delay(1000);
        }
        else
        {
            #ifdef DEBUG_SAP2
                utils.Logger(__FUNCTION__,__LINE__,"Break...",true);
            #endif
            break;
        }
    }
    if (isConnected)
    {
        #ifdef DEBUG_SAP1
            utils.Logger(__FUNCTION__,__LINE__,"Ready",true);
        #endif
        wIP = WiFi.softAPIP().toString();
        wMac = WiFi.softAPmacAddress();
        #ifdef DEBUG_SAP1
            utils.Logger(__FUNCTION__,__LINE__,String("SoftAPIP : "+ wIP),true);
            utils.Logger(__FUNCTION__,__LINE__,String("SoftAPMAC : "+ wMac),true);
        #endif
    }
    else
    {
        #ifdef DEBUG_SAP1
            utils.Logger(__FUNCTION__,__LINE__,"Failed!",true);
        #endif
    }
    return ((isCon) && (isConnected));
}



