#include "utils.h"

Sensor s1, s2, s3, s4,tmp;

void UTILS::Logger(String function_name, int lineNo, String msg, bool new_line, bool new_tab)
{
    if(new_tab)
    {
        msg.replace(",","\t");
    }
    
    String print_msg = String("Function : " + function_name + " L : " + String(lineNo) + "\n MSG : " + msg);
    #ifdef DEBUG
        if(new_line)
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



bool UTILS::Sensor_info_saver(int id, String name, String IP, String MAC)
{
    bool status = false;
    Sensor &p =  fetch_Sensor_obj(id);
    if (p.id != -1)
    {
        p.id = id;
        p.name = name;
        p.IP = IP;
        p.MAC = MAC;
        status = true;
    }
    else {
        Serial.println("Error!");
        status = false;
    }
    return status;
}


Sensor& UTILS::fetch_Sensor_obj(int id) 
{
    Sensor* result = nullptr;
    switch (id) {
        case 0:
        result = &s1;
        break;
        case 1:
        result = &s2;
        break;
        case 2:
        result = &s3;
        break;
        case 3:
        result = &s4;
        break;
        default:
        result = &tmp;
        result->id = -1;
    }
  return *result;
}


String UTILS::Parser(String inStr)
{
    if (!(inStr.length() > 0))
    {
        Serial.println("String is empty");
        return "";
    }
    Serial.println("inStr : " + inStr);
    String strp[7];
    splitstr(inStr, "@",  strp);
    int id = String(strp[0]).toInt();
    Sensor_info_saver( id, String(strp[1]), String(strp[2]), String(strp[3]));
    // Find_Sensor_data_by_id(id);
    Serial.println(String(Find_Sensor_id_by_name("Water  level")));
    // Find_Sensor_data_by_id(id);
    Serial.println("im Here : " + String(__LINE__));
    /*
        i will handle connect & disconnect event outside
        if (inStr.indexOf("Connected") != -1 )
        {
        Serial.println("im Here : " + String(__LINE__));
        Switch_saver(id, "", String(strp[2]), String(strp[3]));
        }
        else if (inStr.indexOf("Disconnected") != -1)
        {
        Serial.println("im Here : " + String(__LINE__));
        Switch_saver(id, "", "", "");
        }
        else
        {
        }
    */
    return "";
}

String UTILS::Find_Sensor_name_by_id(int id)
{
    String data;
    Sensor &p =  fetch_Sensor_obj(id);
    if (p.id != -1)
    {
        Serial.println(p.id);
        Serial.println(p.name);
        Serial.println(p.IP);
        Serial.println(p.MAC);
    }
    return "";
}

int UTILS::Find_Sensor_id_by_name(String name)
{
    for (int i = 0; i < 4; i++)
    {
        Sensor &p =  fetch_Sensor_obj(i);
        String sensor_name = p.name;
        if (p.id == -1)
        {
        break;
        }
        sensor_name.toUpperCase();
        name.toUpperCase();
        if (name == sensor_name)
        {
        return p.id;
        }
    }
    return -1;
}