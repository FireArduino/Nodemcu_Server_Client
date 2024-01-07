#include "Arduino.h"
#include "Server.h"




void setup()
{
    Serial.begin(2400);
    for (int i = 0; i < 20; i++)
    {
        Serial.flush();
    }
    Serversetup();
    
}

void loop()
{
    Serverloop();
}