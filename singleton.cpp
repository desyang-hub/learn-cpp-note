#include <iostream>

using namespace std;

class Singleton {
public:
    static Singleton& get_instance() {
        static Singleton instance;
        return instance;
    }

    Singleton& setup() {
        cout << "Call setup func" << endl;
        return *this;
    }

private:
    Singleton() {}
    Singleton(Singleton& ins){}
    
};


int main() {
    Singleton::get_instance().setup();

    return 0;
}