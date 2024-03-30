#include "ws_server.h"

String WS_SERVER::msg;
// bool WS_SERVER::msg_recived =false;
// bool inside_loop = true;
// bool inside_getRecivedmsg = true;
// IPAddress WS_SERVER::remoteIP(uint8_t num);

void WS_SERVER::begin()
{
    #ifdef DEBUG_WS1
        UTILS::Logger(__FUNCTION__,__LINE__,"Inside WS_begin",true);
    #endif
    WebSocketsServer::begin();
    #ifdef DEBUG_WS2
        UTILS::Logger(__FUNCTION__,__LINE__,"WS_begin Successfully",true);
    #endif
    WebSocketsServer::onEvent(WS_SERVER::customwebSocketEvent);
    #ifdef DEBUG_WS2
        UTILS::Logger(__FUNCTION__,__LINE__,"WS Callback Setup Successfully",true);
    #endif
}

void WS_SERVER::customwebSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
    String strdata;
    switch (type)
    {
        case WStype_DISCONNECTED: // on disconnect
            msg = String(num)+"@Disconnected!";
            break;
        case WStype_CONNECTED: // on connect
            msg = String(num)+"@Connected!";
            break;
        case WStype_TEXT: // on Text Frame
            strdata = "";
            for(size_t i=0; i<length;i++)
            {
                strdata += char(payload[i]);
            }
            msg = String(num) + String("@") +  strdata;
            break;
        case WStype_BIN: // on BIN Frame
            break;
    }
}


String WS_SERVER::getRecivedmsg(void)
{
    if(tmp_msg != msg)
    {
        tmp_msg = msg;
        return tmp_msg;
    }
    return "";
}

// /* ------------------------------------------------- // MARK : setup ------------------------------------------------ */

void WS_SERVER::loop()
{
    #ifdef DEBUG_WS1
        if(inside_loop)
        {
            UTILS::Logger(__FUNCTION__,__LINE__,"Inside WS_loop",true);
            inside_loop = false;
        }
    #endif
    WebSocketsServer::loop();
}

int WS_SERVER::clients(bool ping)
{
    #ifdef DEBUG_WS2
        UTILS::Logger(__FUNCTION__,__LINE__,"Inside clients\nTotal Clients : " + String(WebSocketsServer::connectedClients(ping)),true);
    #endif
    return WebSocketsServer::connectedClients(ping);
}

bool WS_SERVER::sendMsg(int id,String msg)
{
    return WebSocketsServer::sendTXT(id, msg);
}

bool WS_SERVER::isAliveClient(int id)
{
    return clientIsConnected(id);
}

void WS_SERVER::fuckClient(int id)
{
    disconnect(id);
}