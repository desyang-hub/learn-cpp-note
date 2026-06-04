#include "Buffer.h"
#include <iostream>

int main() {
    Buffer buf;
    buf.append("First part");
    std::cout << "After 'First part': readable=" << buf.readableBytes() << std::endl;
    
    buf.append("Second part");
    std::cout << "After 'Second part': readable=" << buf.readableBytes() << std::endl;
    
    buf.append("Third part");
    std::cout << "After 'Third part': readable=" << buf.readableBytes() << std::endl;
    
    return 0;
}
