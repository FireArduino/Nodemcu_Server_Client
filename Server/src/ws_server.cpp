#include "ws_server.h"

String WS_SERVER::msg;
bool WS_SERVER::msg_recived =false;
// IPAddress WS_SERVER::remoteIP(uint8_t num);

void WS_SERVER::begin()
{
    // WebSocketsServer::WebSocketsServer(wsport);
    WebSocketsServer::begin();
    WebSocketsServer::onEvent(WS_SERVER::customwebSocketEvent);
}

void WS_SERVER::customwebSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
    // unsigned int clientID = num;     
    String strdata;
    String Clint_ip;    
    IPAddress clientIP;                                                              // Connected client ID
    // Wsip = webSocket.remoteIP(clientID).toString();                                                          // Connected client IPAddress
    // String Welcome_Str = "Hey! " + Wsip + ":[" + String(clientID) + "]" + " Welcome to FireWebSocketServer"; // Welcome Messege For Client.
    switch (type)
    {
        case WStype_DISCONNECTED: // on disconnect
            // Wsip = webSocket.remoteIP(clientID).toString();
            // Serial.print("\\nClient[");
            // Serial.print(num);
            // Serial.print("] Disconnected!");
            msg = String(num)+":Disconnected!";
            msg_recived = true;
            break;
        case WStype_CONNECTED: // on connect
            // Wsip = webSocket.remoteIP(clientID).toString();
            // Serial.print("\\nConnected from ");
            // Serial.print(Wsip + ":");
            // Serial.print(num);
            msg = String(num)+":Connected!";
            msg_recived = true;
            // Serial.printf(" url: %s", payload);
            // webSocket.sendTXT(clientID, Welcome_Str);

            break;
        case WStype_TEXT: // on Text Frame
            /* ---------------------------------------- I`m Remove this as Aniket told me --------------------------------------- */
            // Clint_ip = WebSocketsServer::remoteIP(num).toString();
            // clientIP = remoteIP(num);
            // Clint_ip = clientIP.toString();
            // clientIP = this->remoteIP(num);
            // Serial.print("\\n");
            // Serial.print(clientID);
            // Serial.print(":" + Wsip);
            // Serial.printf(" : %s", payload);
            /* ---------------------------------------- I`m Remove this as Aniket told me --------------------------------------- */
            // _payloadStr = String(reinterpret_cast<char*>(payload), length);
            // int length = int(length);
            // char payloadCharArray[(length + 1)];  // +1 for null terminator
            // strncpy(payloadCharArray, reinterpret_cast<char*>(payload), length);
            // payloadCharArray[length] = '\0';  // Null terminate the string
            // Serial.printf("Messege is : \n%s", payload);
            strdata = "";
            for(size_t i=0; i<length;i++)
            {
                strdata += char(payload[i]);
                // Serial.println(String(__LINE__)+" : "+String(__FUNCTION__)+" strdata : "+strdata);
            }
            // strdata = String((char*)payload);
            // Serial.println(strdata);
            msg = String(num) + String(":") +  strdata;
            msg_recived = true;
            // Serial.println(String(__LINE__)+" : "+String(__FUNCTION__)+" msg : "+msg);
            break;
        case WStype_BIN: // on BIN Frame
            // Serial.print("\\n");
            // Serial.print(num);
            // Serial.printf(" get binary length: %u\\n", length);
            // hexdump(payload, length);
            break;
    }
}


String WS_SERVER::getRecivedmsg(void)
{
    // Serial.println(String(__LINE__)+" : "+String(__FUNCTION__)+" msg : "+msg);
    String tmp_msg = "";
    if(msg.length() > 0 && msg_recived)
    {
        tmp_msg =  msg;
        msg = "";
        msg_recived = false;
    }
    return tmp_msg;
}

// /* ------------------------------------------------- // MARK : setup ------------------------------------------------ */

void WS_SERVER::loop()
{
    WebSocketsServer::loop();
}

int WS_SERVER::clients(bool ping)
{
    return WebSocketsServer::connectedClients(ping);
}

// IPAddress WS_SERVER::remoteIP(uint8_t num)
// {
//     // WebSocketsServer serverInstance;
//     return WebSocketsServer::getremoteIP(num);
// }