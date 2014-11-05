#ifndef SOCKET_CLASS
#define SOCKET_CLASS

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

const int MAX_HOST_NAME = 200;
const int MAX_CONNECT_NUM = 5;
const int MAX_RECV = 500;

class Socket
{
public:
    Socket();
    virtual ~Socket();
    bool create();
    bool bind(const int port);
    bool listen() const;
    bool accept(Socket&) const;
    bool connect(const std::string host, const int port);
    bool send(const std::string) const;
    int recv(std::string&) const;
    void set_non_blocking(const bool);
    bool is_valid() const {return m_sock != -1;}
private:
    int m_sock;
    sockaddr_in m_addr;
};
#endif
