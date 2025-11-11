#include <iostream>

using namespace std;
enum class Result { Success = 1, Fail = 0, Failure [[deprecated]] = Fail };

enum class City {
  Berlin = 0,
  NewYork = 1,
  Mumbai = 2,
  Bombay [[deprecated]] = Mumbai,
};

Result save_file(const std::string &path) { return Result::Failure; }
[[nodiscard]] Result save_file_attribute(const std::string &path) {
  return Result::Failure;
}

namespace [[deprecated]] Grammar {
void commentPlace(int place) {
  switch (place) {
  case 1:
    std::cout << "very ";
    [[fallthrough]];
  case 2:
    std::cout << "well\n";
    break;
  default:
    std::cout << "OK\n";
    break;
  }
}
} // namespace Grammar
namespace MyLib {
struct WebService {};
struct RestService {};
struct doc {
  const char *value;
};

// [[MyLib::WebService, MyLib::RestService, MyLib::doc("html")]] Before C++ 17
[[using MyLib: WebService, RestService, doc("html")]] // After C++ 17
void foo() {
  std::cout << "foo() called\n";
}

} // namespace MyLib
int main() {
  save_file("output.txt");
  auto tmp = save_file_attribute("output.txt");
  if (tmp == Result::Success) {

    std::cout << "Success !!" << std::endl;
  }

  Grammar::commentPlace(1);

  MyLib::foo();
}
