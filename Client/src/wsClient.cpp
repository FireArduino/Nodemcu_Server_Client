#include "wsClient.h"

bool WSCLIENT::initClient(const String host, const int port)
{
    _connection = WebsocketsClient::connect(host, port, "/");

    WebsocketsClient::onMessage([&](websockets::WebsocketsMessage message)
                                {_messageReceived = true; _MSG = message.data(); });
    return _connection;
}

String WSCLIENT::getMsg()
{
    if (_MSG.length() > 0 && _messageReceived && _MSG != tmp_msg)
    {
        tmp_msg = _MSG;
        _MSG = "";
        _messageReceived = false;
    }
    return tmp_msg;
}

bool WSCLIENT::sendMsg(String msg)
{
    if (WebsocketsClient::available())
    {
        WebsocketsClient::send(msg);
        return true;
    }
    return false;
}

void WSCLIENT::clinetLoop()
{
    if (WebsocketsClient::available())
    {
        WebsocketsClient::poll();
    }
}