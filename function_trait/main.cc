#include <iostream>
#include <tuple>
#include <stddef.h>
#include "Service.h"



int main(int argc, char const *argv[])
{
    
    Service::Proxy serviceProxy;
    serviceProxy.func(1, 2.5, "hhhhhh");


    return 0;
}
