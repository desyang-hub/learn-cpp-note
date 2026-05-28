#pragma once

#include <sys/socket.h>

#include "nonecopyable.h"
#include "InetAddress.h"
#include "utils.h"

class Socket : public nonecopyable
{
private:
    int fd_;
public:
    Socket();
    explicit Socket(int fd);
    ~Socket();

    Socket(const Socket& sock) = delete;
    Socket& operator=(const Socket& sock) = delete;

    Socket(Socket&& sock) __THROW;
    Socket& operator=(Socket&& sock) __THROW;

public:
    int fd() const;

    void bind(const InetAddress& addr);

    void listen(int n = SOMAXCONN);

    int accept(InetAddress& addr);

    void connect(const InetAddress& addr);

    int release();

    void close();

    int send(std::string msg) const;

    int recv(std::string& msg) const;

    void setnoneblocking() const;
};