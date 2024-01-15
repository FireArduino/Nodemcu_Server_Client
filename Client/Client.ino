#include <Arduino.h>
#include "./src/WiFiManager.h"
void setup()
{
    Serial.begin(2400);
    setWifi_Hostname("WaterLevel_Sensor");
    enableLogs(false);
    while (!inti_wifi_manager("WaterLevel_Sensor"));
}

void loop()
{
}