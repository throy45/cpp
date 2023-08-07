/**
 * COMP 5421 Advanced C++ Programming
 * Assignment 5 - Due August 13th, 2023
 * Thomas Roy - 40291949
**/
#include "assignment5.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <set>

/**
 * The function reads words from a file into a vector.
 *
 * @param inFileName The name of the input file from which words will be read.
 * @return a vector of strings, which is declared as "WordsVector".
 */
WordsVector read_words_into_vector(const std::string& inFileName) {
    std::ifstream ifs(inFileName);
    if (!ifs.is_open()) {
        std::cout << "Could not open file " << inFileName << std::endl;
        throw std::runtime_error("Could not open file " + inFileName);
    }
    WordsVector words_vector;
    std::copy(
        std::istream_iterator<std::string>(ifs), // begin
        std::istream_iterator<std::string>(), // end
        std::back_inserter(words_vector)); // destination
    return words_vector;
}

/**
 * The function takes a vector of words, counts the occurrences of each word, and returns a map with
 * the word counts.
 *
 * @param wvec A vector of words (strings)
 * @return a WordsMap, which is a map where the keys are words (strings) and the values are the count
 * of occurrences of each word in the input WordsVector.
 */
WordsMap map_and_count_words_using_lambda(const WordsVector& wvec) {
    WordsMap wmap{};
    std::for_each(
        wvec.begin(),
        wvec.end(),
        [&wmap](const std::string& word) {++wmap[word];}); // lambda to increment the count of each word
    return wmap;
}

/**
 * The WordCountFunctor is a C++ struct that counts the occurrences of words in a text and stores the
 * results in a map.
 * @property {WordsMap} wmap - `wmap` is an object of type `WordsMap`. It is initialized with an empty
 * `WordsMap` using the default constructor.
 */
struct WordCountFunctor {
    WordsMap wmap{};
    void operator()(const std::string& word) { ++wmap[word]; }
    WordsMap getmap() { return wmap; }
};

/**
 * The function `map_and_count_words_using_functor` takes a vector of words, counts the occurrences of
 * each word using a functor, and returns a map of the word counts.
 *
 * @param wvec A vector of words (strings)
 * @return a WordsMap, which is a map that maps words to their respective counts.
 */
WordsMap map_and_count_words_using_functor(const WordsVector& wvec) {
    WordCountFunctor wcf{};
    wcf = std::for_each(
        wvec.begin(),
        wvec.end(),
        wcf); // functor to increment the count of each word
    return wcf.getmap();
}

/**
 * The function removes duplicate elements from a vector of words.
 *
 * @param words_vector A vector of strings containing words.
 * @return a new WordsVector that contains the unique elements from the input WordsVector.
 */
WordsVector remove_duplicates(const WordsVector& words_vector) {
    WordsVector words_vec{ words_vector };

    std::sort(words_vec.begin(), words_vec.end()); // sort the vector

    auto end = std::unique(words_vec.begin(), words_vec.end()); // remove duplicates

    words_vec.erase(end, words_vec.end()); // erase the removed elements

    return words_vec;
}

/**
 * The function checks if a character is not an alphabetic character.
 *
 * @param c The parameter "c" is a reference to a constant character.
 * @return The function is_not_alpha returns a boolean value indicating whether the character passed as
 * an argument is not an alphabetic character.
 */
bool is_not_alpha(const char& c) { return !isalpha(c); }

/**
 * The function `is_palindrome` checks if a given string is a palindrome by removing non-alphabetic
 * characters, converting all characters to uppercase, and comparing the first half of the string with
 * its reversed second half.
 *
 * @param phrase The `phrase` parameter is a constant reference to a `std::string` object, which
 * represents the input phrase that we want to check if it is a palindrome.
 * @return a boolean value indicating whether the given phrase is a palindrome or not.
 */
bool is_palindrome(const std::string& phrase) {
    std::string temp;
    auto back_inserter{ std::back_inserter(temp) };

    std::remove_copy_if( // remove non-alphabetic characters
        phrase.begin(),
        phrase.end(),
        back_inserter,
        is_not_alpha
    );

    std::transform( // convert all characters to uppercase
        temp.begin(),
        temp.end(),
        temp.begin(),
        [](char c) {return static_cast<char>(toupper(c));}
    );

    // check if the first half of the string is equal to its reversed second half
    bool result = std::equal(temp.begin(), temp.begin() + temp.length() / 2, temp.rbegin());

    return result;
}

/**
 * The function `count_using_lambda` counts the number of strings in a vector that have a length equal
 * to a given integer using a lambda function.
 *
 * @param vec A vector of strings that we want to count the number of strings with a specific length.
 * @param n The parameter `n` represents the length of the strings that we want to count in the vector
 * `vec`.
 * @return The function `count_using_lambda` returns a value of type `size_t`, which represents the
 * number of elements in the vector `vec` that satisfy the condition specified in the lambda function.
 */
size_t count_using_lambda(const std::vector<std::string>& vec, int n) {
    return std::count_if(
        vec.begin(),
        vec.end(),
        [n](std::string str) { return static_cast<int>(str.length()) == n;} // lambda function
    );
}

/**
 * The function `count_using_Functor` counts the number of strings in a vector that have a specific
 * length using a functor.
 *
 * @param vec A vector of strings that we want to count the number of strings with a specific length.
 * @param n The parameter `n` represents the desired length of a string. The functor `MyFunctor` checks
 * if a given string has a length equal to `n`. The function `count_using_Functor` uses this functor to
 * count the number of strings in the vector `vec` that have a
 * @return The function `count_using_Functor` returns a value of type `size_t`, which represents the
 * number of elements in the vector `vec` that satisfy the condition defined by the functor
 * `MyFunctor`.
 */
size_t count_using_Functor(const std::vector<std::string>& vec, int n) {
    /**
     * The below code defines a functor that checks if a given string has a specific length.
     * @property {int} size - The size property is an integer that represents the desired length of a
     * string.
     */
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

/**
 * The function checks if the length of a given string is equal to a given size.
 *
 * @param str A string that we want to check the length of.
 * @param size The size parameter is an integer that represents the expected size of the string.
 * @return a boolean value.
 */
bool freeFunc(std::string str, int size) {
    return static_cast<int>(str.length()) == size;
}


/**
 * The function `count_using_Free_Func` counts the number of elements in a vector that satisfy a
 * certain condition using a free function `freeFunc` with an additional parameter `n`.
 *
 * @param vec A vector of strings that we want to count elements from.
 * @param n The parameter `n` is an integer value that is passed to the `freeFunc` function.
 * @return The function `count_using_Free_Func` returns a value of type `size_t`.
 */
size_t count_using_Free_Func(const std::vector<std::string>& vec, int n) {
    // bind the function freeFunc to a unary function
    auto unaryFreeFunc = std::bind(freeFunc, std::placeholders::_1, n);

    return count_if(
        vec.begin(),
        vec.end(),
        unaryFreeFunc);
}



/**
 * The function `multisetUsingMyComparator` takes a vector of strings, creates a multiset using a
 * custom comparator that compares strings based on their lengths and lexicographical order, and then
 * prints the elements of the multiset.
 *
 * @param vec The parameter `vec` is a constant reference to a vector of strings.
 * @return The function does not have a return type, so it does not return anything.
 */
void multisetUsingMyComparator(const std::vector<std::string>& vec) {
    /**
     * The below code defines a struct called Comparator that overloads the () operator to compare two
     * strings based on their lengths and lexicographical order.
     *
     */
    struct Comparator {
        bool operator()(const std::string& s1, const std::string& s2) const {
            if (s1.length() == s2.length()) {
                return s1 < s2;
            }
            return s1.length() < s2.length();
        }
    };
    std::multiset<std::string, Comparator> stringSet;

    std::copy(vec.begin(), vec.end(), std::inserter(stringSet, stringSet.begin()));

    std::ostream_iterator<std::string> out(std::cout, " ");

    std::copy(stringSet.begin(), stringSet.end(), out);
}

void multisetUsingDefaultComparator(const std::vector<std::string>& vec)
{
    std::multiset<std::string> stringSet; // an empty string set

    // to print a sorted verstion of the supplied vector vec,
    // we first copy vec to our stringSet and then print the stringSet.

    // note: since std::multiset does not provide push_front or push_back members,
    // we can’t use a front or back inserter when we copy vec to our empty stringSet,
    // meaning that we must use a general inserter:

    std::copy(vec.begin(), vec.end(), // source start and finish.
        std::inserter(stringSet, stringSet.begin())); // destination start using
    // a general inserter.

    // create an ostream_iterator attached to cout, using a space " " as a separator
    std::ostream_iterator<std::string> out(std::cout, " ");

    // output the set elements to the cout
    std::copy(stringSet.begin(), stringSet.end(), out);
}

/**
 * The function generates the first n Fibonacci numbers and returns them in a vector.
 *
 * @param n The parameter `n` represents the number of Fibonacci numbers to generate.
 * @return a vector of integers containing the first n Fibonacci numbers.
 */
std::vector<int> getnerate_Fibonacci(int n) {
    struct FibGenerator {
        int temp;
        int previous = 0;
        int current = 0;
        int operator()() {
            if (current == 0) { // first iteration
                current = 1;
                return 0;
            }
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



