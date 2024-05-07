#include <iostream>

using namespace std;

/*
Only one copy of the static member is shared by all objects of a class.
The static member is not a part of the class object.
*/

struct A {
    static void f() {
        cout << "In static function A::f()" << endl;
    }
};

int main() {
    // Different value to call the same static member function
    A::f();
    A a;
    A *aptr = &a;
    a.f();
    aptr->f();
}