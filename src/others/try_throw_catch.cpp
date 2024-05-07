/*
Try blocks and catch blocks work together -- a try block detects any exceptions that are thrown by statements within the try block, and routes them to a catch block with a matching type for handling.
A try block must have at least one catch block immediately following it, but may have multiple catch blocks listed in sequence.

Once an exception has been caught by the try block and routed to a catch block for handling, the exception is considered handled, and execution will resume as normal after the catch block.

Catch parameters work just like function parameters, with the parameter being available within the subsequent catch block.
Exceptions of fundamental types can be caught by value, but exceptions of non-fundamental types should be caught by const reference to avoid making an unnecessary copy (and, in some cases, to prevent slicing).

Try blocks catch exceptions not only from statements within the try block, but also from functions that are called within the try block.

When an exception is thrown, the program first looks to see if the exception can be handled immediately inside the current function (meaning the exception was thrown within a try block inside the current function, and there is a corresponding catch block associated).
If the current function can handle the exception, it does so.

If not, the program next checks whether the function’s caller (the next function up the call stack) can handle the exception. 
In order for the function’s caller to handle the exception, the call to the current function must be inside a try block, and a matching catch block must be associated. If no match is found, then the caller’s caller (two functions up the call stack) is checked. Similarly, in order for the caller’s caller to handle the exception, the call to the caller must be inside a try block, and a matching catch block must be associated.

The process of checking each function up the call stack continues until either a handler is found, or all of the functions on the call stack have been checked and no handler can be found.

If a matching exception handler is found, then execution jumps from the point where the exception is thrown to the top of the matching catch block.
This requires unwinding the stack (removing the current function from the call stack) as many times as necessary to make the function handling the exception the top function on the call stack.

If no matching exception handler is found, the stack may or may not be unwound. 
Unwinding the stack destroys local variables in the functions that are unwound (which is good, because it ensures their destructors execute).

When no exception handler for a function can be found, std::terminate() is called, and the application is terminated. In such cases, the call stack may or may not be unwound!
If the stack is not unwound, local variables will not be destroyed, and any cleanup expected upon destruction of said variables will not happen!
*/
#include <iostream>

using namespace std;

void checkString(string& s) {
    if (s == "worse") {
        throw "worse string";
    }
}

void printString(string& s) {
    try {
        if (s == "bad") {
            throw string("bad string");
        }

        checkString(s);
        cout << s << endl;
    } catch(const string& err) { 
        cerr << err << endl;
    } catch (const char* err) {
        cerr << err << endl;
    } catch(...) { // catch all
        cerr << "Error occured";
    }
}

int main() {
    string str;
    cin >> str;
    printString(str);
}