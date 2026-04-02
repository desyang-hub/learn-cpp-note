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