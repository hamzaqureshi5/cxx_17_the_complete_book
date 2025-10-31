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

auto squared = [](int val) constexpr -> int { return val * val; };
auto times2 = [](auto val) constexpr -> auto {
  static_assert(std::is_arithmetic_v<decltype(val)>,
                "times2 only supports arithmetic types");
  return val * 2;
};
auto times3 = [](auto val) constexpr -> auto {
  static_assert(std::is_arithmetic_v<decltype(val)>,
                "times3 only supports arithmetic types");
  return val * 3;
};

int main() {
  constexpr float half = 0.5;
  constexpr float full = 1.0;
  // In C++14 you must explicitly mark it constexpr
  static_assert(times3(half) > full, "Dammnnn!!");
  // Use in compile-time context:
  // std::array<int, squared(5)> arr; // size 25

  /// std::cout << arr.size() << "\n"; // Prints 25
}
