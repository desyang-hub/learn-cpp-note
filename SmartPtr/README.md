## 智能指针unique_ptr, shared_ptr, weak_ptr

### unique_ptr

unique_ptr是独占所有权的智能指针，即同一时间内只能有一个unique_ptr指向一个对象，当unique_ptr被销毁时，它所指向的对象也会被销毁。

unique_ptr的创建方式如下：

```c++
unique_ptr<int> p1(new int(10)); // 创建一个指向int类型对象的unique_ptr



