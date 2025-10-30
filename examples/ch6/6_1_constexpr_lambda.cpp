#include <iostream>
#include <vector>
using namespace std;

#define DEBUG_MODE 1
#define PRINT(x)                                                               \
  do {                                                                         \
    if (DEBUG_MODE) {                                                          \
      std::cout << x << std::endl;                                             \
    }                                                                          \
  } while (0)

#include <array>
#include <iostream>

constexpr auto squared = [](int val) constexpr -> int { return val * val; };

int main() {
  // In C++14 you must explicitly mark it constexpr

  // Use in compile-time context:
  std::array<int, squared(5)> arr; // size 25

  std::cout << arr.size() << "\n"; // Prints 25
}
