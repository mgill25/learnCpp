# Classes vs Structs

They might appear to be similar. When should you be using one vs another?

Well, basically there is no difference. :)

Except:

1. Visibility
Classes are private by default. With a struct, everything is public by default!

2. Usage
Structs exist in C++ to maintain backwards compatibility in C. It's up to the programmer's style - besides visibility - about when to use Structs vs classes.

Example: Cherno uses structs when deal with POD (Plain-Old-Data). Basically some sort of structure which just represents a bunch of variables. We can still add methods to this struct.

Example: a `Vec2` struct which holds 2 `float` variables together. Nothing more.
Method: `Vec2` struct can have an `Add()` method.

`Class`es can be used when you need more functionality: Things like constructors, destructors, methods, OOP features like inheritance hierarchy. Keep your structs simple.

