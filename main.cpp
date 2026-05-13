#include <iostream>

#include <memory>

using namespace std;

void show(unique_ptr<int>& ptr) {
    cout << *ptr << endl;
}

int main() {

    auto ptr = std::make_unique<int>(5);
    show(ptr);
    
    return 0;
}