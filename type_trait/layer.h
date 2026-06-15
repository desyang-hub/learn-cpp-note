/**
 * @FilePath     : /learn-cpp-note/type_trait/layer.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-15 12:01:41
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-15 15:20:23
**/
#pragma once
#include <string>

/**
 * @brief Layer类，表示一个神经网络层
 * @tparam T 数据类型模板参数
 */
template <typename T>
class Layer
{
public:
    // 使用value_type作为类型别名，表示该层的数据类型
    using value_type = T;
public:
    /**
     * @brief 构造函数，初始化Layer对象
     * @param args 可变参数，用于初始化Layer对象
     */
    Layer(/* args */) = default;
    /**
     * @brief 析构函数，清理Layer对象资源
     */
    virtual ~Layer() = default;

    virtual std::string type() const = 0;
};
