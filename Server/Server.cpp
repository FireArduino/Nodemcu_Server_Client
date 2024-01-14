#include "Server.h"

Wifi_AP wap;
WS_SERVER ws_server = WS_SERVER(8889);
String tmp_str;
String strp[10];
UTILS util;

void Serversetup()
{
    wap.setSSID("ESPWIFI");
    wap.setPassKey("12345678");
    if (wap.make_softAP(15))
    {
        while(!wap.isSoftAP());
        ws_server.begin();
    }
}

void Serverloop()
{
    ws_server.loop();
    delay(100);
    String WS_recivedString = ws_server.getRecivedmsg();
    if (WS_recivedString.length() > 0)
    {
        Serial.println(WS_recivedString);
        util.splitstr(WS_recivedString,"@",strp);
        int remote_add = String(strp[0]).toInt();
        ws_server.sendMsg(remote_add,"ok");
        String Clint_IP = ws_server.remoteIP(remote_add).toString();
        Serial.println("Server Messege is : " + strp[1]);
        Serial.println("Server IP is : " + Clint_IP);
        util.Parser(WS_recivedString);
    }
}