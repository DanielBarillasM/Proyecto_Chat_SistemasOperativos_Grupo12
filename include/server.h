#ifndef SERVER_H
#define SERVER_H

#include "sockets.h"

class ChatServer {
public:
    ChatServer();
    void run(uint16_t port);
};

#endif