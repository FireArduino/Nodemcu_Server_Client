#ifndef UTLRASONICSENSOR_H_
#define UTLRASONICSENSOR_H_
#include <Arduino.h>
class ULTSONIC
{
private:
    int _TRIG, _ECHO;

public:
    ULTSONIC(int TRIG, int ECHO);
    void init();
    int measurementsSender(bool cm = true);
};
#endif