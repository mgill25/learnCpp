#include <iostream>
#include "log.h"
#include "common.h"
#include <cstring>

void Separator()
{
    std::cout << "---------------------" << std::endl;
}

void Log(const char* message);

int Multiply(int a, int b) {
    Log("Inside Multiply()");
    return a * b;
}

void TypeSizes() {
    std::cout << "sizeof(char) :\t" << sizeof(char) << std::endl;    
    std::cout << "sizeof(short) :\t" << sizeof(short) << std::endl;    
    std::cout << "sizeof(int) :\t" << sizeof(int) << std::endl;    
    std::cout << "sizeof(long) :\t" << sizeof(long) << std::endl;    
    std::cout << "sizeof(long long) :\t" << sizeof(long long) << std::endl;    
    std::cout << "sizeof(double) :\t" << sizeof(double) << std::endl;    
    std::cout << "sizeof(float) :\t" << sizeof(float) << std::endl;
    std::cout << "sizeof(const char*) :\t" << sizeof(const char*) << std::endl;
}

// argument passed by value. No mutation visible outside.
void IncrementByVal(int value) {
    value++;
}

// argument is variable address. Deferenced and then mutated.
void IncrementByPtr(int* ptr) {
    // deference the pointer and then increment
    // needs to be called as IncrementByPtr(&value) since ptr would
    // have the address of value that we deference here.
    // Parenthesis is needed because of operator precedence. Increment has
    // higher precedence than deference operator, and we do not want to accidentally
    // increment the address by 1 and then dereference that.
    (*ptr)++;
}

// Reference is an easier way to do exactly the above.
// No need to dereference or worry about parens. Can also directly pass the variable.
void IncrementByRef(int& reference) {
    reference++;
}

void PointerTutorial() {
    // Forget types! They are just fiction to make our life easier.
    // Types are meaningless! A pointer is an _integer_ that holds 
    // a memory address.
    // lets create the purest of pointers: a void pointer (type-less)
    // Giving type to the pointer just means the data at that addresses
    // should be interpreted as that type. There is no other meaning of
    // providing type to a pointer.

    int var = 8;
    // Where are you in memory, var?
    int* memoryAsInt = &var;
    *memoryAsInt = 30;
    std::cout << var << std::endl;
    char* buffer = new char[8];
    memset(buffer, 1, 8);
    buffer[0] = 'm';
    buffer[1] = 'a';
    buffer[2] = 'n';
    buffer[3] = 'i';
    buffer[4] = 's';
    buffer[5] = 'h';
    for (size_t i = 0; i <= 5; i++) {
        std::cout << buffer[i] << "";
    }
    std::cout << std::endl;
    delete[] buffer;

    // references
    int a = 10;
    int& b = a; // this is *not* a new variable in memory, just a reference in the code.
    // b is just an alias to a.  (I guess it's a mutable alias!)
    b++;
    std::cout << "a = " << b << std::endl;
    IncrementByVal(a);
    std::cout << "a = " << a << std::endl;
    IncrementByRef(a);
    std::cout << "a = " << a << std::endl;
    // XXX: do not re-assign references (since they are aliases, you'll just end up rewriting the original values)
    int p = 10;
    int q = 20;
    int* ref = &p;
    *ref = 100;
    ref = &q;
    (*ref)++;
    std::cout << "p = " << p << " q = " << q << std::endl;
}

void LoggerClassUsage() {
    MyLog log;
    log.SetLevel(MyLog::LevelWarning);
    log.Warn("This is your final warning!");
    log.Info("This will not be printed. So sad, very bad.");
}

// int s_Variable = 20; // duplicate linker error without static keyword

extern int s_Variable; // external linkage: looks for a variable definition in other translation units.
// `static` variables are **not** visible to the linker. 
// extern int s_ThisLookupWillFail;
extern int s_ThisLookupWillPass;

void Function() {

}

void StaticKeywordUsage() {
    // The linker is not going to be looking to link this variable (or any static function)
    // outside this translation unit.
    std::cout << s_Variable << std::endl;
    // std::cout << s_ThisLookupWillFail << std::endl;
    std::cout << s_ThisLookupWillPass << std::endl;
    Function();
}

void UseEntityStruct();
void UseEntityClass();
void UseInheritance();
void WithoutVirtualFn();
void UnderstandingArrays();
void ArraysUsingNew();
void ExamineClassArray();
void ArraySize();
void StdArray();
void UseStrings();
void UseStdString();

int main() {
    // std::cout << Multiply(10, 20) << std::endl;
    PointerTutorial();
    TypeSizes();
    Separator();
    LoggerClassUsage();
    Separator();
    StaticKeywordUsage();
    Separator();
    UseEntityStruct();
    Separator();
    UseEntityClass();
    Separator();
    UseInheritance();
    Separator();
    WithoutVirtualFn();
    UnderstandingArrays();
    ArraysUsingNew();
    ExamineClassArray();
    ArraySize();
    StdArray();
    UseStrings();
    UseStdString();
}
