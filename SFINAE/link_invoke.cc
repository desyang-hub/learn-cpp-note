#include <iostream>

using namespace std;

class person {
private:
    std::string name_;
    int age_;
    int id_;

public:
    person& name(const std::string& name) {
        name_ = name;
        return *this;
    }

    person& age(int n) {
        age_ = n;
        return *this;
    }

    person& id(int d) {
        id_ = d;
        return *this;
    }
};


int main(int argc, char const *argv[])
{
    
    person a;
    a.name("xioaming").age(22).id(1022);

    return 0;
}
