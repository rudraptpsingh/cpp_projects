#include <iostream>

using namespace std;

/*
static data members and their initializers can access other static private and protected members of the class.
*/

class C {
    static int i;
    static int j;
    static int k;
    static int l;
    static int m;
    static int n;
    static int o;
    static int p;
    static int f() {
        return 0;
    }

    int a;

public:
    C() {
        a = 0;
    }
};

C c;
int C::i = C::f();
int C::j = f();
int C::k = c.a;
int C::l = i;
int C::m = C::j;


int main() {

}