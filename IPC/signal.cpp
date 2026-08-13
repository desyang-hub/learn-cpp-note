#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

volatile sig_atomic_t got_sig = 0;
void handler(int) { got_sig = 1; }

int main() {
    signal(SIGUSR1, handler);
    pid_t pid = fork();
    if (pid == 0) {
        sleep(1);
        kill(getppid(), SIGUSR1);
        _exit(0);
    } else {
        while (!got_sig) pause();
        std::cout << "Received SIGUSR1\n";
        wait(nullptr);
    }
}