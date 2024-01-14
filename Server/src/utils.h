#include "Arduino.h"

#ifndef UTILS_H_
#define UTILS_H_
    #include "../global_defines.h"

typedef struct Sensor
{
    int id;
    String name, IP, MAC;
} Sensor;
    class UTILS
    {
        private:
        public:
            void Logger(String function_name, int lineNo, String msg, bool new_line=false, bool new_tab=false);
            void splitstr(String str, const char *dl, String *myd);
            bool Sensor_info_saver(int id, String name, String IP, String MAC);
            Sensor &fetch_Sensor_obj(int id);
            String Parser(String inStr);
            String Find_Sensor_name_by_id(int id);
            int Find_Sensor_id_by_name(String name);
    };

#endif