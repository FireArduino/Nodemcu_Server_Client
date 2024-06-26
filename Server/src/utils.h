#include "Arduino.h"

#ifndef UTILS_H_
#define UTILS_H_
#include "../global_defines.h"

class UTILS
{
    private:
        void splitstr(String str, const char *dl, String *myd);
    public:
        void Logger(String function_name, int lineNo, String msg, bool new_line = false, bool new_tab = false);
        void Parser(String inStr);
};

#endif