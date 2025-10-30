#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <string>

class MyClass {
public:
    static inline std::string name = "default";   // ✅ single global instance
};

inline int globalCounter = 0;   // ✅ also allowed
#endif
