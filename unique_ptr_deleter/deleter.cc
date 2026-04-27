#include <memory>
#include <cstdio>
#include <iostream>


class Deleter
{
private:
    /* data */
public:
    Deleter(/* args */);
    ~Deleter();

    void close()  {
        std::cout << "invoke close" << std::endl;
    }
};

Deleter::Deleter(/* args */)
{
    
}

Deleter::~Deleter()
{
    std::cout << "~Deleter()" << std::endl;
}


void deleter_demo() {

    auto d_ptr = new Deleter();

    auto deleter = [](Deleter* d) {
        d->close();
        delete d;
    };

    auto d = std::unique_ptr<Deleter, decltype(deleter)>(d_ptr, deleter);

    
}

int main() {
    // 1. 默认删除器：delete（与普通 unique_ptr 一样）
    std::unique_ptr<int> p1(new int(42));

    // 2. 自定义删除器：管理 FILE*
    auto fclose_deleter = [](FILE* f) {
        if (f) {
            std::cout << "Closing file\n";
            fclose(f);
        }
    };
    std::unique_ptr<FILE, decltype(fclose_deleter)> file_ptr(fopen("test.txt", "r"), fclose_deleter);

    // 3. 自定义删除器：带清理日志
    auto log_deleter = [](int* p) {
        std::cout << "Deleting " << *p << '\n';
        delete p;
    };
    std::unique_ptr<int, decltype(log_deleter)> p2(new int(100), log_deleter);


    deleter_demo();
}