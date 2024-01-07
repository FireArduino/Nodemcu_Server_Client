#include "ws_server.h"

String WS_SERVER::msg;
bool WS_SERVER::msg_recived =false;
bool inside_loop = true;
bool inside_getRecivedmsg = true;
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
    String Clint_ip;    
    IPAddress clientIP;                                                              // Connected client ID
    switch (type)
    {
        case WStype_DISCONNECTED: // on disconnect
            msg = String(num)+":Disconnected!";
            msg_recived = true;
            break;
        case WStype_CONNECTED: // on connect
            msg = String(num)+":Connected!";
            msg_recived = true;
            break;
        case WStype_TEXT: // on Text Frame
            strdata = "";
            for(size_t i=0; i<length;i++)
            {
                strdata += char(payload[i]);
            }
            msg = String(num) + String(":") +  strdata;
            msg_recived = true;
            break;
        case WStype_BIN: // on BIN Frame
            break;
    }
}


String WS_SERVER::getRecivedmsg(void)
{
    #ifdef DEBUG_WS1
        if(inside_getRecivedmsg)
        {
            UTILS::Logger(__FUNCTION__,__LINE__,"Inside getRecivedmsg",true);
        }
    #endif
    String tmp_msg = "";
    if(msg.length() > 0 && msg_recived)
    {
        #ifdef DEBUG_WS2
        if(inside_getRecivedmsg)
        {
            UTILS::Logger(__FUNCTION__,__LINE__,"old messegse : " + tmp_msg + " New messegse " + msg + " msg_recived_flag is " + String(msg_recived),true);
        }
        #endif
        tmp_msg =  msg;
        msg = "";
        msg_recived = false;
        #ifdef DEBUG_WS2
        if(inside_getRecivedmsg)
        {
            UTILS::Logger(__FUNCTION__,__LINE__,"msg_recived_flag is " + String(msg_recived),true);
            inside_getRecivedmsg = false;
        }
        #endif
    }
    return tmp_msg;
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