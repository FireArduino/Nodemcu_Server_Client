#include "utils.h"

void UTILS::Logger(String function_name, int lineNo, bool new_line, bool new_tab)
{
String msg = "Function : " + function_name + " L : " + String(lineNo) + "\n MSG : " + msg";
    Serial.println();
}