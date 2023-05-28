#include <iostream>
#include <string>
#include "Dictionary.h"

using std::cin;
using std::cout;
using std::string;

void testNumList();
void testWord();
void testWordList();

int main()
{
    // testNumList();
    // testWord();
    // testWordList();

    cout << "Enter the name of input text file: ";
    string filename;
    cin >> filename;
    Dictionary dictionary(filename);
    dictionary.print(cout);

    return 0; // 0 means success!
}
