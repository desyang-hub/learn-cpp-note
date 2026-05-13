#include <iostream>
#include <array>
#include <stddef.h>
#include <assert.h>

using namespace std;

template<class T, int MAX_SIZE>
class Stack
{
private:
    std::array<T, MAX_SIZE> arr_;
    int idx_;
public:
    Stack() : idx_(-1) {}
    virtual ~Stack() = default;

public:
    void push(const T& val) {
        assert(idx_ + 1 == MAX_SIZE && "push error, exceed stack max capacity.");
        arr_[++idx_] = val;
    }

    T pop() {
        assert(idx_ != -1 && "pop error, stack no any elements.");
        T v = std::move(arr_[idx_]);
        --idx_;
        return v;
    }

    size_t size() const {
        return idx_ + 1;
    }

    size_t capcity() const {
        return MAX_SIZE;
    }

    bool empty() const {
        return idx_ == -1;
    }
};


int main(int argc, char const *argv[])
{
    
    Stack<int, 5> s;
    s.push(1);
    s.push(2);
    std::cout << "element nums: " << s.size() << endl;

    while (!s.empty()) {
        std::cout << s.pop() << std::endl;
    }

    return 0;
}
