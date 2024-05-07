#include <iostream>

using namespace std;

/*
You can directly refer to a static member in the same scope of its class, or in the scope of a class derived from the static member's class.
*/

int f() {
    cout << "In g()" << endl;
    return 0;
}

class X {
    public:
        static int j;
        static int g() {
            cout << "In X::g()" << endl;
            return 1;
        }
};

class Y : public X {
    public:
        static int i;
};

int X::j = g(); // X::g()
int Y::i = j;   // X::j

int main() {
    cout << X::j;
}