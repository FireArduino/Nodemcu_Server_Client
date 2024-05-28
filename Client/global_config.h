#ifndef GLOBAL_CONFIG_H_
#define GLOBAL_CONFIG_H_

#include <ESP8266WiFi.h>
#include <espnow.h>
#include "./src/ultraSocnicSensor.h"


String Client_name = "WaterLevel_Sensor";

#define TRIGGER_PIN D4
#define ECHO_PIN D3
#define MAX_DISTANCE 200

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;  // send readings timer

String SensorName = "WaterLevel_Sensor";

typedef struct struct_message {
  int distance;
  char Name[20];
} struct_message;

typedef struct ServerMessege {
  char MSG[24];
} ServerMessege;

uint8_t broadcastAddress[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

struct_message myData;
ServerMessege Server;

#endif