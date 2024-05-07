#include <iostream>

using namespace std;

class X {};

struct Y {};

int main() {
    int X = 0;
    Y y;
    //X x; // class 'X' is hidden by a non-type declaration of 'X' here
    class X x;
}