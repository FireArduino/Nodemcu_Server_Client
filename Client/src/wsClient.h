#ifndef WSCLIENT_H_
#define WSCLIENT_H_

#include <ArduinoWebsockets.h>

class WSCLIENT : public websockets::WebsocketsClient
{
private:
    String _MSG = "";
    bool _connection = false;
    bool _messageReceived = false;

public:
    bool initClient(const String host, const int port);
    String getMsg();
    bool sendMsg(String msg);
    void clinetLoop();
};

#endif