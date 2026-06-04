#include "Buffer.h"
#include <iostream>

int main() {
    Buffer buf;
    std::cout << "After construction: readable=" << buf.readableBytes() 
              << ", writable=" << buf.writableBytes() << std::endl;
    
    buf.append("Some data here");
    std::cout << "After append: readable=" << buf.readableBytes() 
              << ", writable=" << buf.writableBytes() << std::endl;
    
    return 0;
}
