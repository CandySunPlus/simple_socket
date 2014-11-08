#ifndef SERVER_SOCKET_CLASS
#define SERVER_SOCKET_CLASS

#include "socket.h"
#include <list>
#include <thread>

class ServerSocket : public Socket
{
public:
    ServerSocket(const int port);
    ServerSocket(){};
    virtual ~ServerSocket();
    void accept(Socket &);
    void run();
private:
    bool accept();
    void addClient(Socket *);
    void deleteClient(Socket *);
    void* processMessage(void* arg);
    void sendMsgToAllClient(const std::string& message);
    std::thread *thread;
    static std::list<Socket*> clientSockets;
    static bool serviceFlag;
};
#endif