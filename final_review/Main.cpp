#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    struct Squared_Number {
        int number{ 1 };
        int squared{ 1 };
        int operator()() {
            int temp = squared;
            ++number;
            squared = number * number;
            return temp;
        }
    };

    Squared_Number squared_number;
    std::vector<int> vec1(10);
    std::vector<int> vec2(10);
    std::vector<int> vec3(10);
    std::generate(vec1.begin(), vec1.end(), Squared_Number{});
    std::generate(vec3.begin(), vec3.end(), squared_number);

    for (auto& i : vec1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (auto& i : vec3) {
        std::cout << i << " ";
    }
    return 0;
}