#include <iostream>



// 1. Nested Namespaces
// Proposed in 2003 for the first time, the C++ standard committee finally accepted to define nested namespaces as follows:
namespace A::B::C {

// CODE HERE
}
// which is equivalent to:
namespace A {
namespace B {
namespace C {

// CODE HERE

}
}
}
int main() {
  return 0;
}
