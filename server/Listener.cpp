#include "Listener.h"
#include "SocketConnection.h"

Listener::Listener(io_context &ioc, const ip::tcp::endpoint &endpoint) : acceptor(ioc, endpoint) {
    AcceptConnection();
}

void Listener::AcceptConnection() {
    acceptor.async_accept([this] (error_code err, ip::tcp::socket socket) {
        if (!err) {
            std::cout << "Server accepted connection from client" << std::endl;
            std::make_shared<SocketConnection>(std::move(socket))->AcceptWebsocket();
        }

        AcceptConnection();
    });
}
