#include "assignment5.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <set>

WordsVector read_words_into_vector(const std::string& inFileName) {
    std::ifstream ifs(inFileName);
    if (!ifs.is_open()) {
        std::cout << "Could not open file " << inFileName << std::endl;
        throw std::runtime_error("Could not open file " + inFileName);
    }
    WordsVector words_vector;
    std::copy(
        std::istream_iterator<std::string>(ifs),
        std::istream_iterator<std::string>(),
        words_vector);
    return words_vector;
}

WordsMap map_and_count_words_using_lambda(const WordsVector& wvec) {
    WordsMap wmap;
    std::for_each(
        wvec.begin(),
        wvec.end(),
        [&wmap](std::string word) {++wmap[word];});
    return wmap;
}

WordsMap map_and_count_words_using_functor(const WordsVector& wvec) {
    struct WordCountFunctor {
        WordsMap wmap;
        void operator()(std::string word) { ++wmap[word]; }
        WordsMap& getmap() { return wmap; }
    };
    WordCountFunctor wcf{};
    std::for_each(
        wvec.begin(),
        wvec.end(),
        wcf);
    return wcf.getmap();
}

WordsVector remove_duplicates(const WordsVector& words_vector) {
    WordsVector words_vec{ words_vector };

    std::sort(words_vec.begin(), words_vec.end());

    auto end = std::unique(words_vec.begin(), words_vec.end());

    words_vec.erase(end, words_vec.end());

    return words_vec;
}

bool is_palindrome(const std::string& phrase) {
    std::string temp;
    auto back_inserter{ std::back_inserter(temp) };


    std::remove_copy_if(
        phrase.begin(),
        phrase.end(),
        back_inserter,
        isalpha
    );

    std::transform(
        temp.begin(),
        temp.end(),
        temp.begin(),
        [](char c) {return static_cast<char>(toupper(c));}
    );

    bool result = std::equal(temp.begin(), temp.begin() + temp.length() / 2, temp.rbegin());

    return result;

}

size_t count_using_lambda(const std::vector<std::string>& vec, int n) {
    return std::count_if(
        vec.begin(),
        vec.end(),
        [n](std::string str) { return static_cast<int>(str.length()) == n;}
    );
}

size_t count_using_Functor(const std::vector<std::string>& vec, int n) {
    struct MyFunctor {
        int size;
        MyFunctor() = delete;
        MyFunctor(int n) : size{ n } {}
        bool operator()(std::string str) {
            return static_cast<int>(str.length()) == size;
        }
    };

    MyFunctor myFunc{ n };
    return std::count_if(
        vec.begin(),
        vec.end(),
        myFunc
    );
}

bool freeFunc(std::string str, int size) {
    return static_cast<int>(str.length()) == size;
}


size_t count_using_Free_Func(const std::vector<std::string>& vec, int n) {
    auto unaryFreeFunc = std::bind(freeFunc, std::placeholders::_1, n);

    return count_if(
        vec.begin(),
        vec.end(),
        unaryFreeFunc);
}

void multisetUsingMyComparator(const std::vector<std::string>& vec) {
    struct Compare {
        bool operator()(const std::string& s1, const std::string& s2) const {
            if (s1.length() == s2.length()) {
                return s1 < s2;
            }
            return s1.length() < s2.length();
        }
    };
    std::multiset<std::string, Compare> stringSet;

    std::copy(vec.begin(), vec.end(), std::inserter(stringSet, stringSet.begin()));

    std::ostream_iterator<std::string> out(std::cout, " ");

    std::copy(stringSet.begin(), stringSet.end(), out);

}

std::vector<int> getnerate_Fibonacci(int n) {
    struct FibGenerator {
        int temp;
        int previous = 0;
        int current = 1;
        int operator()() {
            temp = previous + current;
            previous = current;
            current = temp;
            return previous;
        }
    };
    std::vector<int> fib(n);
    std::generate(fib.begin(), fib.end(), FibGenerator());
    return fib;
}



