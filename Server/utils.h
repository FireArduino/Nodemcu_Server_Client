#include "Arduino.h"

#ifndef UTILS_H_
#define UTILS_H_

class UTILS
{
private:
public:
    void Logger(String function_name, int lineNo, bool new_line, bool new_tab);
};

#endif