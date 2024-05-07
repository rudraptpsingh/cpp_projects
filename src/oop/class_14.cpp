#include <iostream>

using namespace std;

/*
You cannot have static and nonstatic member functions with the same names and the same number and type of arguments.
Static member functions can not be declared with the keywords virtual, const, volatile or const volatile.
A static member function can access only the names of static members, enumerators, and nested types of the class in which it is declared.
*/

class X {
public:
    static int f() {
        cout << "in static f()" << endl;
        return 0;
    }


    int f(int a) {
        cout << "in f()" << endl;
        return 0;
    }
};

int main() {
    X x;
    x.f(1);
    X::f();
}