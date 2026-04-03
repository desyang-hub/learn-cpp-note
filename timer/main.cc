#include "Timer.h"

#include <iostream>
#include <cstring>

void test() {

    TIMER_START_TAG(timer01);
    for (int i = 0; i < 1e8; ++i) {
        i++;
    }
    TIMER_FINISH_TAG(timer01);
    // TIMER_FINISH();

    TIMER_START();
    for (int i = 0; i < 1e8; ++i) {
        i++;
    }
}

int main() {
    TIMER_START();

    test();
    return 0;
}