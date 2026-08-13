// reader.cpp
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

int main() {
    int fd = open("/tmp/myfifo", O_RDONLY); // 阻塞直到有写端打开
    char buf[256]{};
    read(fd, buf, sizeof(buf) - 1);
    std::cout << "Read: " << buf << "\n";
    close(fd);
}