// writer.cpp
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>

int main() {
    mkfifo("/tmp/myfifo", 0666);
    int fd = open("/tmp/myfifo", O_WRONLY);
    const char* msg = "Hello via FIFO";
    write(fd, msg, strlen(msg));
    close(fd);
}