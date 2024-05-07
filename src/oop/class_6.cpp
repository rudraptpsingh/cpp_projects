// Incomplete class declarations

#include <iostream>

using namespace std;

class A; // Incomplete class declaration. No class members defined. 
         // You can not declare any objects of this class type or refer to members of this class until the declaration is complete.
         // However making specific references to a class prior its definition is allowed as long as the size of the class is not required.

class B {}; // Complete class declaration(empty member list)

int main() {
    //A a; // error, declaring an object of an incompletely declared class type.
    A *a; // allowed. 
    B b;
}