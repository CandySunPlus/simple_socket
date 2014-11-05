#include "server_socket.h"
#include "socket_exception.h"
#include <iostream>

int main(int argc, const char *argv[])
{
    std::cout << "running..." << std::endl;

    try {
        ServerSocket server(30000);

        while (true) {
            ServerSocket new_sock;
            server.accept(new_sock);
            std::cout << "connect accepted" << std::endl;
            try {
                while (true) {
                    std::string data;
                    new_sock >> data;
                    new_sock << data;
                }
            } catch (SocketException&) {}

        }
    } catch (SocketException& e) {
        std::cout << "Exception was caught:" << e.description() << std::endl;
        std::cout << "Exiting." << std::endl;
    }

    return 0;
}
