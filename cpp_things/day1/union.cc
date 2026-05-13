#include <iostream>
#include <memory>

using namespace std;


template<class T>
union Store {
    Store* next;
    T data;

    Store() {
        static_assert(sizeof(T) >= sizeof(char*) && "T calss must exceed 4/8 bytes.");
    }
};

int main(int argc, char const *argv[])
{

    int chunk = 20;

    auto freeStore = (Store<int>*)malloc(chunk * sizeof(Store<int>));

    Store<int>* p = freeStore;

    for (int i = 1; i < chunk; ++i) {
        freeStore->next = (Store<int>*)((char*)freeStore + sizeof(Store<int>));
        freeStore = freeStore->next;
    }
    freeStore->next = nullptr;

    free(p);
    
    return 0;
}
