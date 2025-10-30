#include "D.hpp"

int main() {
    int x = D::n;        // OK
    const int* p = &D::n;  // ✅ Needs storage → REQUIRES definition in D.cpp [Before C++ 17]
                           // ✅ OK — storage is available automatically [After C++ 17]
}
