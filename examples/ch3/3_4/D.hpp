// D.hpp
// struct D {
//     static constexpr int n = 5;  // ✅ Declaration ONLY (no storage) Before C++ 17
// };


struct D {
    static constexpr int n = 5;  // ✅ After C++ 17 Definition, and implicitly inline
};
