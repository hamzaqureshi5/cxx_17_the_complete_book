
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Data {
private:
  std::string name;
  int value;

public:
  Data(std::string n, int v) : name(n), value(v) {}

  void demonstrateCaptures() {
    // 0. Capture 'this' pointer as const vars
    auto l_c = [nc = std::as_const(name), vc = std::as_const(value)] {
      std::cout << "[const] name: " << nc << ", value: " << vc << '\n';
    };

    // Call all lambdas
    l_c();
  }
};

int main() {
  std::vector<int> col1{1, 2, 3, 4};

  auto print = [&const_col = std::as_const(col1)] {
    std::cout << "coll: ";
    for (int elem : const_col) {
      std::cout << elem << ' ';
    }
    std::cout << '\n';
  };

  print();

  Data D("Hamza", 10);
  D.demonstrateCaptures();
  return 0;
}
