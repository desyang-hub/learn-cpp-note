#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <iostream>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) { perror("pipe"); return 1; }

    // pipefd[0] 读端 pipefd[1] 写端

    pid_t pid = fork();
    if (pid == 0) { // 子进程：写
        close(pipefd[0]); // 关闭读
        const char* msg = "Hello from child";
        write(pipefd[1], msg, strlen(msg));
        close(pipefd[1]); // 写完后关闭写
        _exit(0);
    } else { // 父进程：读
        close(pipefd[1]); // 关闭写
        char buf[256]{};
        ssize_t n = read(pipefd[0], buf, sizeof(buf) - 1);
        std::cout << "Parent received: " << buf << " (" << n << " bytes)\n";
        close(pipefd[0]); // 读完后关闭读
        wait(nullptr);
    }
}