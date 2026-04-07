#ifdef __cplusplus
extern "C" {
#endif
#include "c_add/add.h"
#ifdef __cplusplus
}
#endif

#include <iostream>
using namespace std;

int main() {
    std::cout << add(1, 2) << std::endl;

    return 0;
}