#include "server_socket.h"
#include "socket_exception.h"
#include <iostream>
#include <list>
#include <thread>

std::list<Socket*> ServerSocket::clientSockets;
bool ServerSocket::serviceFlag = true;

ServerSocket::ServerSocket(const int port) {

    if (!Socket::create()) {
        throw SocketException("Could not create server socket.");
    }

    if (!Socket::bind(port)) {
        throw SocketException("Could not bind to port.");
    }

    if (!Socket::listen()) {
        throw SocketException("Could not listen to socket.");
    }
}

ServerSocket::~ServerSocket() {
    std::list<Socket*>::iterator iter;
    for (iter=clientSockets.begin(); iter!=clientSockets.end(); iter++) {
        delete (*iter);
    }
}

void ServerSocket::accept(Socket &sock) {
    if (!Socket::accept(sock)) {
        throw SocketException("Could not accept socket.");
    }
}

void ServerSocket::run() {
    while(serviceFlag) {
        if (clientSockets.size() >= static_cast<unsigned int>(MAX_CONNECT_NUM)) {
            serviceFlag = false;
        } else {
            serviceFlag = accept();
        }
        sleep(1);
    }
}

bool ServerSocket::accept() {
    Socket* clientSocket = new Socket;
    accept(*clientSocket);
    addClient(clientSocket);

    std::thread newThread(&ServerSocket::processMessage, *this, static_cast<void*>(clientSocket));

    return true;
}

void ServerSocket::addClient(Socket *socket) {
    clientSockets.push_back(socket);
    std::cout << "Now " << clientSockets.size() << " Users." << std::endl;
}

void ServerSocket::deleteClient(Socket *socket) {
    std::list<Socket*>::iterator iter;
    for(iter=clientSockets.begin(); iter!=clientSockets.end(); iter++) {
        if ((*iter)->getAddress() == socket->getAddress() &&
                (*iter)->getPort() == socket->getPort()) {
            delete (*iter);
            clientSockets.erase(iter);
            std::cout << "Now " << clientSockets.size() << "Users." << std::endl;
            break;
        }
    }
}

void *ServerSocket::processMessage(void *arg) {
    std::string message;
    Socket* clientSocket = static_cast<Socket*>(arg);
    send(*clientSocket, "Welcome.");

    while(serviceFlag) {
        recv(*clientSocket, message);
        if (message == "exit") {
            send(*clientSocket, "user exit.");
            deleteClient(clientSocket);
            break;
        } else {
            sendMsgToAllClient(message);
        }
        sleep(1);
    }
    return NULL;
}

void ServerSocket::sendMsgToAllClient(const std::string &message) {
    std::list<Socket*>::iterator iter;
    for (iter=clientSockets.begin(); iter!=clientSockets.end(); iter++) {
        send(*(*iter), message);
    }
}
