#include "Buffer.h"
#include <iostream>

int main() {
    Buffer buf;
    
    buf.append(std::string("String"));
    buf.append("CharPtr", 8);
    buf.append("Another");
    
    std::string result = buf.retrieveAllAsString();
    std::cout << "Result: '" << result << "'" << std::endl;
    std::cout << "Length: " << result.size() << std::endl;
    
    return 0;
}
