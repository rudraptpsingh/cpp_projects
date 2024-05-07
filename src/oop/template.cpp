#include <iostream>

using namespace std;

template <typename T1, typename T2>
T2 addNums(T1 a, T2 b) {
    return a+b;
}

int main() {
    int a = 1;
    double c = 2.3, d = 4.5;
    cout << addNums<int, int>(a, c) << endl;
    cout << addNums(c, d);
}