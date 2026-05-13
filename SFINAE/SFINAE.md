# SFINAE (Substitution Failure Is Not An Error)

> 中文常译为：“**替换失败不是错误**”

---

### 🔍 什么是 SFINAE？

在 C++ 模板重载解析（overload resolution）过程中：

- 编译器会尝试将模板参数代入函数模板或类模板。
- 如果**代入导致类型不合法**（比如某个类型没有 `::value_type`），**这不会直接导致编译错误**。
- 而是**简单地将这个模板从候选集中移除**。
- 只要还有至少一个合法的候选，程序就正常编译。

> 💡 这就是“**不能存在也不报错**”的核心机制：**无效的模板实例不会报错，只是被忽略**。

---

### 🧪 举个经典例子

```cpp
template<typename T>
void foo(typename T::value_type*);   // #1

template<typename T>
void foo(T*);                        // #2

struct A { using value_type = int; };
struct B {};

int main() {
    foo<A>(nullptr); // 调用 #1（A 有 value_type）
    foo<B>(nullptr); // 调用 #2（B 没有 value_type → #1 被 SFINAE 排除，不报错！）
}
```

- 对 `B` 调用 `foo` 时，`#1` 的 `typename T::value_type` 无效。
- 但因为 SFINAE，**不会报错**，而是选择 `#2`。
- 如果没有 `#2`，才会报错（因为无可用重载）。

---

### 🛠 SFINAE 的常见用途

1. **条件性启用函数模板**（C++11/14 时代常用）
   ```cpp
   template<typename T>
   typename std::enable_if<std::is_integral<T>::value>::type
   func(T t) { /* 只接受整数类型 */ }
   ```

2. **类型特征检测**（如检测是否有某成员函数）

3. **实现 `std::void_t`、`std::declval` 等工具的基础**

> ⚠️ 注意：C++20 引入了 **Concepts**，很大程度上替代了手动 SFINAE，代码更清晰。

---

### ❌ 不是“延迟实例化”或“两阶段查找”

虽然 C++ 模板还有其他特性（如：
- **延迟实例化（Lazy Instantiation）**：模板只在使用时才实例化
- **两阶段查找（Two-phase lookup）**：名字查找分定义时和实例化时

但这些**不会导致“无效模板不报错”**，只有 **SFINAE** 明确描述了“**替换失败不算错，只是排除候选**”的行为。

---

### ✅ 总结

| 问题描述 | 正确术语 |
|--------|--------|
| “模板中某些无效写法不报错，只是被忽略” | **SFINAE**（Substitution Failure Is Not An Error） |

这是 C++ 模板元编程的核心机制之一。