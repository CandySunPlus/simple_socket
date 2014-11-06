#include <iostream>
#include "client_socket.h"
#include "socket_exception.h"

ClientSocket::ClientSocket(std::string host, int port) {
    if (!Socket::create()) {
        throw SocketException("Could not create client socket.");
    }

    if (!Socket::connect(host, port)) {
        throw SocketException("Could not bind to port.");
    }
}


void ClientSocket::receiveHandler(ClientSocket &client) {
    std::string reply;
    while (true) {
        client.recv(reply);
        std::cout << "receive server response:" << std::endl;
        std::cout << reply << std::endl;
    }
}

bool ClientSocket::send(const std::string &message) {
    return Socket::send(static_cast<Socket&>(*this), message);
}

int ClientSocket::recv(std::string &message) {
    return Socket::recv(static_cast<Socket&>(*this), message);
}
