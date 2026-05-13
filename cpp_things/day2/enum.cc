#include <iostream>
#include <string>
#include <stdexcept>

// ===== 定义枚举和字符串的统一源（X-Macro）=====
#define COLOR_VALUES \
    X(RED)          \
    X(BLUE)         \
    X(GREEN)

// 生成 enum
enum Color {
#define X(name) name,
    COLOR_VALUES
#undef X
};

// 生成 toString
std::string toString(Color e) {
    switch (e) {
#define X(name) case name: return #name;
        COLOR_VALUES
#undef X
        default:
            throw std::invalid_argument("Invalid Color");
    }
}

// ===== 使用 =====
int main() {
    std::cout << toString(RED) << "\n";
    std::cout << toString(BLUE) << "\n";
    std::cout << toString(GREEN) << "\n";
    return 0;
}