#include <iostream>

using namespace std;

class Integer {
private:
    int data_;
public:
    Integer(int value = 0) : data_(value) {
        cout << *this << " 对象构造" << endl;
    }

    ~Integer() {
        // 析构发生
        cout << *this << " 对象析构" << endl;
    }

    friend ostream& operator<<(ostream& os, const Integer& it) {
        return os << "Integer{" << it.data_ << "}";
    }
};

int main() {
    Integer a(2);

    Integer b = std::move(a);
    

    return 0;
}