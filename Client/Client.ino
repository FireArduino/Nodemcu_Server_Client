#include <Arduino.h>
#include "global_config.h"
WSCLIENT client;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup()
{
    Serial.begin(2400);
    setWifi_Hostname(Client_name);
    enableLogs(true);
    while (!inti_wifi_manager(Client_name.c_str()))
        ;
        delay(100);
    bool connected = client.initClient(serverStaticIP, serverPort);
        delay(50);
    if (connected)
    {
        Serial.println("Connecetd!");
        // client.sendMsg("Hello Server");
    }
    else
    {
        Serial.println("Not Connected!");
        ESP.restart();
    }
    Serial.println("GateWay : " + WiFi.gatewayIP().toString());
    Serial.println("IP : " + WiFi.localIP().toString());
}
unsigned long int  count = 0;
void loop()
{
    client.clinetLoop();
    int distance = sonar.ping_cm();
    delay(50);
    if(distance > 0)
    {
        Serial.print("Ping: ");
        Serial.print(distance);
        Serial.println("cm");
        client.sendMsg(Client_name +"@"+ String(distance));
    }
    String msg = client.getMsg();
    Serial.println(msg);              
}
