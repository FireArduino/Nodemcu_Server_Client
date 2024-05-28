#include "global_defines.h"

typedef struct struct_message {
  int distance;
  char Name[20];
} struct_message;

typedef struct SensorInfo {
  char Name[20];
  uint8_t mac;
} SensorInfo;

int old_distance = 0;


typedef struct ClientMsg {
  char MSG[20];
} ClientMsg;

#define MAX_SENSOR 3

struct_message myData;
SensorInfo Sensor[MAX_SENSOR];
ClientMsg client;
int Sensor_id = 0;

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;  // send readings timer

void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("MAC : ");
  char macAddr[18];
  sprintf(macAddr, "%2X:%2X:%2X:%2X:%2X:%2X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  Serial.println(macAddr);
  Serial.println();
}

void setup() {
  Serial.begin(74880);
  for (int i = 0; i < 20; i++) {
    Serial.flush();
  }
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  pinMode(RELAY, OUTPUT);
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);

  esp_now_register_recv_cb(OnDataRecv);
}

bool Data_sendor(String Messege, String Sensor_name) {
  Messege.toCharArray(client.MSG, Messege.length());
  for (int s = 0; s <= MAX_SENSOR; s++) {
    if (String(Sensor[s].Name) == Sensor_name) {
      esp_now_send((uint8_t *)Sensor[s].mac, (uint8_t *)&Messege, sizeof(Messege));
      return true;
    }
  }
  return false;
}


void handleRelay() {
  if (old_distance != myData.distance) {
    if (myData.distance > WL_THRASOLD) {
      Serial.println("distance :  " + String(myData.distance));
      Serial.println("Sensor Name :  " + String(myData.Name));
      Serial.println("Water level low turning Pump On");
      digitalWrite(RELAY, HIGH);
      // if (Data_sendor("OK", "WaterLevel_Sensor")) {
      //   Serial.println("Replyed To Water level Sensor");
      // }
    } else {
      Serial.println("Water tank level ok !");
      digitalWrite(RELAY, LOW);
    }
    old_distance = myData.distance;
    myData = { 0 };
  }
}

void loop() {
  handleRelay();
  delay(100);
}