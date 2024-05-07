/*
Every class that uses virtual functions (or is derived from a class that uses virtual functions) has a corresponding virtual table.
This table is simply a static array that the compiler sets up at compile time.
A virtual table contains one entry for each virtual function that can be called by objects of the class.
Each entry in this table is simply a function pointer that points to the most-derived function accessible by that class.

The compiler also adds a hidden pointer that is a member of the base class,
which we will call *__vptr. *__vptr is set (automatically) when a class object is created so that it points to the virtual table for that class.
Unlike the this pointer, which is actually a function parameter used by the compiler to resolve self-references, *__vptr is a real pointer member.
Consequently, it makes each class object allocated bigger by the size of one pointer.
It also means that *__vptr is inherited by derived classes, which is important.


*/

#include <iostream>

using namespace std;

class A {
public:
    void PrintHello() {
        cout << "Hello from A" << endl;
    }
};

class B {
public:
    virtual void PrintHello() {
        cout << "Hello from B" << endl;
    }
};

class C: public B {
public:
    void PrintHello() {
        cout << "Hello from B" << endl;
    }
};


int main() {
    A a;
    B b;
    a.PrintHello();
    b.PrintHello();
    cout << sizeof(a) << endl; // prints size 1 byte
    cout << sizeof(b) << endl; // prints size 8 bytes(due to virtual function)

    /*
    Two vtables are created for each class(B and C).
    A hidden pointer is added to the base class B.
    When a class object is created, *__vptr is set to point to the virtual table for that class.
    For example, when an object of type Base is created, *__vptr is set to point to the virtual table for Base(B).
    When objects of type C is constructed, *__vptr is set to point to the virtual table for C.
    */
}