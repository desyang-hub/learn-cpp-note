#include "Buffer.h"
#include <iostream>

int main() {
    Buffer buf;
    
    const size_t dataSize = 1024 * 1024; // 1MB
    std::vector<char> largeData(dataSize, 'L');
    
    std::cout << "Appending 1MB..." << std::endl;
    buf.append(&largeData[0], dataSize);
    std::cout << "Readable after append: " << buf.readableBytes() << std::endl;
    
    std::string retrieved = buf.retrieveAllAsString();
    std::cout << "Retrieved size: " << retrieved.size() << std::endl;
    
    return 0;
}
