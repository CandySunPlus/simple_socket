#include <iostream>
#include <thread>
#include "client_socket.h"
#include "socket_exception.h"

int main(int argc, const char* argv[])
{
    try {
        ClientSocket client("127.0.0.1", 30000);
        std::string sendBuf;
//        std::thread receiver(ClientSocket::receiveHandler, std::ref(client));

        std::cout << "Enter string send to server:" << std::endl;
        getline(std::cin, sendBuf);
        client.send(sendBuf);
        std::string message;
        client.recv(message);
        std::cout << "receive from server:" << std::endl;
        std::cout << message << std::endl;

    } catch (SocketException& e) {
        std::cout << "Exception was caught:" << e.description() << std::endl;
    }
    return 0;
}

