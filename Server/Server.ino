#include "Wifi_AP.h"


Wifi_AP wap;

void setup()
{
    Serial.begin(2400);
    wap.make_softAP(5);
}

void loop()
{
    
}