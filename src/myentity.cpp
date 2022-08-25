#include <iostream>

class MyEntity
{
public:
    float X, Y; // no default value provided

    // ctor has no return type. In languages like Java, primitive types are automatically set to 0
    // this is **not** the case with C++. We get whatever is in place at the memory.
    MyEntity() {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity" << std::endl;
    }

    MyEntity(float x, float y)
    {
        X = x;
        Y = y;
    }

    ~MyEntity()
    {
        // nothing to de-allocate from the heap
        std::cout << "Destroyed Entity" << std::endl;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

/**
 * We won't be able to create instances of the following class
 */
class HideMyDefaultConstructor
{
private:
    HideMyDefaultConstructor() {};
public:
    static void SomeStaticMethod() {
        std::cout << "This is a static method call" << std::endl;
    }
};

// 2nd strategy: tell C++ that we don't want a default constructor
class NoDefaultCTor
{
public:
    NoDefaultCTor() = delete;
};

void UseEntityClass() 
{
    MyEntity e(10.0f, 5.0f);
    e.Print();
    HideMyDefaultConstructor::SomeStaticMethod();
    // HideMyDefaultConstructor foo;
    // NoDefaultCTor foo;
    // Objects created on the stack automatically get destroyed when they go out of scope.
    // It's why ~MyEntity destructor gets called when we exit this method call.
    // Destructors are used to clean up allocations, especially heap-allocations.
}