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