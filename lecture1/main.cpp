#include <iostream>

void f(int, int &);
void g(int, const int &);

int main()
{
    int a = 5;
    int *pa = &a;
    int **ppa = &pa;
    std::cout << "a: " << a << std::endl;
    std::cout << "pa: " << pa << std::endl;
    std::cout << "*pa: " << *pa << std::endl;
    std::cout << "ppa: " << ppa << std::endl;
    std::cout << "*ppa: " << *ppa << std::endl;
    std::cout << "**ppa: " << **ppa << std::endl; // not necessary at end of file

    class Foo
    {
        std::string name;
        int age;

    public:
        Foo() : name{"Bob"}, age{10} {}
    };

    Foo foo;

    int x = 10, y = 20;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    f(x, y);
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    // f(1, 2); // doesn't compile because 2 is not a reference
    // int &r1 = 10; // doesn't compile because 10 is not a variable
    const int &r2 = 10; // works because 10 is const
    // creates a temporary var int temp = 10, const int &r2 = temp;
    return 0;
}

void f(int a, int &b)
{
    a = 100;
    b = 200;
    return;
}

void g(int a, int const &b)
{
    a = 100;
    // b = 200; // doesn't compile because b is const
    return;
}