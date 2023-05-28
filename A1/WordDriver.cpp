#include <iostream>
#include <cassert>
#include "Word.h"

using std::cout;
using std::endl;

Word makeWord(const char *word, int number)
{
    Word w1{word, number};
    return w1; // return a temporary
}

void testWord()
{
    std::cout << "Testing Objects of Class Word\n";
    Word w1{makeWord("Hello", 11)}; // move ctor
    // cout << w1 << endl; // ideal way to print w1 (easy to implement)
    cout << "A) w1: " << w1 << endl;
    w1 = makeWord("Goodbye", 22); // move assignment
    cout << "B) w1: " << w1 << endl;
    w1.appendNumber(33);
    w1.appendNumber(44);
    w1.appendNumber(55);
    w1.appendNumber(66);
    cout << "C) w1: " << w1 << endl;
    ;

    Word w2 = w1; // copy constructor (not copy assignment)
    w1.appendNumber(77);
    cout << "D) w1: " << w1 << endl;
    cout << "E) w2: " << w2 << endl;

    w2 = w1; // copy assignment
    cout << "F) w1: " << w1 << endl;
    cout << "G) w2: " << w2 << endl;

    Word w3 = std::move(w2); // move constructor
    cout << "H) w3: " << w3 << endl;
    cout << "I) w2: " << w2 << endl;
    //  warning C26800: Use of a moved from object
    w1 = std::move(w3); // move assignment
    cout << "J) w3: " << w3 << endl;
    //  warning C26800: Use of a moved from object
    cout << "K) w1: " << w1 << endl;

    NumList ia = w1.getNumberList();
    cout << "L) ia: " << ia << endl;

    const char *pCstr = w1.c_str();
    cout << "M) length of w1: " << pCstr << " = " << std::strlen(pCstr);
    cout << "\n";
}