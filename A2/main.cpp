#include <iostream>
#include <string>
#include "Dictionary.h"

using std::cin;
using std::cout;
using std::string;

void testNumList();
void testWord();
void testWordList();

/**
 * The main function reads in a filename, creates a dictionary object from the file, and prints the
 * dictionary.
 *
 * @return The main function is returning an integer value of 0, which indicates that the program has
 * executed successfully.
 */
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
