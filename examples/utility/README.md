# `<utility>` in C++17 — Complete Reference & Examples

## ✅ rvalue vs lvalue
- **lvalue**: has a stable memory location (e.g., variables).
- **rvalue**: temporary value that does not persist (e.g., `10`, `a + b`).

---

## ✅ 1. What `<utility>` Contains

The `<utility>` header provides essential low-level helpers for C++ template metaprogramming and value category handling.

### **1. `std::forward`**
Perfectly forwards arguments, preserving whether they are lvalues or rvalues.

### **2. `std::move`**
Converts an lvalue into an rvalue to enable move semantics.

### Other key utilities in `<utility>`:
- `std::swap`
- `std::pair`
- `std::make_pair`
- `std::move_if_noexcept`
- `std::exchange`
- `std::index_sequence`, `std::make_index_sequence`
- `std::rel_ops` (deprecated but still known)

---

## ✅ `std::forward` vs `std::move`

| Utility        | What It Does | When to Use |
|----------------|--------------|-------------|
| **`std::move`** | Forces value to rvalue | Moving from an object |
| **`std::forward`** | Perfectly forwards value preserving lvalue/rvalue category | Template-based forwarding |

---

## ✅ Example: Perfect Forwarding

```cpp
void print_ref(int& x) { std::cout << "lvalue: " << x << "\n"; }
void print_ref(int&& x) { std::cout << "rvalue: " << x << "\n"; }

template <typename T>
void wrapper(T&& val) {
    print_ref(std::forward<T>(val));  // perfect forwarding
}

int a = 10;
wrapper(a);  // lvalue
wrapper(20); // rvalue
```

---

## ✅ 3. How to Build

```bash
./run.sh
```

---

## ✅ 4. Why `<utility>` Matters

- Enables writing **high‑performance template code**
- Allows **perfect forwarding**
- Enables **move semantics**
- Provides **pair utilities**, **swapping**, and **sequence generation** used heavily in STL
- Critical for **modern C++ generic programming**

---

## ✅ 5. Recommended Use Cases

| Feature | Use Case |
|--------|----------|
| `std::forward` | Template-based API forwarding |
| `std::move` | Moving heavy objects |
| `std::swap` | Efficient swapping |
| `std::pair` | Lightweight key/value structures |
| `std::exchange` | Replace-and-return operations |
| `std::index_sequence` | Template metaprogramming helpers |
