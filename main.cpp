#include <iostream>

#include <memory>

using namespace std;

void show(unique_ptr<int>& ptr) {
    cout << *ptr << endl;
}

// ❌ 浪费版
struct Bad  { char a; double b; char c; };      // sizeof = 24

// ✅ 紧凑版  
struct Good { double b; char a; char c; };       // sizeof = 16

int main() {

    cout << sizeof(Bad) << " " << sizeof(Good) << std::endl;

    auto ptr = std::make_unique<int>(5);
    show(ptr);
    
    return 0;
}