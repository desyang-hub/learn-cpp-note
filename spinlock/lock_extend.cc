#include <memory>
#include <mutex>
#include <vector>
#include <thread>
#include <iostream>

using namespace std;

class Counter {
private:
    mutable std::mutex mutex_;
    size_t count_{};

public:
    void deposit(int acount) {
        count_ += acount;
    }

    size_t getBlance() const {
        return count_;
    }

    std::mutex& getMutex() const {
        return mutex_;
    }
};

int main() {

    Counter counter;

    vector<std::thread> wokers;
    wokers.reserve(10);

    for (int i = 0; i < 10; ++i) {
        wokers.emplace_back([i, &counter]{
            std::lock_guard<std::mutex> lock(counter.getMutex());
            counter.deposit(i + 10);
        });
    }

    for (int i = 0; i < 10; ++i) {
        wokers[i].join();
    }

    cout << counter.getBlance() << std::endl;

    return 0;
}