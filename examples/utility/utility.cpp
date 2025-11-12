
#include <iostream>
#include <utility>

template <typename T> class Box {
public:
  T value;
  template <typename U> Box(U &&v) : value(std::forward<U>(v)) {}  
  //  Box(T &&v) : value(std::forward<T>(v)) {} // perfect forwarding [Only for R Values]
};

void print_ref(int &x) {
  std::cout << "======> lvalue: " << x << "\n";
} // L Value as Argument

void print_ref(int &&x) {
  std::cout << "======> rvalue: " << x << "\n";
} // R Value as Argument

template <typename T> void wrapper(T &&val) {
  print_ref(std::forward<T>(val)); // perfect forwarding
}

int main() {

  int LVALUE = 10;              
  Box<int> B1(10);          // OK, rvalue → int&&
  Box<int> B2(LVALUE);

  wrapper(LVALUE); // prints "lvalue: 10"
  wrapper(20);     // prints "rvalue: 20"
}
