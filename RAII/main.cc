#include "String.h"
#include "FILEGuarder.h"

#include <iostream>
#include <memory>

using namespace std;
using namespace RAII;

int main() {

    String str("desyang");

    std::cout << str << std::endl;

    std::unique_ptr<FILE, FILEGuarder> f(fopen("app.log", "w"));



    return 0;
}