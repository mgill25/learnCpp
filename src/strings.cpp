#include <iostream>
#include <string>
#include <stdlib.h>

void UsesOfChar()
{
    // 1. char can be used to refer to 1 byte of memory
    // 2. Cast pointers to char* so you can do pointer arithmetic in terms of bytes
    // 3. Useful for allocating memory buffers: char buffer[1024] just allocates 1K memory. There you go.
    // 4. Also useful for string and text. ASCII characters are 1 byte.
    //    Of course, character sets exist in which chars are > 1 byte (Japanese, English etc, unicode).
    // 5. We can't fit all languages into 8-bit character sets. UTF-16: 16-bit character encoding.
    // 6. But in C++ baseline, primitive data type char (not a _wide_ string but a normal string), we have char = 1 byte.
    // 7. For other languages, you will need a different character encoding, can't do that with this.
    // 8. In terms of things like font-rendering in game engines etc, just text in general is a big and complex problem.
}

void UseStrings()
{
    // String in general = group of characters. Basically text.
    UsesOfChar();
    // We often refer to strings as const char*. Lets see how that works.
    const char* name = "Manish Gill"; // C-style way of definining strings. Still important to know how this works.
    // make it const because you don't wanna be changing its value.
    // XXX: Just because this is a char*, DOES NOT MEAN that this is heap allocated! This is still on the Stack!
    // delete[] name is _not needed_ here. 
    // RULE OF THUMB: Don't use `delete` without a `new`!
    const char* foo = "Manish"; // this has no `new` keyword, hence no `delete` needed.
    // foo[2] = 'a'; // this will not work since our string is immutable/const.
    // null termination character is needed. that's how we know the string has terminated/ended.
    std::cout << foo << std::endl;
    std::cout << name << std::endl;

    char name2[7] = {'M', 'a', 'n', 'i', 's', 'h', '\0'};
    std::cout << name2 << std::endl;

    // NOTE: always use `const` when creating char*. If there is a pointer to a string literal (char*),
    // which is non-const, then mutating it can be UB (undefined behaviour). This is also something that
    // has been deprecated since C++11.
    char* lastName = "Gill";
    // lastName[1] = "o"; // This assignment will fail since C++11 because we never want to mutate strings!
    std::cout << lastName << std::endl;
}

// String copy is quite slow.
void BadPrintBecauseCopy(std::string someString)
{
    std::cout << "Got it by copy = " << someString << std::endl;
}

// Pass the string as a const reference: so we promise not to mutate and 
// it's a reference, not a copy.
void GoodPrintNoCopy(const std::string &someStringReference)
{
    std::cout << "Got by const ref = " << someStringReference << std::endl;
}

void StringLiteral()
{
    // RHS is a string literal.
    const char name[7] = "Manish"; // literals like RHS are const char[]    
    const char weirdName[8] = "Ma\0nish";
    std::cout << "strlen() for my weirdName = " << strlen(weirdName) << std::endl;
    // as soon as strlen() runs into \0, it finishes. Hence, we get weirdName length = 2.
    
    // String literals are stored in a _read-only_ section of the memory.
    // This can be verified by inspecting the assembly, we can find TEXT...cstring_literals section
    // IF you want to mutate char*...don't use char*, just use char[].
    
    // Other string types...
    const wchar_t* name2 = L"Manish";  // (2 or 4) bytes per char
    const char16_t* name3 = u"Manish"; // 2-byte per char, UTF-16
    const char32_t* name4 = U"Manish"; // 4-byte per char, UTF-32
    const char8_t* name5 = u8"Manish";

    // Multiline strings
    const char* example = R"(Line1
Line2
Line3
Line4)";

    // C++14 adds some more things...
    using namespace std::string_literals;
    std::string name0 = "Manish"s + "Gill"s; // This works now with the "s suffix.

}

void UseStdString()
{
    // C++ STL has a basic_string class (template class)
    // std::string is a templated version of that basicstring class, which is templated
    // with char. (template specialization). There is something called wstring (for wide strings) as well.
    std::string name = "Hello";
    std::cout << name << std::endl;     // #include<string> contains the overload for << that is needed for std::string
    name.size();
    name.append("foo");
    // DO NOT ADD 2 strings together like so:
    // std::string full_name = "Manish " + "Gill"; // this will not work (both RHS values are const char*)
    // append strings like so:
    std::string full_name = "Manish ";
    full_name += "Gill";    // works because += is overloaded to allow appending const char*
    // another way:
    std::string my_full_name = std::string("Manish ") + "Gill"; // has another allocation

    // finding substrings in strings:
    bool contains = my_full_name.find("ill") != std::string::npos;
    std::cout << my_full_name << " contains \"ill\"? " << contains << std::endl;
    BadPrintBecauseCopy(my_full_name);
    GoodPrintNoCopy(my_full_name);
    StringLiteral();
}