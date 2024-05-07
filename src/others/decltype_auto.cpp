#include <iostream>

using namespace std;

template <typename X, typename Y>
auto product(X x, Y y) -> decltype(x+y) {
    return x+y;
}

int main() {
    cout << product(1, 2) << endl;
    cout << product(1, 2.0) << endl;
    cout << product(1.0, 2.0) << endl;
}