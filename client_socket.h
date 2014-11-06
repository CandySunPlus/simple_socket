#ifndef CLIENT_SOCKET_CLASS
#define CLIENT_SOCKET_CLASS

#include "socket.h"

class ClientSocket: public Socket
{
public:
    ClientSocket(std::string host, int port);
    virtual ~ClientSocket(){};
    bool send(const std::string&);
    int recv(std::string&);
    static void receiveHandler(ClientSocket& client);
};
#endif