#ifndef GLOBAL_CONFIG_H_
#define GLOBAL_CONFIG_H_


#include "./src/WiFiManager.h"
#include "./src/wsClient.h"
#include <NewPing.h>

String serverStaticIP = "192.168.4.1";
int serverPort = 8889;
String Client_name = "WaterLevel_Sensor";
#define TRIGGER_PIN  D4 
#define ECHO_PIN     D3 
#define MAX_DISTANCE 200









#endif