#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstring>
#include <iostream>

#include <unistd.h>

// 4. 共享内存 + 信号量（经典组合）

union semun {
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};

int main() {
    // 创建共享内存
    int shmid = shmget(IPC_PRIVATE, 4096, IPC_CREAT | 0666);
    char* shm = (char*)shmat(shmid, nullptr, 0);

    // 创建二进制信号量（初始值=1）
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    semun arg{1};
    semctl(semid, 0, SETVAL, arg);

    pid_t pid = fork();
    auto p_op = [](int id, int op) {
        sembuf sb{0, (short)op, SEM_UNDO};
        semop(id, &sb, 1);
    };

    if (pid == 0) {
        p_op(semid, -1); // P
        strcpy(shm, "Child wrote this");
        p_op(semid, +1); // V
        shmdt(shm);
        _exit(0);
    } else {
        wait(nullptr); // 等待子进程结束
        p_op(semid, -1);
        std::cout << "Shm: " << shm << "\n";
        p_op(semid, +1);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, nullptr);
        semctl(semid, 0, IPC_RMID);
    }
}