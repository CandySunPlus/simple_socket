#ifndef CLIENT_SOCKET_CLASS
#define CLIENT_SOCKET_CLASS

#include "socket.h"

class ClientSocket: private Socket
{
public:
    ClientSocket(std::string host, int port);
    virtual ~ClientSocket(){};

    const ClientSocket& operator << (const std::string&) const;
    const ClientSocket& operator >> (std::string&) const;
};
#endif