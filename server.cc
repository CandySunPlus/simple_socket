#include "server_socket.h"
#include "socket_exception.h"
#include <iostream>
#include <thread>

int main(int argc, const char *argv[])
{
    std::cout << "running..." << std::endl;
    try {
        ServerSocket server(30000);
        server.run();
    } catch (SocketException& e) {
        std::cout << "Exception was caught:" << e.description() << std::endl;
        std::cout << "Exiting." << std::endl;
    }

    return 0;
}
