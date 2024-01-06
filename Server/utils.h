#include "Arduino.h"

#ifndef UTILS_H_
#define UTILS_H_

class UTILS
{
private:
public:
    void Logger(String function_name, int lineNo, String msg, bool new_line=false, bool new_tab=false);
};

#endif