#include "utils.h"

void UTILS::Logger(String function_name, int lineNo, String msg, bool new_line, bool new_tab)
{
    if (new_tab)
    {
        msg.replace(",", "\t");
    }

    String print_msg = String("Function : " + function_name + " L : " + String(lineNo) + "\n MSG : " + msg);
#ifdef DEBUG
    if (new_line)
    {
        Serial.println(print_msg);
    }
    else
    {
        Serial.print(print_msg);
    }
#endif
}

void UTILS::splitstr(String str, const char *dl, String *myd)
{
    char myarr[400];
    char *p;

    str.toCharArray(myarr, sizeof(myarr));
    int cnt = 0;
    p = strtok(myarr, dl);

    while (p != NULL)
    {
        myd[cnt] = String(p);
        myd[cnt].trim();
        p = strtok(NULL, dl);
        cnt++;
    }
}

void UTILS::Parser(String inStr)
{
    if (!(inStr.length() > 0))
    {
        Serial.println("String is empty");
        return;
    }
    String strp[5];
    // Serial.println("inStr : " + inStr);
    splitstr(inStr, "@", strp);
    // Serial.println("Client IP : " + strp[4]);
    // Serial.println("Client Add : " + strp[0]);
    // Serial.println("Client : " + strp[1]);
    // Serial.println("IP From Client : " + strp[2]);
    if (strp[1] == "WaterLevel_Sensor")
    {
        int Distance = strp[3].toInt();
        Serial.println("Water Level : " + String(Distance));
        if (WL_THRASOLD < Distance)
        {
            digitalWrite(2, LOW);
            Serial.println("Turn Water PUMP ON");
        }
        else if (WL_THRASOLD > Distance)
        {
            digitalWrite(2, HIGH);
            Serial.println("Turn Water Pump OFF!");
        }
        else
        {
            Serial.println("All is Well");
        }
    }
}