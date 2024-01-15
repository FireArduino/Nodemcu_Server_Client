#ifndef WIFI_MANAGER_H_
#define WIFI_MANAGER_H_

#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

bool inti_wifi_manager(char const *ssid, char const *pass = NULL);
bool setWifi_Hostname(String hostname);
void enableLogs(boolean debug = true);

#endif