#include <iostream>
#include "client_socket.h"
#include "socket_exception.h"

int main(int argc, const char* argv[])
{
    try {
        ClientSocket client("127.0.0.1", 30000);
        std::string reply;
        try {
            client << "Test Message.";
            client >> reply;
        } catch (SocketException&) {}

        std::cout << "We received this response from the server:" << std::endl;
        std::cout << "\"" << reply << "\"" << std::endl;

    } catch (SocketException& e) {
        std::cout << "Exception was caught:" << e.description() << std::endl;
    }
    return 0;
}