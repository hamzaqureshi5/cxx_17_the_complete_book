#include "MyClass.hpp"
#include <iostream>

void f2() {
    std::cout << "Name = " << MyClass::name << "\n";
    std::cout << "Counter = " << globalCounter << "\n";
}
