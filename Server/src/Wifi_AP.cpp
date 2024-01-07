#include "Wifi_AP.h"


IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 9);
IPAddress subnet(255, 255, 255, 0);

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
    }
    else
    {
        #ifdef DEBUG_SAP1
            utils.Logger(__FUNCTION__,__LINE__,"Failed!",true);
        #endif
    }
    return ((isCon) && (isConnected));
}

void Wifi_AP::setSSID(String ss){
    if(ssid.length() > 0)
    {
        ssid = ss;
    }
}

void Wifi_AP::setPassKey(String pass){
    if(pass.length() > 0)
    {
        password = pass;
    }
}

bool Wifi_AP::isSoftAP()
{
    return WiFi.enableAP(true);
}

String Wifi_AP::getMac()
{
    String MAC = "";
    if(isSoftAP() && isConnected)
    {
        MAC = WiFi.softAPmacAddress();
    }
    return MAC;
}

String Wifi_AP::getIP()
{
    String IP = "";
    if(isSoftAP() && isConnected)
    {
        IP = WiFi.softAPIP().toString();
    }
    return IP;
}

String Wifi_AP::getGateWay()
{
    String GateIP = "";
    if(isSoftAP() && isConnected)
    {
        GateIP = gateway.toString();
    }
    return GateIP;
}

int Wifi_AP::getConnectinCount()
{
    int cCount = 0;
    if(isSoftAP() && isConnected)
    {
        cCount = WiFi.softAPgetStationNum();
    }
    return cCount;
}