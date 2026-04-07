## 自旋锁与互斥锁

自旋锁避免上下文切换开销但浪费CPU周期，互斥锁节省CPU资源但引入切换开销。
临界区大小：短临界区适合自旋锁，长临界区适合互斥锁


### 自旋锁

特性概括：通过循环忙等待获取锁，不会进行上下文切换（一直持有cpu），适用于锁持有时间短的场景。

适用场景：极短临界区 - 锁持有时间小于两次上下文切换开销

### 互斥锁(mutex)



通过系统调用实现阻塞

特性概括：通过系统来进行调度，等待锁释放时会进行上下文切换(线程进入休眠，不占用cpu)，适用于锁持有时间长的场景。【用户态与内核态之间的状态变换开销大，系统调度会产生延迟，不适用于实时性要求高的系统】

适用场景：长临界区 - 锁持有时间大于两次上下文切换开销

### 自旋锁与互斥锁的优缺点

自旋锁：

优点：

- 不会进行上下文切换，开销小

缺点：

- 锁持有时间过长，会导致cpu空转，浪费cpu资源

互斥锁：

优点：



### c++ 锁的最佳实践

| 特性 | 纯内部锁 | 纯外部锁 | 混合模式 (你描述的) |
| :--- | :--- | :--- | :--- |
| 锁的管理 | 类内部，不透明 | 使用者，完全自由 | 类提供，使用者管理 |
| 灵活性 | 低 | 高 | 非常高 |
| 便利性 | 高 | 低 | 高 |
| 复合操作安全 | 不安全 | 安全 | 安全 |

这种混合模式是 C++ 中一种非常成熟和推荐的设计实践，它完美地体现了 C++“信任程序员”和“不为不需要的功能付出代价”的哲学。

样例程序
```cpp

#include <iostream>
#include <mutex>
#include <thread>

class BankAccount {
private:
    int balance_;
    // 1. 提供一个 mutable mutex，即使是在 const 成员函数中也能加锁
    mutable std::mutex mtx_; 

public:
    BankAccount(int initial_balance) : balance_(initial_balance) {}

    // 2. 提供一个公有方法，让外部可以获取到这个锁
    // 返回引用，确保所有线程操作的是同一个 mutex 对象
    std::mutex& getMutex() { 
        return mtx_; 
    }

    // 3. 类内部的方法不加锁，保持轻量级
    void deposit(int amount) { 
        balance_ += amount; 
    }
    
    int getBalance() const { 
        return balance_; 
    }
};

// --- 使用场景 ---

BankAccount account(100);

// 场景A：用户决定对复合操作加锁
void transfer_money(BankAccount& acc, int amount) {
    // 用户自己决定锁的范围，覆盖整个复合操作
    std::lock_guard<std::mutex> lock(acc.getMutex());
    
    int current_balance = acc.getBalance();
    // 模拟一些处理...
    acc.deposit(amount);
    // 整个操作是原子的
}

// 场景B：用户决定只保护单个操作
void check_balance(const BankAccount& acc) {
    // 用户也可以只为一次读取操作加锁
    std::lock_guard<std::mutex> lock(acc.getMutex());
    std::cout << "当前余额: " << acc.getBalance() << std::endl;
}

// 场景C：用户认为在某些情况下不需要锁（例如，单线程初始化阶段）
void init_account(BankAccount& acc) {
    // 用户自己决定，这里不加锁，直接操作
    acc.deposit(500);
}
```