// D.cpp
#include "D.hpp"

constexpr int D::n;  // ✅ REQUIRED definition (provides storage) 


// AFTER C++ 17 constexpr supports inline 

// constexpr int D::n; is not required , if defined here, this will be depreciated, and still works