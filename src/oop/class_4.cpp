#include <iostream>

using namespace std;

struct X {
    int a;
};

// ways to declare references to classes, pointers to classes, and arrays of classes.
int main() {
    class X x;
    x.a = 5; // works as 'a' is still public
    cout << x.a;
}