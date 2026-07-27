#include "Observer.h"

#include <iostream>

void observer_demo() {
    Observer observer;

    observer.subject([](Observer* obs){
        std::cout << "notify xiaoming" << std::endl;
    });

    observer.subject([](Observer* obs){
        std::cout << "notify xiaoli" << std::endl;
    });


    observer.Notify();
}