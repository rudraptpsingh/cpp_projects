// C++ program to implement
// constructor in multiple
// inheritance
#include <iostream>
using namespace std;
class A1
{
public:
    A1()
    {
        cout << "Constructor of the base class A1 \n";
    }
};

class A2
{
public:
    A2()
    {
        cout << "Constructor of the base class A2 \n";
    }
};

class A3
{
public:
    A3()
    {
        cout << "Constructor of the base class A3 \n";
    }
};

// IMP: Here A2 Constructor called first, then A1, then A3 as A2 is virtual.
class S : public A1, virtual A2, public A3
{
public:
    S() : A1(), A2()
    {
        cout << "Constructor of the derived class S \n";
    }
};

// Driver code
int main()
{
    S obj;
    return 0;
}
