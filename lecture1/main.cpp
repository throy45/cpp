#include <iostream>

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
    };

    Foo f;
    return 0;
}