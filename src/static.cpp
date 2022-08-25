
// static int s_Variable = 10;  // duplicate linker error with global without `static`
int s_Variable = 10;

// because we also define s_Variable as a global in main.cpp,
// without the static keyword, we will get a duplicate symbol error by the linker.

// If we want to reference to this variable without making it static:
// we can declare an undefined variable as `extern` by the same name in main.cpp.
// Then, we will get the value defined above! But it has to be non-static!

// static int s_ThisLookupWillFail = 20; // this will be invisible to the linker for `extern`
int s_ThisLookupWillPass = 20;

// the same concept applies to functions that applies to variables as far as static is concerned.
static void Function()
{
}

// PS: defining a static variable in a header file and including it into multiple cpp files will make it
// local to those individual translation units.

// Why would you need static variables?
// Well, you want to be using static as much as you can instead of using global. Global namespace pollution is generally considered bad. 
// Use it for the same reason you would use private member variables in a class.

// TL;DR: Try to mark variables as static unless you need those to be available across translation units.