# `<functional>` in C++17 --- Complete Reference & Examples

This repository provides a practical walkthrough of the **C++17
`<functional>` library**, including its utilities for invoking
callables, binding parameters, wrapping functions, negating predicates,
hashing, and using standard function objects.

`<functional>` is one of the most powerful standard headers in modern
C++, enabling flexible functional-style programming, generic
programming, and type-erased callable handling.

------------------------------------------------------------------------

## ✅ **1. What `<functional>` Contains**

`<functional>` provides several major categories of utilities:

### **1. Callable Invocation Utilities**

-   `std::invoke`\
-   `std::invoke_result`, `std::invoke_result_t`
-   Traits:
    -   `std::is_invocable`\
    -   `std::is_invocable_r`\
    -   `std::is_nothrow_invocable`\
    -   `std::is_nothrow_invocable_r`

### **2. Function Wrapper**

-   `std::function`

### **3. Reference Wrappers**

-   `std::reference_wrapper`
-   `std::ref`, `std::cref`

### **4. Bind Utilities**

-   `std::bind`
-   Traits: `std::is_bind_expression`, `std::is_placeholder`
-   Placeholders:
    -   `std::placeholders::_1`, `_2`, etc.

### **5. Predicate Negator**

-   `std::not_fn`

### **6. Arithmetic Functors**

-   `std::plus`, `std::minus`, `std::multiplies`, `std::divides`,
    `std::modulus`, `std::negate`

### **7. Comparison Functors**

-   `std::equal_to`, `std::not_equal_to`,\
    `std::greater`, `std::less`,\
    `std::greater_equal`, `std::less_equal`

### **8. Logical Functors**

-   `std::logical_and`, `std::logical_or`, `std::logical_not`

### **9. Bitwise Functors**

-   `std::bit_and`, `std::bit_or`, `std::bit_xor`, `std::bit_not`

### **10. Hashing Utility**

-   `std::hash<T>`

------------------------------------------------------------------------

## ✅ **2. C++17 Example Using All Features**

``` cpp
#include <iostream>
#include <functional>

struct A {
    int mult(int x) { return x * 10; }
    int add(int x, int y) { return x + y; }
};

struct Functor {
    int operator()(int x) const { return x * x; }
};

int freeFunc(int x) {
    return x + 1;
}

bool isEven(int x) {
    return x % 2 == 0;
}

int main() {
    A obj;

    std::cout << "invoke freeFunc: "
              << std::invoke(freeFunc, 5) << "\n";

    std::cout << "invoke member mult: "
              << std::invoke(&A::mult, obj, 3) << "\n";

    auto lambda = [](int x) { return x * 2; };
    std::cout << "invoke lambda: "
              << std::invoke(lambda, 4) << "\n";

    Functor f;
    std::cout << "invoke functor: "
              << std::invoke(f, 6) << "\n";

    std::function<int(int)> func1 = freeFunc;
    std::function<int(int)> func2 = lambda;
    std::function<int(int)> func3 = f;

    std::cout << "std::function freeFunc: " << func1(5) << "\n";
    std::cout << "std::function lambda: "   << func2(5) << "\n";
    std::cout << "std::function functor: "  << func3(5) << "\n";

    auto boundFree = std::bind(freeFunc, std::placeholders::_1);
    std::cout << "bind freeFunc: " << boundFree(10) << "\n";

    auto boundMember =
        std::bind(&A::add, &obj, std::placeholders::_1, std::placeholders::_2);
    std::cout << "bind member add: " << boundMember(2, 3) << "\n";

    int x = 10;
    auto add_ref = [&](int y) { return x += y; };

    std::function<int(int)> refCall = std::ref(add_ref);
    std::cout << "ref call: " << refCall(5) << "\n";
    std::cout << "x after ref: " << x << "\n";

    auto isOdd = std::not_fn(isEven);
    std::cout << "isOdd(7): " << isOdd(7) << "\n";

    return 0;
}
```

------------------------------------------------------------------------

## ✅ **3. How to Build**

``` bash
g++ -std=c++17 example.cpp -o example
./example
```

------------------------------------------------------------------------

## ✅ **4. Why `<functional>` Matters**

-   Enables **generic design** of APIs\
-   Supports **callbacks and event systems**\
-   Used in **STL algorithms**\
-   Useful in **multithreading**, **task scheduling**, **function
    dispatchers**\
-   Provides **type-erased callable storage** (`std::function`)\
-   Allows **uniform invocation** (`std::invoke`)

------------------------------------------------------------------------

## ✅ **5. Recommended Use Cases**

  Feature           When to Use
  ----------------- ------------------------------------------
  `std::invoke`     Calling any callable uniformly
  `std::function`   Storing callbacks, polymorphic callables
  `std::bind`       Partially applying arguments
  `std::ref`        Passing references safely
  `std::not_fn`     Predicate negation for STL algorithms
  `std::hash`       Custom hashing in unordered containers
