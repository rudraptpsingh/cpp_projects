// Local classes

#include <iostream>

using namespace std;

/*
A local class is declared within a function definition.
Declarations in a local class can only use type names, enumerations, static variables
from the enclosing scope, as well as external variables and functions.

Local classes in C++ have certain restrictions, and one of them is that they cannot access non-static local variables of their enclosing function directly. 
This is because the lifetime of local variables in a function ends when the function exits, while the lifetime of objects of the local class can extend beyond that scope. 
Therefore, allowing direct access to local variables from within a local class could lead to dangling references or undefined behavior.

Member functions of local class ahve to be defined within their class definition, if that are defined at all. As a result, member functions of a local class are inline functions.

A local class can not have static data members.
*/

int x;

void f() {
    static int y;
    //int x;
    extern int g();

    class local {
        int g() {
            //return x; // reference to local variable of enclosing function not allowed.
            return 0;
        }

        int h() {
            return y;
        }

        int k() {
            return ::x;
        }

        int l() {
            return g();
        }
    };
}

int main() {
    return 0;
}