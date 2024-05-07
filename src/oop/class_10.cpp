#include <iostream>

using namespace std;

/*
You may declare a data member or member function as static but not auto, extern or register.
A constant initializer( = constant expression) may only appear in a class member of integral or enum type that has been declared static.
The compiler allocates class members in the order in which they are declared.
*/

class X {
    int x = 10;
    static int y;
    //auto z;
    //extern int d;
    //register int e;

    //virtual void func() = 0;

};

int main() {
    // X x; // object declaration of an abstract class is not allowed.
    return 0;
}