#include <iostream>
using namespace std;

class A {
public:
    void f() {
        cout << "in A::f()" << endl;
    }
};

class B {
public:
    void f() {
        cout << "in B::f()" << endl;
    }
};

class C: public A {

};

class D: virtual public A {
public:
    void g() {
        cout << "in D::g()" << endl;
    }
};

class E: virtual public A {
public:
    void h() {
        cout << "in E::f()" << endl;
    }
};

class F: public D, public E {

};



int main() {
    C c;
    c.f();

    D d;
    d.f();

    F f;
    f.f();
}