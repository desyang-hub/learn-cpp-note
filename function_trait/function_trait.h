/**
 * @FilePath     : /learn-cpp-note/function_trait/function_trait.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-18 10:34:44
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-18 11:32:05
**/
#pragma once

// 函数萃取器本质上是对类的特化，因此需要定义一个模板类，并对其进行特化

template<class T>
struct function_trait;

// 普通函数 本质上是一个指针
template<class Result, class... Args>
struct function_trait<Result(*)(Args...)> {
    using return_type = Result;
    using tuple_args_type = std::tuple<Args...>;
    constexpr static bool is_member_function = false;
    constexpr static bool is_single_argument = sizeof...(Args) == 1;
};

// 类成员函数指针
template<class Result, class Class, class... Args>
struct function_trait<Result(Class::*)(Args...)> {
    using return_type = Result;
    using tuple_args_type = std::tuple<Args...>;
    constexpr static bool is_member_function = false;
    constexpr static bool is_single_argument = sizeof...(Args) == 1;
};

// 类常成员函数指针
template<class Result, class Class, class... Args>
struct function_trait<Result(Class::*)(Args...) const> {
    using return_type = Result;
    using tuple_args_type = std::tuple<Args...>;
    constexpr static bool is_member_function = true;
    constexpr static bool is_single_argument = sizeof...(Args) == 1;
};

// lambda 函数, 本质上LambdaFunctor是一个类，其operator()是一个成员函数，所以当用户传入一个lambda函数时，实际上传入的是一个LambdaFunctor类型的对象，只需要将该类型的operator()函数进行特化即可
template<class LambdaFunctor>
struct function_trait : 
    public function_trait<decltype(&LambdaFunctor::operator())> {
};