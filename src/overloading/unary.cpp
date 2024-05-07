#include <iostream>

using namespace std;

/*
You overload a unary operator with either a nonstatic member function that has no parameters, or a
nonmember function that has one parameter. Suppose a unary operator @ is called with the statement @t,
where t is an object of type T. A nonstatic member function that overloads this operator would have the
following form:
return_type operator@()
A nonmember function that overloads the same operator would have the following form:
return_type operator@(T)

An overloaded unary operator may return any type.
*/

struct X {};

void operator!(X) {
    cout << "X::operator!" << endl;
}

struct Y {
    void operator!() {
        cout << "Y::operator!" << endl;
    }
};

int main() {
    X x;
    Y y;
    !x; // interpreted as operator!(X)
    !y; // interpreted as Y::operator!()
}