# Linking

[Video](https://www.youtube.com/watch?v=H4s55GgAg0I&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=8)

- files are translation units, nothing more
- 1 source file == 1 obj file
- all files combined together can be built
- build is separated into 3 steps
    - pre-processing
    - compiling
    - linking

# What is Linking

**Primary focus**: _Find where each symbol and function is, and link them together_.
Translation Units cannot interact. If we split our program into multiple C++ files, we need to
somehow link them together. That is the primary purpose of the linker!

Even if you do not have any external functions, the application still needs to know the _entrypoint_ (typically the `main` function). Linking the main function is also done by Linker.

- Commenting out the function call which needs to be link can skip the linker error.
- But, commenting out any outer function which calls the symbol that needs to be linked won't fix the linking error (even if technically it is dead code). Because we _could_ use the outer function elsewhere, and hence the linker is obligated to link it. Thus causing the error.

```cpp
int Multiply(int a, int b) {
    Log("Inside Multiply()");
    return a * b;
}

manish@manish learnCpp % make all
rm -rf a.out
clang++ -Wall src/main.cpp
Undefined symbols for architecture arm64:
  "Log(char const*)", referenced from:
      Multiply(int, int) in main-a41ba1.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [build] Error 1

// We get a Linking Error: we cannot find the symbol Log(char const*), which is defined inside
// the Multiply() function. This error is produced even if we are not using Multiply().
```

- If we declare a function `static`, that means we only declare the function for that translation unit.
- And if we make that outer function static and then do not call it, _then_ we can bypass the linker error.

```cpp
static int Multiply(int a, int b) {
    Log("Inside Multiply()");
    return a * b;
}
 
// compiling src/main.cpp only (and not src/logger.cpp)
src/main.cpp:5:12: warning: unused function 'Multiply' [-Wunused-function]
// compilation is successful (no linking error), because of the `static` keyword!
```

Within a single file, duplicate definitions can be detected by the compiler itself.
However, if you move one duplicate definition to a different file, the linker comes into play.

Inadvertently adding duplicate definition into your code!

```cpp
// Inside the header file, we have the definition of the function Log()
// and we have included that header file at 2 places: once in src/main.cpp and once in src/logger.cpp

// building leads to the following error:
duplicate symbol 'Log(char const*)' in:
```

_Include_ statement is simply copy-pasting the header contents into the `.cpp` file. Of course, doing it twice means we have 2 definitions. 

How can we fix this? We only defined the function at one place and yet we got a duplicate linker error.

1. Mark the function `static`. The definition would be internal to the translation unit only and won't be visible to any other object file. This fixes the error.

2. Mark the function `inline`. This would take the function call and replace it with the function body. Thus, there would be no duplicate. (Heh? I think there would still be 2 _definitions_ right?)

3. Better/Recommended way: Move the Log definition into a different translation unit (either one of the existing, or make a new one). 

At the end of the day, the linker takes in all the object files, and/or all the libraries (C runtime library, STL, platform APIs etc) and link them all together.

# Static vs Dynamic Linking

Linking is of 2 types: static and dynamic. We will know about them later. :-)

# Rule:

- ODR: One Definition Rule.
We need to define functions only _once_.
