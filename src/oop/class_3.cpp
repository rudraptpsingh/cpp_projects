#include <iostream>

using namespace std;

class X {};

// ways to declare references to classes, pointers to classes, and arrays of classes.
int main() {
    X x;
    X &xref = x;
    X *xptr;
    X xarray[10];
}