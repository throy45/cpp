#include <array>
#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    for (size_t i{}; i < arr.size(); ++i)
    {
        std::cout << arr.at(i) << std::endl;
    } // at will throw an exception if the index is out of range
    // instead of [] which will not throw an exception
    for (int i : arr)
    {
        std::cout << i << std::endl;
    }
    arr.front();
    arr.back();
    if (arr.empty())
    {
        ;
    }

    // vectors
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::vector<int> vec2(5, 0); // 5 elements with value 0
    vec2.push_back(6);           // add 6 to the end of the vector
    std::vector<int> vec3{1, 2, 3, 4, 5};
    for (int i : vec3)
    {
        i *= i; // does not work because i is a copy of the element in the vector
    }
    for (int i : vec3)
    {
        std::cout << i << std::endl;
    }
    for (int &i : vec3)
    {
        i *= i; // works because i is a reference to the element in the vector
    }
    for (std::vector<int>::iterator i = vec3.begin(); i != vec3.end(); ++i)
    { // useful in some algorithms, especially when you need to modify the elements
        // or sorting
        std::cout << *i << std::endl;
    }

    // strings
    std::string str{"Hello"};
    std::cout << str.length << std::endl;

    const char *a = str.c_str(); // returns a pointer to the first character in the string
    char *const b = "abc";
    const char *const c = "abc";
    // the difference between b and c is that b can be reassigned to point to another string

    std::find(str.begin(), str.end(), 'l'); // returns an iterator to the first occurence of 'l'

    return 0;
}