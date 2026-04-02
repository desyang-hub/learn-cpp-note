#include <memory>
#include <malloc.h>
#include <iostream>

using namespace std;

int main() {
    int len = sizeof(int);
    void* mem = malloc(len);
    
    int* intPtr = new (mem)int(8);

    cout << *intPtr << endl;

    if (mem) {
        free(mem);
    }
    return 0;
}
