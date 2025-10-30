# C++17 Learning Repository

This repository is an open-source collection of **C++17 examples**, **chapter-wise practice code**, and supporting build files for learners who want structured, practical exposure to modern C++ (with a focus on C++17).

It is designed to help developers, students, and professionals understand C++17 features through **clean, minimal, and fully working examples**.

---

## ✅ **Repository Overview**
```
.
├── Cpp17TheCompleteGuide.pdf   # Reference book (if licensed)
├── cxx17                        # Additional C++17 utilities
├── examples                     # All chapter-wise examples
│   ├── ch2
│   ├── ch3
│   ├── ch4
│   ├── ch5
│   └── ch6
├── git-push.sh                  # Helper script
└── tree.txt                     # Auto-generated file list
```

Each chapter folder contains:
- **main.cpp** (or multiple cpp files)
- **CMakeLists.txt**
- **run.sh** (quick-run script)
- **build/** auto-generated directory

All examples follow modern CMake and work on Linux/macOS/Windows.

---

## 🎯 **Purpose of This Repository**
This repo aims to:
- Provide **practical demonstrations** of all major C++17 features.
- Serve as a **reference codebase** for beginners and experienced developers.
- Help learners run examples quickly without complex setups.
- Build a community-driven, accessible learning resource.

---

## 🚀 **Key C++17 Features Covered**
The examples in `examples/` demonstrate many C++17 improvements, including:

### **Core Language Features**
- `if` and `switch` initializers
- Structured bindings
- Inline variables
- Fold expressions
- constexpr enhancements
- UTF-8 character literals
- Class template argument deduction (CTAD)

### **Library Features**
- `std::optional`
- `std::variant`
- `std::any`
- `std::string_view`
- Parallel algorithms
- Filesystem library
- `std::shared_mutex` and threading examples

### **Examples in This Repo Include:**
- Multi-file projects (classes, headers, build system)
- Threading & concurrency
- constexpr lambdas
- static_assert improvements
- Practical small utilities built with C++17

---

## 📦 **How to Build & Run Examples**
Each example has its own `CMakeLists.txt` file.

### **1. Build all examples manually**
```bash
cd examples/ch2
mkdir build && cd build
cmake ..
make
./ecxx      # or example output binary
```

### **2. Use run.sh**
Most folders include `run.sh` for quick running:
```bash
./run.sh
```
This script builds & executes the sample.

---

## 🧩 Example: C++17 If-Initialization
```cpp
if (auto it = mp.find(key); it != mp.end()) {
    // use it
}
```

---

## 🤝 **How to Contribute**
Contributions are welcome! You can help by:
- Adding new examples
- Improving explanations or code comments
- Fixing bugs in existing examples
- Enhancing documentation

### Steps:
1. Fork the repository
2. Create a feature branch
3. Submit a pull request

---

## 📄 License
You are free to use, modify, and distribute this repository under the **MIT License** (or any license you choose — update this as required).

---

## ⭐ Support the Project
If this repository helps you learn C++17, consider giving it a **star**! It helps others discover it.

---

## 📬 Contact
If you have questions, suggestions, or requests, feel free to open an issue or submit a PR.

Happy Coding! 🚀