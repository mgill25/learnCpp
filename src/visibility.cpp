#include <iostream>

// 3 modifiers: private, protected, public.
// Visibility has no impact on performance or how the code runs.
// struct is public by default, class is private by default.
// Engineering Manager for the Ingestion Platform.

class DefaultEntity
{
    int X, Y; // visibility=private by default

public:
    DefaultEntity()
    {
        X = 0;
        Y = 0;
    }
};

struct DefaultStructEntity
{
    int X, Y; // visibility public by default
};

// only private (* and _friend_ functions) can access private members of a class.

class A { int someMember; };
class B : public A 
{
public:
    B() {
        // someMember = 20; // sub-classes **do not** have access to private members of superclass
    }
};

// protected is a little bit more visible than private (but less visible than public)
class Woah {
protected:
    int woahDude;
};

class Hurr : public Woah
{
    Hurr() {
        woahDude = 20; // this works because woahDude is protected and visible from subclasses.
    }
};