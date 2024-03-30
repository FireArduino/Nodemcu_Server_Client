
#include "WiFiManager.h"

WiFiManager wm;

bool inti_wifi_manager(char const *ssid, char const *pass)
{
    return wm.autoConnect(ssid, pass); // password protected ap
}

bool setWifi_Hostname(String hostname)
{
    return wm.setHostname(hostname);
}

void enableLogs(boolean debug)
{
    wm.setDebugOutput(debug);
}

void setPortelTimeout(int t)
{
    wm.setConfigPortalTimeout(t);
}