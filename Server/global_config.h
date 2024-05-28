#ifndef GLOBAL_DEFINES_H_
#define GLOBAL_DEFINES_H_

#include <ESP8266WiFi.h>
#include <espnow.h>

#define WL_THRASOLD 20
#define RELAY D2
#define MAX_SENSOR 3

// #define DEBUG 1

#ifdef DEBUG
// #define Serial 1
// #define DEBUG_SAP2 1
// #define DEBUG_WS1 1
// #define DEBUG_WS2 1
// #define DEBUG_WS9 1
#endif


typedef struct struct_message {
  int distance;
  char Name[20];
} struct_message;

typedef struct SensorInfo {
  char Name[20];
  uint8_t mac[6];
} SensorInfo;

int old_distance = 0;


typedef struct ClientMsg {
  char MSG[20];
} ClientMsg;

struct_message myData;
SensorInfo Sensor[MAX_SENSOR];
ClientMsg client;

int Sensor_id = 0;


#endif