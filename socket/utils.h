#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>

inline void errif(bool condition, const char* msg) {
    if (condition) {
        perror(msg);
        exit(-1);
    }

    assert(true);
}

#define Errorif(condition, msg) \
    if (condition) { \
        perror(msg); \
        exit(-1); \
    }

#define Errorif(condition, msg) \
    if (condition) { \
        perror(msg); \
        exit(-1); \
    }


#define Assert(condition)

inline void setnoneblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl get error");
        return;
    }

    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}