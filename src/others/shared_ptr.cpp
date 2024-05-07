#include <iostream>

using namespace std;

class A {
public:
    void PrintHello() {
        cout << "Hello\n";
    }
};

void show(shared_ptr<A> ptr) {
    ptr->PrintHello();
    cout << ptr.use_count() << endl;
}

int main() {
    shared_ptr<A> aptr1(new A);
    shared_ptr<A> aptr2(aptr1);
    aptr1->PrintHello();
    aptr2->PrintHello();
    cout << aptr2.use_count() << endl;
    show(aptr2);
    cout << aptr2.use_count() << endl;

    shared_ptr<int> xptr = make_shared<int>(11);
    shared_ptr<int> yptr = make_shared<int>(22);
    shared_ptr<int> zptr = xptr;
    cout << *zptr << endl;
    yptr.swap(zptr);
    cout << *xptr << " " << *yptr << " " << *zptr << endl;
}