#include <iostream>
#include <array>

void UnderstandingArrays()
{
    // what is the correct syntax to create arrays in C++?
    // <type> <variable>[size]
    int example[5];
    // how to index items from this array?
    example[0] = 2;
    example[4] = 4;

    std::cout << example[2] << std::endl; // print an element
    std::cout << example << std::endl; // this will just print the memory address of this array
    // this is because `example` is just a pointer type
    // example[-1]; // this will cause a memory access violation. Be careful.

    // a for loop is a really good way to set items in the array
    for (int i = 0; i < 5; ++i) {
        example[i] = 5;
    }
    std::cout << example[2] << std::endl;
    // arrays store their data contiguously (in a row) in the memory
    // each int is 4 bytes, len of array = 5, this means we allocate 4 * 5 = 20 bytes in memory contiguously.
    // access to a specific index essentially just offsets from addr at the beginning of array
    int* ptr = example;
    example[2] = 10;
    std::cout << example[2] << std::endl;
    *(ptr + 2) = 6; // lhs here is the same as example[2] 
    // +2 works here because ptr has type int, so it will add 2 * sizeof(int) bytes to our starting offset.
    std::cout << example[2] << std::endl;
    // If you want to deal with raw bytes, cast the pointer as char, and deal with the size-based offset yourself
    *(int*)((char*) ptr + 8) = 21;
    std::cout << example[2] << std::endl;
}

// we can also create arrays using the new keyword (just like class instances)
void ArraysUsingNew()
{
    int example[5];
    int* another = new int[5];      // same as the line above, just with a different "lifetime". This is Created on the heap.

    for (size_t i = 0; i < 5; i++) {
        example[i] = 2;
        another[i] = 22;
    } 
    for (size_t i = 0; i < 5; i++)
        std::cout << example[i] << " ";
    for (size_t i = 0; i < 5; i++)
        std::cout << another[i] << " ";
    std::cout << std::endl;
    // example array would be automatically deallocated when we go out of the scope
    // but we have to manually deallocate the another array from the heap using the delete keyword.
    delete[] another;

    // So why would you allocate dynamically on the heap rather than the stack?
    // Biggest reason: Lifetimes.
    // If you have a function returning a new array, you *have* to allocate (unless you pass in the memory addr or something)
    // Another reason: Memory indirection
}

class Box
{
public:
    int example[5];
    Box() {
        for (size_t i = 0; i < 5; i++)
            example[i] = 2;
    }
};

class IndirectAlloc
{
public:
    int* example = new int[5];
    IndirectAlloc() {
        for (size_t i = 0; i < 5; i++)
            example[i] = 2;
    }
};

void ExamineClassArray()
{
    Box b; // example[5] is allocated right where the address of b lives in memory.
    IndirectAlloc a;    // a's memory does not contain the example array, just the addr. array lives elsewhere in mem.
}

void ArraySize()
{
    // This is because there is no real way to keep track of the size of the raw array in C++ (which isn't compiler dependent)
    // You cannot trust that, since it is dangerous.
    int a[5];
    sizeof(a); // this will return size of array in bytes. NOT the number of bytes.
    sizeof(a) / sizeof(int); // this will divide total bytes by a single byte of same type, thus returning the number of elements.
    std::cout << "array a has size = " << sizeof(a) / sizeof(int) << std::endl;

    // THIS IS NOT SOMETHING YOU WANT TO USE! WHY?
    // Lets say our array is being pointed to by an int*
    int* b = new int[5];
    std::cout << "Is this correct??? array b has size = " << sizeof(b) / sizeof(int) << std::endl;
    // This is obviously *NOT* correct, because sizeof(b) returns the size of the int*, not the total size of bytes in array.
    // So, sizeof(arr) / sizeof(type) trick only works with stack-allocated array.
    // Instead, just maintain the size by yourself. It sucks, but just do it.
    // Hint: use `const int size = 5` in your class. or `static const int size = 5`
    // Or `constexpr` but that's for another day.
}

// C++11 has std::array which is a standard data structure
// This keeps track of the size of the array and includes bound checking
void StdArray()
{
    std::array<int, 5> my_array;
    for (size_t i = 0; i < my_array.size(); i++)
        my_array[i] = 10;

    for (size_t i = 0; i < my_array.size(); i++)
        std::cout << my_array[i] << " ";

    std::cout << std::endl;
}