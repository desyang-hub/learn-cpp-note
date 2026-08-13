#pragma once

#include <sys/msg.h>
#include <cstring>
#include <iostream>

// 消息队列

struct MsgBuf {
    long mtype;       // 必须 > 0
    char mtext[256];
};

// sender
void send_msg() {
    int qid = msgget(ftok("/tmp", 'M'), IPC_CREAT | 0666);
    MsgBuf msg{1, "Hello MQ"};
    msgsnd(qid, &msg, strlen(msg.mtext), 0);
}

// receiver
void recv_msg() {
    int qid = msgget(ftok("/tmp", 'M'), 0666);
    MsgBuf msg{};
    msgrcv(qid, &msg, sizeof(msg.mtext), 1, 0); // type=1
    std::cout << "MQ received: " << msg.mtext << "\n";
}