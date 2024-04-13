

#include "ultraSocnicSensor.h"

ULTSONIC::ULTSONIC(int TRIG, int ECHO)
{
    _TRIG = TRIG;
    _ECHO = ECHO;
}

void ULTSONIC::init()
{
    pinMode(_TRIG, OUTPUT); // Initializing Trigger Output and Echo Input
    pinMode(_ECHO, INPUT_PULLUP);
}

int ULTSONIC::measurementsSender(bool cm)
{
    digitalWrite(_TRIG, LOW); // Set the trigger pin to low for 2uS
    delayMicroseconds(2);
    digitalWrite(_TRIG, HIGH); // Send a 10uS high to trigger ranging
    delayMicroseconds(20);
    digitalWrite(_TRIG, LOW);                   // Send pin low again
    int distance = pulseIn(_ECHO, HIGH, 26000); // Read in times pulse
    distance = distance / 58;                   // Convert the pulse duration to distance
    if (cm)
    {
        return distance;
    }
    return distance * 0.3937; // Convert from cm to inches
}