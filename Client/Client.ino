#include <Arduino.h>
#include "global_config.h"
WSCLIENT client;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
String msg;
unsigned long int delay_time = 0;
void setup()
{
    Serial.begin(2400);
    setWifi_Hostname(Client_name);
    setPortelTimeout(1*60);
    enableLogs(true);
    while (!inti_wifi_manager(Client_name.c_str()))
        ;
        delay(100);
    bool connected = client.initClient(serverStaticIP, serverPort);
        delay(50);
    if (connected)
    {
        Serial.println("Connecetd!");
    }
    else
    {
        Serial.println("Not Connected!");
        ESP.restart();
    }
    Serial.println("GateWay : " + WiFi.gatewayIP().toString());
    Serial.println("IP : " + WiFi.localIP().toString());
}


void loop()
{
    if ((WiFi.status() != WL_CONNECTED) || (WiFi.localIP().toString() == "0.0.0.0")) {
        Serial.println("ROUTER DISCONNECTED !!!!");
        ESP.restart();
    }
    client.clinetLoop();
    msg = client.getMsg();
    int distance = sonar.ping_cm();
    Serial.print("Ping: ");
    Serial.print(distance);
    Serial.println("cm");
    // delay(50);
    if(distance > 0 && msg == "ok" && millis() > delay_time + 2000)
    {
        delay_time = millis();
        // Serial.print("Ping: ");
        // Serial.print(distance);
        // Serial.println("cm");
        client.sendMsg(Client_name +"@"+ WiFi.localIP().toString() +"@"+String(distance));
    }         
}
