// Nested classes

#include <iostream>

using namespace std;

// Member functions and static data members of a nested class can be defined in namespace scope.
// A nested class may inherit from private members of its enclosing class.

class outside {
public:
    class nested {
    public:
        static int x;
        static int y;
        void f();
        void g();
    };
};

int outside::nested::x = 5;

void outside::nested::f() {
    cout << "in f()";
}

typedef outside::nested outnest;

int outnest::y = 6;

void outnest::g() {
    cout << "in g()";
}

int main() {
    // class outnest obj; // you can't use a typedef name in an elaborated type specifier.
    outnest n;
    n.f();
    n.g();
}