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

## ✅ **3. How to Build**

``` bash
./run.sh
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
