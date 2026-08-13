// server
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <iostream>

// client
int main() {
    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    sockaddr_un addr{AF_UNIX, "/tmp/uds.sock"};
    connect(fd, (sockaddr*)&addr, sizeof(addr));
    write(fd, "Hello UDS", 9);
    close(fd);
}