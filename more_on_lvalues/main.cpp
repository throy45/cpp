#include <iostream>
using std::cout;

int f() { return 77; } // f() is an rvalue of type int

class Foo
{ /*...*/
};
int fun(const Foo &f) { return 1; }
int fun(Foo &f) { return 2; }
int fun(const Foo &&f) { return 3; }
int fun(Foo &&f) { return 4; }

const Foo cffun() { return Foo(); } // cffun() is an rvalue of type const Foo.
int main()
{
    Foo f{};                   // f is a named lvalue of type Foo.
    const Foo cf{};            // cf is a named lvalue of type const Foo.
    const Foo &cfr1 = f;       // Initialize cfr1 with lvalue of type Foo.
    const Foo &cfr2 = cf;      // Initialize cfr2 with lvalue of type const Foo.
    const Foo &cfr3 = Foo();   // Initialize cfr3 with an rvalue of type Foo.
    const Foo &cfr4 = cffun(); // Initialize cfr4 with an rvalue of type const Foo.
    // Foo& fr4 = cffun(); // Error, cannot initialize a nonconst lvalue reference with an rvalue.
    // const Foo&& cfrr1 = f; // Error, cannot initialize an rvalue reference with an lvalue.
    // const Foo&& cfrr2 = cf; // Error, cannot initialize an rvalue reference with an lvalue.
    const Foo &&cfrr3 = Foo();   // Initialize an rvalue reference with an rvalue of type Foo.
    const Foo &&cfrr4 = cffun(); // Initialize an rvalue reference with an rvalue of type Foo.
    // Foo&& frr4 = cffun(); // Error, cannot initialize a nonconst rvalue reference
    //  with an rvalue of type const Foo.
    cout << "fun(f) " << fun(f) << '\n';
    cout << "fun(cf) " << fun(cf) << '\n';
    cout << "fun(cfr1) " << fun(cfr1) << '\n';
    cout << "fun(Foo()) " << fun(Foo()) << '\n';
    cout << "fun(cfrr3) " << fun(cfrr3) << '\n';
    return 0;
}