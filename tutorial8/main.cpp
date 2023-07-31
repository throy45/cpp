#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Base" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() {
        std::cout << "Derived" << std::endl;
    }
};

int main() {
    Derived d;
    Base b1 = d; // slicing, Derived part is lost
    Base& b2 = d; // not slicing, polymorphism if print is virtual
    std::cout << "b1 print call: ";
    b1.print(); // Base, static binding
    std::cout << "b2 print call: ";
    b2.print(); // Derived, dynamic binding
    return 0;

    // Polymorphism criteria:
    // 1. base class reference or pointer should be equal to derived class object or address, respectively
    // 2. common method should be virtual in base
    // 3. inherit or override the method in derived

    // What is the effect of redefining a non-virtual method in derived class?
    // 1. if base class reference or pointer is used to call the method, base class method is called
    // 2. if derived class object is used to call the method, derived class method is called
    // 3. if base class object is used to call the method, base class method is called
    // it is overloading, not overriding

    // How can you prevent a method from being overridden in derived class?
    // 1. make the method private
    // 2. make the method final
    // 3. make the class final

    // In C++ a class can have multiple parents. This is called multiple inheritance.

    // In C++ a class can inherit from one class which is inherited from another class. This is called multilevel inheritance.

    // Compositions is has-a relation (not OOP)
}