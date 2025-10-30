#include "MyClass.hpp"
#include <iostream>

void f1() {
    MyClass::name = "changed in f1";
    globalCounter++;
}
