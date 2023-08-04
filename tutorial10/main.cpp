#include <iostream>
#include <vector>
#include <string>

void square(std::vector<int>& v);


template <class InputIt>
void accumulate(InputIt first, InputIt last, std::string& str);

int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    square(v);
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::vector < std::string > str_vec{ "a", "a", "a", "a", "a", "b" };
    std::string my_str;
    accumulate(str_vec.begin(), str_vec.end(), my_str);

    std::cout << my_str << std::endl;
}

void square(std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        *it = *it * *it;
    }
}

// looks for an element and return the position if found, last if not
template <class InputIt, class T>
InputIt find(InputIt first, InputIt last, const T& value) {
    for (auto it = first; it != last; ++it) {
        if (*it == value)
            return it;
    }
    return last;
}

template <class InputIt>
void accumulate(InputIt first, InputIt last, std::string& str) {
    for (auto it = first; it != last; ++it) {
        str += *it;
    }
}