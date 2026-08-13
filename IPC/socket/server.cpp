// server
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <iostream>

int main() {
    unlink("/tmp/uds.sock");
    int srv = socket(AF_UNIX, SOCK_STREAM, 0);
    sockaddr_un addr{AF_UNIX, "/tmp/uds.sock"};
    bind(srv, (sockaddr*)&addr, sizeof(addr));
    listen(srv, 1);

    int cli = accept(srv, nullptr, nullptr);
    char buf[256]{};
    read(cli, buf, sizeof(buf) - 1);
    std::cout << "UDS: " << buf << "\n";
    close(cli); close(srv);
}