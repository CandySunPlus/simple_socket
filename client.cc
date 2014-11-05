#include <iostream>
#include <thread>
#include "client_socket.h"
#include "socket_exception.h"

int main(int argc, const char* argv[])
{
    try {
        ClientSocket client("127.0.0.1", 30000);
        std::string sendBuf;
        std::thread receiver(ClientSocket::receiveHandler, std::ref(client));

        while (true) {
            std::cout << "Enter string send to server:" << std::endl;
            getline(std::cin, sendBuf);
            if (sendBuf.compare("quit") == 0) {
                break;
            }
            try {
                client << sendBuf;
            } catch (SocketException&) {}
        }
    } catch (SocketException& e) {
        std::cout << "Exception was caught:" << e.description() << std::endl;
    }
    return 0;
}

