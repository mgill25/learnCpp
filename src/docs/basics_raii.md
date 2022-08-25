# Back to basics - C++ RAII (Resource Allocation Is Initialization)

A _resource_ for our purpose, is anything that requires special (manual) management:
C++ programs can manage different kinds of _resources_

- allocated memory (`malloc/free`, `new/delete`, `new[]/delete[]`)
- posix file handles (`open/close`)
- C FILE handles (`fopen/fclose`)
- Mutex locks (`pthread_mutex_lock/pthread_mutex_unlock`)
- C++ threads (`spawn/join`)
- Objective-C resource counted objects (`retain/release`)

## Classes that manage resources
- Some of these resources are intrinsically "unique" (e.g. mutex locks)
- Some are "duplicable" (e.g. heap allocation, Posix file handles)
- This does not matter. What matters is that an explicit action that needs to be taken by the program in order to _free_ the resource.
- We'll stick with the classic boring example of heap allocation.

### The Rule of Three

If your class directly manages some kind of resource (such as a new'd pointer), then you almost
certainly need to hand-write three special member functions:

1. A _destructor_ to free the resource
2. A _copy constructor_ to copy the resource
3. A _copy assignment operator_ to free the left-hand resource **and** copy the right-hand one

Use the _copy-and-swap_ idiom to implement assignment.

Why copy-and-swap?
- if we do hand-managed deallocation + reallocation + assignment, what can be the problem?
- it is fine if we do `v = w`
- but what happens when someone does `v = v`? LHS and RHS values are the same. If we have a deallocation, we just deallocated the thing we were supposed to copy. :)
    - Original data is gone, we deleted it.
    - Self copy is a problem

### RAII 

The slogan is about initialization. But the meaning is really about _cleanup_.
It really should be called _"Resource Freeing Is Destruction"_

### RAII and exception safety
We might throw an exception and forgot to cleanup at exception handling
Hence, to avoid such bugs, do all the resource cleanup in destructors

Performance but no Safety. I think that's a reasonable point-of-view when it comes to C++ code.
Rust: Safety first without compromising on performance. 

### The Rule of Zero

If your class does not directly manage any resource, but merely uses library components such as vectors and strings, then you should strive to write _no_ special member functions.

Let the compiler: 
    - implicitly generate a defaulted constructor
    - generate the copy ctor
    - generate the copy assignment operator
    - (your own swap might improve performance)

- Business Logic classes: Follow Rule of Zero
- Resource Management classes: Follow Rule of Three

### RValue references
### The Rule of Five
- 2 more rules for performance
    - a move constructor to transfer ownership of the resource
    - a move assignment operator to free lhs and transfer ownership to the rhs

CAS leads to duplication!
copy with `std::move()` means we can still use the CAS idiom.