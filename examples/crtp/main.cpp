#include <iostream>
using namespace std;

template <typename T> class CRTP_Base {
public:
  void call() {
    // Call function from Derived
    static_cast<T *>(this)->FunctionCall();
  }
};

class CRTP_Derived : public CRTP_Base<CRTP_Derived> {
public:
  void FunctionCall() { cout << "CRTP Function call from Derived\n"; }
};

// WITHOUT CRTP

// class NO_CRTP_Base {
// public:
//   virtual void sayHello() { cout << "Base Class Function call\n"; }

//   void call() {
//     sayHello(); // runtime dispatch (vtable)
//   }

//   virtual ~NO_CRTP_Base() {}
// };

// class NO_CRTP_Derived : public NO_CRTP_Base {
// public:
//   void sayHello() override { cout << "Derived Class Function call\n"; }
// };

int main() {
  // WITH CRTP
  CRTP_Derived d;
  d.call(); // Calls Derived::FunctionCall()

  // WITHOUT CRTP
  // NO_CRTP_Base *obj = new NO_CRTP_Derived();
  // obj->call(); // resolved at runtime
  // delete obj;
}