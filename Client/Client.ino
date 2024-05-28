#include <ESP8266WiFi.h>
#include <espnow.h>

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

void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&Server, incomingData, sizeof(myData));
  // Serial.print("Length of data : ");
  // Serial.print("\n" + String(len));
  // Serial.print("MAC : ");
  // Serial.printf("%d", mac);
  // Serial.print("\nMSG: ");
  // Serial.print(Server.MSG);
  // Serial.println();
}

void setup() {
  // Init Serial Monitor
  Serial.begin(74880);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  // WiFi.hostname(SensorName);
  WiFi.softAP(SensorName);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
  SensorName.toCharArray(myData.Name, SensorName.length() + 1);
}



void handleServer() {
  if (String(Server.MSG).length() > 0) {
    Serial.println("Server Messege : " + String(Server.MSG));
    Server = { 0 };
  }
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    myData.distance = random(1, 99);
    Serial.println("Im Sending : " + String(myData.distance));
    esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));
    lastTime = millis();
    delay(100);
    handleServer();
  }
  delay(300);
}
