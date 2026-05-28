#include "Socket.h"

#include <unistd.h>

#include "utils.h"

Socket::Socket() : fd_(socket(AF_INET, SOCK_STREAM, 0)) {
    errif(fd_ == -1, "socket create error");
}

Socket::Socket(int fd) : fd_(fd) {

}

Socket::~Socket() {
    this->close();
}

// 移动构造函数, 避免重复close
Socket::Socket(Socket&& sock) __THROW : fd_(sock.release()) {}

Socket& Socket::operator=(Socket&& sock) __THROW {
    fd_ = sock.release();
    return *this;
}

int Socket::fd() const {
    return fd_;
}

void Socket::bind(const InetAddress& addr) {
    errif(::bind(fd_, (sockaddr*)&addr.addr_, addr.addr_len_) == -1, "bind error");
}

void Socket::listen(int n) {
    errif(::listen(fd_, n) == -1, "listen error");
}

int Socket::accept(InetAddress& addr) {
    int fd = ::accept(fd_, (sockaddr*)&addr.addr_, &addr.addr_len_);
    errif(fd == -1, "accept error");
    return fd;
}

void Socket::connect(const InetAddress& addr) {
    errif(::connect(fd_, (sockaddr*)&addr.addr_, addr.addr_len_) == -1, "connect error");
}

int Socket::release() {
    int fd = fd_;
    fd_ = -1;
    return fd;
}

void Socket::close() {
    if (fd_ != -1) {
        ::close(fd_);
        fd_ = -1;
    }
}

int Socket::send(std::string msg) const {
    return ::send(fd_, msg.c_str(), msg.size(), 0);
}

int Socket::recv(std::string& msg) const {
    char buf[1024];
    int num_reads = ::recv(fd_, buf, 1024, 0);
    if (num_reads > 0)
        msg.append(buf, num_reads);
    return num_reads;
}

void Socket::setnoneblocking() const {
    ::setnoneblocking(fd_);
}