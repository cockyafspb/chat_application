#include <iostream>
#include "Headers.h"
#include "Listener.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <port>";
        return 1;
    }

    io_context ioc;
    ip::tcp::endpoint endpoint(ip::tcp::v4(), std::stoi(argv[1]));
    Listener listener(ioc, endpoint);
    std::cout << "Server started accepting connections" << std::endl;

    //graceful shutdown
    signal_set signals(ioc, SIGINT, SIGTERM);
    signals.async_wait([&ioc](error_code err, int signal) {
        if (!err) ioc.stop();
    });

    ioc.run();
    return 0;
}
