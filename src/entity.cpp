// learning about static in struct and class
#include <iostream>
struct Entity
{
    static int x, y;
    void Print()
    {
        std::cout << "Entity(x = " << x << ", y = " << y << ")" << std::endl;
    }
};

int Entity::x;
int Entity::y;

void UseEntityStruct()
{
    Entity e;
    e.x = 2;
    e.y = 3;

    // Entity e1 = { 5, 8 }; // error: excess elements in struct initializer (when x, y are `static`)
    // Undefined symbols for architecture (if we haven't defined them. lets do that globally above)
    // After definining it, we can print e1
    Entity e1;
    e1.x = 5;
    e1.y = 8;

    e.Print();  // e.x and e.y are now the same as e1.x and e1.y (one instance of (x, y) across instances of classes)
    e1.Print();

    // commented out to reduce warning noise. valid code.
    // if (e1.x == e.x && e1.x == Entity::x) {
    //     std::cout << "static variables are shared across instances. Hence proved" << std::endl;
    // }

    // Be mindful of the fact that static methods can't access non-static variables!
    // That should be obvious :) 
    // A Static method does not have a class instance (object).
}