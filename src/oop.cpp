#include <iostream>

class BaseEntity
{
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
        std::cout << "New Position: " << X << ", " << Y << std::endl;
    }
};

class SomePlayer : public BaseEntity 
{
public:
    const char* Name;

    SomePlayer(const char* name)
    {
        Name = name;
    }

    void PrintName()
    {
        std::cout << "Player Name = " << Name << std::endl;
    }
};

void printEntity(BaseEntity e)
{
    std::cout << "X = " << e.X << ", Y = " << e.Y << std::endl;
    std::cout << "SizeOf(Entity) = " << sizeof(e) << std::endl; // different from SomePlayer size!
}

void UseInheritance()
{
    SomePlayer manish("Manish Gill");
    manish.X = 10.0f;
    manish.Y = 20.0f;
    manish.PrintName();
    manish.Move(10, 20);
    std::cout << "sizeof(manish) = " << sizeof(manish) << std::endl;
    printEntity(manish);
}