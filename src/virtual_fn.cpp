#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

// Virtual functions: allow us to override methods in sub-classes
class VBaseEntity : public Printable
{
public:
    virtual std::string GetName() { return "VBaseEntity"; }

    // virtual std::string PureGetName() = 0; // this makes it a pure virtual function.
    // pure virtual functions _have_ to be implemented in the sub-classes
    // if a class only has pure virtual fns, it can be considered like an "interface".
    // If a class has a pure virtual function, it can no longer be instantiated.
    virtual std::string GetClassName() { return "VBaseEntity"; }
};

class VPlayer : public VBaseEntity 
{
private:
    std::string m_Name;

public:
    VPlayer(const std::string& name)
        : m_Name(name) {}

    std::string GetName() override { return m_Name; }

    std::string GetClassName() override { return "VPlayer"; }
};

/**
 * someEntity->GetName() gets completely coerced to a VBaseEntity and loses its Player trait
 * including the player name. This is bad because despite the pointer type, someEntity actually
 * refers to `manish` who is SomePlayer and has a name!
 * This is the same reason why printEntity() prints the wrong size in oop.cpp
 */
void PrintName(VBaseEntity* e)
{
    std::cout << e->GetName() << std::endl;
}

void printClassName(Printable* obj)
{
    std::cout << "class=" << obj->GetClassName() << std::endl;
}

void WithoutVirtualFn()
{
    VBaseEntity* e = new VBaseEntity();
    PrintName(e);                       // should print "VBaseEntity"
    VPlayer* manish = new VPlayer("Manish");
    PrintName(manish);                  // should print "Manish"
    VBaseEntity* someEntity = manish;
    PrintName(someEntity);              // should print "Manish" again!
    // Virtual functions help us do correct polymorphism here via something called
    // "dynamic dispatch", which happens via a vTable.
    // vTable has a mapping for all virtual functions in our base class,
    // so that we can map them to the correct overwritten function at runtime.
    // The fix: add the keyword `virtual` to the overwridden method in our Base class
    // mark the overridden function with the keyword `override` (introduced in C++11)
    // this makes the override explicit and allows the compiler to check the override
    // and prevent human error.

    // Cost of Virtual Functions:
    // There is 2 runtime costs:
    // 1. Additional memory required for the VTable to dispatch to correct fn.
    // 2. VTable lookup during method call is an additional cost.
    // Usually this shouldn't be an issue unless you're in an embedded environment
    // where each and every byte is valuable. Otherwise there really isn't any impact.

    printClassName(e);
    printClassName(manish);
}

