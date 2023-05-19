// brings in the iostream library
#include <iostream>

int main()
{
    /*
        This is a comment
    */

    std::cout << "Hello World!" << std::endl;
    std::cout << "Hello World!2";
    std::cout << "Hello World!3" << std::endl;
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