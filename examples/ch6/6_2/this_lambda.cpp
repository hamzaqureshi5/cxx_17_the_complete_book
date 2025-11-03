
#include <iostream>
#include <string>

using namespace std;

class Data {
private:
  std::string name;
  int value;

public:
  Data(std::string n, int v) : name(n), value(v) {}

  void demonstrateCaptures() {
    // 1. Capture 'this' pointer explicitly
    auto l_this = [this] {
      std::cout << "[this] name: " << name << ", value: " << value << '\n';
    };

    // 2. Capture all local variables by value (including 'this' pointer)
    auto l_value = [=] {
      std::cout << "[=] name: " << name << ", value: " << value << '\n';
    };

    // 3. Capture all local variables by reference
    auto l_ref = [&] {
      std::cout << "[&] name: " << name << ", value: " << value << '\n';
    };

    // 4. Capture 'this' + some locals explicitly by value
    int localVar = 42;
    auto l_value_this = [=, this] {
      std::cout << "[=, this] localVar: " << localVar << ", name: " << name
                << '\n';
    };

    // 5. Capture 'this' + some locals by reference
    auto l_ref_this = [&, this] {
      std::cout << "[&, this] localVar: " << localVar << ", value: " << value
                << '\n';
    };

    // Call all lambdas
    l_this();
    l_value();
    l_ref();
    l_value_this();
    l_ref_this();
  }
};

int main() {
  Data D("Hamza", 10);
  D.demonstrateCaptures();
  return 0;
}
