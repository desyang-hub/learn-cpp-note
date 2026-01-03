#include <iostream>

using namespace std;

template<typename T>
const T& Max(const T& a, const T& b) {
    return a > b ? a : b;
}

class Integer {
public:
    Integer(const int& val=0) : m_data(val) {

    }
    
    friend bool operator>(const Integer& a, const Integer& b) {
        return a.m_data > b.m_data;
    }

    friend std::ostream& operator<<(std::ostream& os, const Integer& b) {
        return os << b.m_data;
    }
private:
    int m_data;
};




int main() {

    Integer a, b(1), c(-2);

    cout << Max(a, Max(b, c)) << endl;

    return 0;
}