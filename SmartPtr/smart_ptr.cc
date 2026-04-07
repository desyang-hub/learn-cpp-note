#include <memory>
#include <iostream>

#include "../blockedQueue/BlockedQueue.h"

using namespace std;

// unique_ptr 独占所有权，不允许拷贝，只能移动
// shared_ptr 共享所有权，允许拷贝，进行拷贝后共享计数器值增加1，析构时减少1，最后一个shared_ptr释放，资源进行释放
// weak_ptr 监控shared_ptr，不拥有所有权，当需要用到时，可以获取一个shared_ptr副本(原子操作,线程安全)，但是shared_ptr本身时非线程安全的，在多线程下，需要自己处理多线程并发竞争逻辑




int main() {

    // 独占所有权
    std::unique_ptr<BlockedQueue<int>> blockedQueuePtr = std::make_unique<BlockedQueue<int>>();

    std::shared_ptr<BlockedQueue<int>> blockedQueueSharedPtr = std::make_shared<BlockedQueue<int>>();
    
    std::weak_ptr<BlockedQueue<int>> wkPtr = blockedQueueSharedPtr;
    if (auto bqsPtr = wkPtr.lock()) {
        cout << bqsPtr.use_count() << endl;
    }



    return 0;
}