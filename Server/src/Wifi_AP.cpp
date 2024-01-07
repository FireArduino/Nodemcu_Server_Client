#include "Wifi_AP.h"


IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 9);
IPAddress subnet(255, 255, 255, 0);

// UTILS utils;

bool Wifi_AP::make_softAP(int wait_time)
{
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"Setting soft-AP configuration ... ",true);
    #endif
    bool isCon = WiFi.softAPConfig(local_IP, gateway, subnet);
    if (isCon)
    {
        #ifdef DEBUG_SAP2
            UTILS::Logger(__FUNCTION__,__LINE__,"Ready",true);
        #endif
    }
    else
    {
        #ifdef DEBUG_SAP2
            UTILS::Logger(__FUNCTION__,__LINE__,"Failed!",true);
        #endif
    }
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"Setting soft-AP ... ",true);
    #endif
    bool isConnected = WiFi.softAP(ssid, password);
    for (int i = 0; i < wait_time &&((isCon) && (isConnected)); i++)
    {
        if (isConnected != true)
        {
            #ifdef DEBUG_SAP2
                UTILS::Logger(__FUNCTION__,__LINE__,"Waiting for softap creation : " + String(i),true);
            #endif
            delay(1000);
        }
        else
        {
            #ifdef DEBUG_SAP2
                UTILS::Logger(__FUNCTION__,__LINE__,"Break...",true);
            #endif
            break;
        }
    }
    if (isConnected)
    {
        #ifdef DEBUG_SAP1
            UTILS::Logger(__FUNCTION__,__LINE__,"Ready",true);
        #endif
    }
    else
    {
        #ifdef DEBUG_SAP1
            UTILS::Logger(__FUNCTION__,__LINE__,"Failed!",true);
        #endif
    }
    return ((isCon) && (isConnected));
}

void Wifi_AP::setSSID(String ss){
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"Setting SSID " + ss,true);
    #endif
    if(ssid.length() > 0)
    {
        #ifdef DEBUG_SAP2
            UTILS::Logger(__FUNCTION__,__LINE__,"Successfully Set SSID " + ss + "From " + ssid,true);
        #endif
        ssid = ss;
    }
}

void Wifi_AP::setPassKey(String pass){
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"Setting password " + pass,true);
    #endif
    if(pass.length() > 0)
    {
        #ifdef DEBUG_SAP2
            UTILS::Logger(__FUNCTION__,__LINE__,"Successfully Set password " + pass + "From " + password,true);
        #endif
        password = pass;
    }
}

bool Wifi_AP::isSoftAP()
{
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"SoftAP is " + String(WiFi.enableAP(true)),true);
    #endif
    return WiFi.enableAP(true);
}

String Wifi_AP::getMac()
{
    String MAC = "";
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"Inside getMac",true);
    #endif
    if(isSoftAP() && isConnected)
    {
        MAC = WiFi.softAPmacAddress();
        #ifdef DEBUG_SAP2
            UTILS::Logger(__FUNCTION__,__LINE__,"MAC is " + MAC,true);
        #endif
    }
    return MAC;
}

String Wifi_AP::getIP()
{
    String IP = "";
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"Inside getIP",true);
    #endif
    if(isSoftAP() && isConnected)
    {
        IP = WiFi.softAPIP().toString();
        #ifdef DEBUG_SAP2
            UTILS::Logger(__FUNCTION__,__LINE__,"IP is " + IP,true);
        #endif
    }
    return IP;
}

String Wifi_AP::getGateWay()
{
    String GateIP = "";
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"Inside getGateWay",true);
    #endif
    if(isSoftAP() && isConnected)
    {
        GateIP = gateway.toString();
        #ifdef DEBUG_SAP2
            UTILS::Logger(__FUNCTION__,__LINE__,"GateIP is " + GateIP,true);
        #endif
    }
    return GateIP;
}

int Wifi_AP::getConnectionCount()
{
    int cCount = 0;
    #ifdef DEBUG_SAP1
        UTILS::Logger(__FUNCTION__,__LINE__,"Inside getConnectionCount",true);
    #endif
    if(isSoftAP() && isConnected)
    {
        cCount = WiFi.softAPgetStationNum();
        #ifdef DEBUG_SAP2
            UTILS::Logger(__FUNCTION__,__LINE__,"ConnectionCount is " + String(cCount),true);
        #endif
    }
    return cCount;
}