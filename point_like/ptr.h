#ifndef __PTR__
#define __PTR__

#include <iostream>
using namespace std;

template<typename T>
class Ptr {
public:
    Ptr(T* ptr) : m_data(ptr) {

    }

    T& operator*() const {
        return *m_data;
    }

    T* operator->() const {
        return m_data;
    }

    ~Ptr() {
        delete m_data;
        m_data = nullptr;
    }
private:
    T* m_data;
};

#endif