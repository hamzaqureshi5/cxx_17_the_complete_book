#include <functional>
#include <iostream>
#include <string>

// -------------------- Structs and Functors --------------------
struct A {
  int mult(int x) { return x * 10; }
  int add(int x, int y) { return x + y; }
};

struct Functor {
  int operator()(int x) const { return x * x; }
};

// Free function
int freeFunc(int x) { return x + 1; }

// Predicate function
bool isEven(int x) { return x % 2 == 0; }

int main() {
  A obj;

  std::cout << "=== std::invoke Examples ===\n";
  std::cout << "invoke freeFunc: " << std::invoke(freeFunc, 5) << "\n";
  std::cout << "invoke member mult: " << std::invoke(&A::mult, obj, 3) << "\n";

  auto lambda = [](int x) { return x * 2; };
  std::cout << "invoke lambda: " << std::invoke(lambda, 4) << "\n";

  Functor f;
  std::cout << "invoke functor: " << std::invoke(f, 6) << "\n\n";

  std::cout << "=== std::function Examples ===\n";
  std::function<int(int)> func1 = freeFunc;
  std::function<int(int)> func2 = lambda;
  std::function<int(int)> func3 = f;
  std::cout << "std::function freeFunc: " << func1(5) << "\n";
  std::cout << "std::function lambda: " << func2(5) << "\n";
  std::cout << "std::function functor: " << func3(5) << "\n\n";

  std::cout << "=== std::bind Examples ===\n";
  auto boundFree = std::bind(freeFunc, std::placeholders::_1);
  std::cout << "bind freeFunc: " << boundFree(10) << "\n";

  auto boundMember = std::bind(&A::add, &obj, std::placeholders::_1, 125);
  std::cout << "bind member add: " << boundMember(2, 3) << "\n\n";

  std::cout << "=== std::ref / std::cref Examples ===\n";
  int x = 10;
  auto add_ref = [&](int y) { return x += y; };
  std::function<int(int)> refCall = std::ref(add_ref);
  std::cout << "ref call: " << refCall(5) << "\n";
  std::cout << "x after ref: " << x << "\n\n";

  std::cout << "=== std::not_fn Example ===\n";
  auto isOdd = std::not_fn(isEven);
  std::cout << "isOdd(7): " << isOdd(7) << "\n\n";

  std::cout << "=== Arithmetic, Comparison, Logical Functors ===\n";
  std::plus<int> plus;
  std::multiplies<int> mult;
  std::logical_and<bool> land;
  std::less<int> less;
  std::cout << "plus(3,4): " << plus(3, 4) << "\n";
  std::cout << "mult(3,5): " << mult(3, 5) << "\n";
  std::cout << "land(true,false): " << land(true, false) << "\n";
  std::cout << "less(2,5): " << less(2, 5) << "\n\n";

  std::cout << "=== std::hash Example ===\n";
  std::hash<std::string> h;
  std::cout << "Hash of 'Object1': " << h("Object1") << "\n";
  std::cout << "Hash of 'Object2': " << h("Object2") << "\n";
  std::cout << "Hash of 'Object3': " << h("Object3") << "\n";
  std::cout << "Hash of 'Object3': " << h("Object3") << "\n";

  return 0;
}
