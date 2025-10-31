#include <iostream>
/* An aggregate is a class, or a structure that has no user-declared
 * constructors, no private or protected non-static members, no base classes,
 * and no virtual functions. */

struct Data {
  std::string name = "NULL";
  double value = 111;
};

struct MoreData : Data {
  bool done = false;
  void print() const {
    std::cout << '[' << name << ',' << value << ',' << done << "]\n";
  }
};

template <typename T> struct Alpha {
  T x;
  T y;
};

template <typename T> struct PAlpha : Alpha<T> {
  bool critical = false;
  void print() const {
    std::cout << '[' << this->x << ',' << this->y << ',' << this->critical
              << "]\n";
  }
};

int main() {
  Data x{"Hamza", 6.77};
  Data x1{};

  MoreData y{{"Hamza", 6.77}, false};
  y.print();
  MoreData y1{{"Hamza"}, false};
  y1.print();

  // MoreData y{"test", 3.14, true};   //  C++14 ERROR C++ 17 OK
  // You had to manually write a constructor in C++ 14

  MoreData y2;
  y2.print();

  Alpha<float> a{2.4, 7.4};
  PAlpha<float> s{a, false};
  s.print();

  // How to check if some object is aggregate type
  std::cout << std::is_aggregate<decltype(s)>::value << std::endl;

  return 0;
}
