/*
Linkage determines whether identifiers that have identical names refer to the same object, function, or
other entity, even if those identifiers appear in different translation units. The linkage of an identifier
depends on how it was declared. There are three types of linkages:
v Internal linkage : identifiers can only be seen within a translation unit.
v External linkage : identifiers can be seen (and referred to) in other translation units.
v No linkage: identifiers can only be seen in the scope in which they are defined.
Linkage does not affect scoping, and normal name lookup considerations apply.

You can have linkage between translation units written in different programming languages, which is
called language linkage.

Internal linkage:

The following kinds of identifiers have internal linkage:
v Objects, references, or functions explicitly declared static
v Objects or references declared in namespace scope (or global scope in C) with the specifier const and
neither explicitly declared extern, nor previously declared to have external linkage
v Data members of an anonymous union
v 2C0+0+0 Function templates explicitly declared static
v 2C0+0+0 Identifiers declared in the unnamed namespace
A function declared inside a block will usually have external linkage. An object declared inside a block
will usually have external linkage if it is specified extern. If a variable that has static storage is defined
outside a function, the variable has internal linkage and is available from the point where it is defined to
the end of the current translation unit.
If the declaration of an identifier has the keyword extern and if a previous declaration of the identifier is
visible at namespace or global scope, the identifier has the same linkage as the first declaration.


External linkage:

In namespace scope, the identifiers for the following kinds of entities have external linkage:
v A reference or an object that does not have internal linkage
v A function that does not have internal linkage
v A named class or enumeration
v An unnamed class or enumeration defined in a typedef declaration
v An enumerator of an enumeration that has external linkage
v A template, unless it is a function template with internal linkage
v A namespace, unless it is declared in an unnamed namespace
If the identifier for a class has external linkage, then, in the implementation of that class, the identifiers
for the following will also have external linkage:
v A member function.
v A static data member.
v A class of class scope.
v An enumeration of class scope.

No linkage:

The following kinds of identifiers have no linkage:
v Names that have neither external or internal linkage
v Names declared in local scopes (with exceptions like certain entities declared with the extern keyword)
v Identifiers that do not represent an object or a function, including labels, enumerators, typedef names
that refer to entities with no linkage, type names, function parameters, and template names
You cannot use a name with no linkage to declare an entity with linkage. For example, you cannot use
the name of a structure or enumeration or a typedef name referring to an entity with no linkage to
declare an entity with linkage. The following example demonstrates this:
int main() {
struct A { };
// extern A a1;
typedef A myA;
// extern myA a2;
}
The compiler will not allow the declaration of a1 with external linkage. Structure A has no linkage. The
compiler will not allow the
*/