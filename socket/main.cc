#include <thread>
#include <iostream>
#include <unistd.h>

#include "Socket.h"

void client_worker() {
    Socket sock;
    InetAddress addr(8080);

    sock.connect(addr);
    std::string msg;
    while (true) {
        msg.clear();
        sock.send("hello! im client");

        int num = sock.recv(msg);
        if (num <= 0) {
            std::cout << "connection disconnect." << std::endl;
            break;
        }
        std::cout << "recv server msg: " << msg << std::endl;
        sleep(1);
    }
}

void server_worker() {
    Socket sock;
    InetAddress addr(8080);
    sock.bind(addr);
    sock.listen();

    std::string msg;

    while (true) {
        msg.clear();
        InetAddress client_addr;
        int fd = sock.accept(client_addr);
        Socket cli(fd);

        int num = cli.recv(msg);
        if (num > 0) {
            std::cout << "recv cli msg: " << msg << std::endl;
            int bytes = cli.send(msg);
            if (bytes < msg.size()) {
                std::cout << "send error" << std::endl;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    
    std::thread server(server_worker);
    sleep(1);
    std::thread client(client_worker);

    client.join();
    server.join();
    return 0;
}
