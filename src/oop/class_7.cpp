// Nested classes

#include <iostream>

using namespace std;

// A nested class is declared within the scope of another class.
// The name of the nested class is local to its enclosing class.
// Member functions of a nested class follow regular access rules
// and have no special access privileges to members of their enclosing class.
// Member functions of the enclosing class have no special access to members of a nested class.

class A {
    int x;

    class B {};

    class C {
        //B b; // This is not allowed as A::B is private.

        int y;
        void f(A* p, int i) {
            p->x = i; // shouldn;t be allowed but compiles.
            cout << p->x;
        }
    };

    void g(C* p) {
        // int z = p->y; // not allowed as y is private.
    }
};

int main() {
    //A::B b; not allowed as A::B is private.
}


