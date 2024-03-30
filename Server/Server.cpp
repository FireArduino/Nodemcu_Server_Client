#include "Server.h"

Wifi_AP wap;
WS_SERVER *ws_server;
String tmp_str;
UTILS util;
String tmp_msg = "";
void Serversetup()
{
    wap.setSSID("ESPWIFI");
    wap.setPassKey("12345678");
    if (wap.make_softAP(15))
    {
        while (!wap.isSoftAP())
            ;
        ws_server = new WS_SERVER(8889);
        ws_server->begin();
    }
}

void Serverloop()
{
    ws_server->loop();
    // delay(100);
    String WS_recivedString = ws_server->msg;
    // Serial.println(ws_server->clients(true));
    if (tmp_msg != WS_recivedString)
    {
        tmp_msg = WS_recivedString;
        // splitstr(WS_recivedString, "@",  strp);
        int id = WS_recivedString.substring(0, WS_recivedString.indexOf('@')).toInt();
        ws_server->sendMsg(id, "ok");
        util.Parser(WS_recivedString + "@" + ws_server->remoteIP(id).toString());
    }
}