# Learning C++ - 30th June, 2022

1. Pre-processors
2. Compilation
3. Linking
4. Static keyword (to prevent duplicate linker errors)
5. Missing symbol linker error and how to fix that
6. Extern keyword and how to use that to look up a symbol outside the translation unit.
7. ODR (One Definition Rule)
8. Declaration vs Definition and when to use which
9. C++ header files and #pragma once, #ifdef guards
10. Basics of C++ structs and classes
11. static keyword inside C++ classes
12. Class definition in header files + implementation in .cpp files
13. #include to do full text substitution.
14. Virtual methods (to do dynamic dispatch) to override subclass methods (also the `override` keyword)
15. Basics of class Inheritance
16. Simple Constructor and Destructor in C++ classes
17. Class visibility (private and public).
18. How to disable regular object construction (making ctor private or marking as delete)
19. Revision of pointers (what they represent in memory and how the type information is used (or rather not used).
20. References in C++.
21. Member variable naming convention.
22. Enums inside classes and their naming convention.
23. C++ constructor initializer list.
24. Pure virtual functions (aka interfaces in C++)
25. Stack-allocated arrays and basics of Heap-allocation/dealloc of arrays using `new` and `delete`.
26. `sizeof(array) / sizeof(type)` trick that only works with stack-allocated arrays.
27. `std::array<type, size>` which is safer and does bound-checking (perf impact?)
28. [] array indexing - directly and via pointers (both typed and byte-based using char* casting)
    int* ptr = new int[5];
    *(type*)((char*) ptr + (sizeof(type) * offset)) = type_value;
29. 


## Expertly Written C++17/C++20 repositories and their functions

1. lvalue references
2. Constructors, Destructors and Inheritance
3. Annotations, such as `const` and `noexcept` on members.
4. Simple type templates and value templates.
5. constexpr, std::move and rvalue references.
6. Type traits and std::enable_if
7. Concepts