#include <iostream>

using namespace std;

class X {};

int main() {
   //X X, T; // Declares two objects. This is equal to the below statement.
    X X;
    class X T; // keyword class is required since variable X hides class type X
}