#include <iostream>
using namespace std;


class Base
{
public:
	int f(int i)
	{
		cout << "f(int): ";
		return i+3;
	}
};
class Derived : public Base
{
public:
	double f(double d)
	{
		cout << "f(double): ";
		return d+3.3;
	}
};

/*
Overloading doesn’t work for derived class in the C++ programming language.
There is no overload resolution between Base and Derived.
The compiler looks into the scope of Derived, finds the single function “double f(double)” and calls it.
It never disturbs the (enclosing) scope of Base.
In C++, there is no overloading across scopes and derived class scopes are not an exception to this general rule.
https://www.stroustrup.com/bs_faq2.html#overloadderived

But what if I want to create an overload set of all my f() functions from my base and derived class? That's easily done using a using-declaration:

	class D : public B {
	public:
		using B::f;	// make every f from B available
		double f(double d) { cout << "f(double): "; return d+1.3; }
		// ...
	};
Give that modification, the output will be
	f(int): 3
	f(double): 3.6
That is, overload resolution was applied to B's f() and D's f() to select the most appropriate f() to call.

*/
int main()
{
	Derived* dp = new Derived;
	cout << dp->f(3) << '\n';   // double f(double d) called
	cout << dp->f(3.3) << '\n'; // double f(double d) called
	delete dp;
	return 0;
}
