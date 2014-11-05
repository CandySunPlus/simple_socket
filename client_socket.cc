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

const ClientSocket &ClientSocket::operator<<(const std::string &param) const {
    if (!Socket::send(param)) {
        throw SocketException("Could not write to socket.");
    }
    return *this;
}

const ClientSocket &ClientSocket::operator>>(std::string &param) const {
    if (!Socket::recv(param)) {
        throw SocketException("Could not read from socket.");
    }
    return *this;
}
