#include "utils.h"

void UTILS::Logger(String function_name, int lineNo, String msg, bool new_line, bool new_tab)
{
    if(new_tab)
    {
        msg.replace(",","\t");
    }
    
    String print_msg = String("Function : " + function_name + " L : " + String(lineNo) + "\n MSG : " + msg);

    if(new_line)
    {
        Serial.println(print_msg);
    }
    else
    {
        Serial.print(print_msg);
    }
}