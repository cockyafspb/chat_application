#ifndef CLIENT_SERVER_LISTENER_H
#define CLIENT_SERVER_LISTENER_H

#include "Headers.h"

class Listener {
public:
    Listener(io_context& ioc, const ip::tcp::endpoint& endpoint);
    void AcceptConnection();

private:
    ip::tcp::acceptor acceptor;
};


#endif //CLIENT_SERVER_LISTENER_H
