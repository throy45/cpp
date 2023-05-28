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
    std::ifstream fin;
    fin.open(filename); // create an input file stream
    if (!fin)
    {
        cout << "could not open input file: " << filename << endl;
        exit(1);
    }
    int linenum = 0;
    string line;
    getline(fin, line); // very important first attempt to read;
    // this first attempt will get the i/o flags initialized
    while (fin)
    {
        // cout << line << endl;
        ++linenum;               // count the line
        istringstream sin(line); // turn the line into an input string stream
        string wordStr;
        while (sin >> wordStr) // extract word strings
        {
            processWord(wordStr, linenum);
        }
        getline(fin, line); // attempt to read the next line, if any
    }
    fin.close();
}

void Dictionary::processWord(const string &word, int linenum)
{
    size_t index = bucketIndex(word);
    wordListBuckets[index].addSorted(word, linenum);
}

void Dictionary::print(ostream &sout) const
{
    for (size_t i = 0; i < 27; ++i)
    {
        sout << "bucket " << i << ": ";
        wordListBuckets[i].print(sout);
        sout << endl;
    }
}

std::ostream &operator<<(std::ostream &sout, const Dictionary &dict)
{
    dict.print(sout);
    return sout;
}