#include "Wifi_AP.h"
#include "ws_server.h"

Wifi_AP wap;
WS_SERVER ws_server = WS_SERVER(8889);
String tmp_str;
void setup()
{
    Serial.begin(2400);
    for (int i = 0; i < 20; i++)
    {
        Serial.flush();
    }
    if (wap.make_softAP(15))
    {
        ws_server.begin();
    }
}

void loop()
{
    ws_server.loop();
    delay(100);
    String WS_recivedString = ws_server.getRecivedmsg();
    if (WS_recivedString.length() > 0)
    {
        Serial.println(WS_recivedString);
        // tmp_str = WS_recivedString;
    }
}