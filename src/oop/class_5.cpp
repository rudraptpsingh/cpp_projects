#include <iostream>

using namespace std;

class A { };

void A(class A*) { };

// If a class name is declared in the same scope as a function, enum, or object with the same name, you must
// refer to that class using an elaborated type specifier.

int main() {
    // A a; // class A hidden by function A()
    class A a;
    class A* b;
    A(&a);
    A(b);
}