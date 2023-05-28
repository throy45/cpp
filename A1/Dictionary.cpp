#include "Dictionary.h"

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

void Dictionary::processWord(const string &word, int linenum)
{
    size_t index = bucketIndex(word);
    wordListBuckets[index].addSorted(word, linenum);
}

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

std::ostream &operator<<(std::ostream &sout, const Dictionary &dict)
{
    dict.print(sout);
    return sout;
}