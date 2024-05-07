#include <iostream>

using namespace std;

/*
Immediately following the opening brace of each function definition, __func__ is implicitly declared by
the compiler. The resulting behavior is as if the following declaration had been made:
static const char __func__[] = "function-name";
*/

void PrintHello() {
    cout << "Hello!" << endl;
    cout << "Function name is: " << __func__ << endl;
}

int main() {
    PrintHello();
}