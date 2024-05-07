#include <iostream>

using namespace std;

class A {
public:
    void PrintHello() {
        cout << "Hello\n";
    }
};

int main() {
    unique_ptr<A> aptr(new A);
    aptr->PrintHello();
    unique_ptr<A> aptr2 = move(aptr);
    aptr2->PrintHello();
    cout << aptr.get() << " " << aptr2.get();
}