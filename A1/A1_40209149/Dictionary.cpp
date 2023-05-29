#include "Dictionary.h"

/**
 * This function returns the bucket index of a given word in a dictionary based on its first letter.
 *
 * @param word The input parameter `word` is a constant reference to a string, which represents the
 * word for which we want to find the bucket index in the dictionary.
 * @return a size_t value which represents the bucket index of a given word in the dictionary.
 */
size_t Dictionary::bucketIndex(const string &word) const
{
    size_t index = 26; // bucket index for words not beginning with a letter
    if (isalpha(word[0]))
    {
        if (isupper(word[0]))
            index = word[0] - 'A';
        else
            index = word[0] - 'a';
    }
    return index;
}

/**
 * This function reads a file containing words, and processes each word.
 *
 * @param filename A string that represents the name of the file to be opened and read.
 */
Dictionary::Dictionary(const string &filename) : filename(filename)
{
    std::ifstream inputFile(filename);
    // inputFile.open(filename); // create an input file stream
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Could not open input file: " + filename);
    }
    int linenum = 0;
    string line;
    getline(inputFile, line); // very important first attempt to read;
    // this first attempt will get the i/o flags initialized
    while (inputFile)
    {
        // cout << line << endl;
        ++linenum;                                  // count the line
        std::istringstream inputStringStream(line); // turn the line into an input string stream
        string wordStr;
        while (inputStringStream >> wordStr) // extract word strings
        {
            processWord(wordStr, linenum);
        }
        getline(inputFile, line); // attempt to read the next line, if any
    }
    inputFile.close();
}

/**
 * This function adds a word to a dictionary, and stores the line number and frequency.
 *
 * @param word A string representing a word to be added to the dictionary.
 * @param linenum linenum is an integer parameter that represents the line number where the word was
 * found in a text document. This parameter is used in the function to add the word to the appropriate
 * linked list in the hash table bucket and to keep track of the line numbers where the word appears.
 */
void Dictionary::processWord(const string &word, int linenum)
{
    size_t index = bucketIndex(word);
    wordListBuckets[index].addSorted(word, linenum);
}

/**
 * This function prints the contents of a dictionary object, organized by alphabetical order.
 *
 * @param sout The parameter "sout" is a reference to an output stream (e.g. cout, ofstream) that is
 * used to print the contents of the dictionary to the console or a file.
 */
void Dictionary::print(ostream &sout) const
{
    sout << "=======================" << endl;
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < 27; ++i)
    {
        sout << "<" << letters[i] << ">" << endl;
        wordListBuckets[i].print(sout);
        sout << endl;
    }
}

/**
 * This is an overloaded operator function that prints the contents of a Dictionary object to an output
 * stream.
 *
 * @return The `operator<<` function returns a reference to the `std::ostream` object `sout`.
 */
std::ostream &operator<<(std::ostream &sout, const Dictionary &dict)
{
    dict.print(sout);
    return sout;
}