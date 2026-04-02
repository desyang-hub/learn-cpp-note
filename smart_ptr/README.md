1. unique_ptr如何实现不可拷贝但可移动？
声明拷贝构造和拷贝赋值函数为delete，同时提供移动构造和移动赋值函数的实现。

2. shared_ptr的引用计数如何工作？它是线程安全的吗？
shared_ptr通过应用计数来管理对象的声明周期，当发生对象的拷贝时，引用计数+1，当对象被销毁时引用计数-1，当最后一个shared_ptr被销毁时，引用计数为0，执行析构函数销毁对象。shared_ptr的引用计数是线程安全的，因为它的操作都是原子操作。

3. 循环引用场景（比如两个类互相持有shared_ptr）及解决方法。
两个对象互相持有对方的shared_ptr，会导致引用计数无法归零，从而无法销毁对象。解决方法是通过weak_ptr来解决循环引用问题，weak_ptr不会增加引用计数，当最后一个shared_ptr被销毁时，weak_ptr会变成空指针。
可以将weak_ptr当成是一个观察者，只有当需要时，且观察对象存在时，才使用weak_ptr来访问对象。不增加引用计数，从而打破循环引用。

4. 如何自定义删除器（比如管理FILE*）？
可以通过重载shared_ptr的删除器函数来实现自定义删除器。例如：

```cpp
#include <memory>
#include <iostream>
#include <cstdio>

using namespace std;
int main() {
    auto fileCloser = [](FILE* f) { 
        std::cout << "close" << std::endl;
        fclose(f); };
    std::unique_ptr<FILE, decltype(fileCloser)> filePtr(fopen("test.txt", "w"), fileCloser);

    return 0;
}
```

在上面的例子中，我们使用lambda表达式作为删除器，当filePtr被销毁时，会调用lambda表达式来关闭文件。