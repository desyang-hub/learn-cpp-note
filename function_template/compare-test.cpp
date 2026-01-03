#include <iostream>
#include "compare.h"

using namespace std;

class Integer {
public:
    Integer(int value = 0) : m_data(value) {}

    bool operator>(const Integer& i) const {
        return m_data > i.m_data;
    }

    // friend bool operator>(const Integer& i1, const Integer& i2) {
    //     return i1.m_data > i2.m_data;
    // }

private:
    int m_data;
};




int main() {

    cout << compare(2, 1) << endl;

    cout << compare(Integer(3), Integer(0)) << endl;

    cout << __cplusplus << endl;

    return 0;
}