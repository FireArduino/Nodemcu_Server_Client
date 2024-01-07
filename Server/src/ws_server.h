#ifndef WS_SERVER_H_
#define WS_SERVER_H_

#include <Arduino.h>
#include <WebSocketsServer.h>

class WS_SERVER : public WebSocketsServer
{
    private:
        static void customwebSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length);
        // IPAddress remoteIP(uint8_t num);
    public:
        WS_SERVER(const int port) : WebSocketsServer(port){};
        static String msg;
        static bool msg_recived;
        // IPAddress remoteIP(uint8_t num);
        void begin();
        void loop();
        String getRecivedmsg(void);
        int clients(bool ping = false);
};

#endif