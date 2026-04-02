#include "String.h"

#include <string.h>
#include <iostream>

using namespace RAII;
using std::cout;
using std::endl;

String::String(const char* ptr) {
    cout << "RAII Construct" << endl;
    if (ptr) {
        const int str_len = strlen(ptr);
        ptr_ = new char[str_len + 1];
        strcpy(ptr_, ptr);
        ptr_[str_len] = '\0';
    }
    else {
        ptr_ = new char[1];
        ptr_[0] = '\0';
    }
}

String::~String() {
    cout << "RAII Resource Destroy" << endl;
    if (ptr_) {
        delete[] ptr_;
    }
}