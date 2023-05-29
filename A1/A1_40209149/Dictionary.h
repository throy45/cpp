#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "WordList.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::string;

class Dictionary
{
    string filename;
    WordList wordListBuckets[27]; // 26 alpha buckets + 1 none-alpha bucket
    size_t bucketIndex(const string &word) const;

public:
    Dictionary(const string &filename);
    void processWord(const string &word, int linenum);
    void print(ostream &out) const;
    Dictionary() = delete;                               // no default ctor
    ~Dictionary() = default;                             // default dtor
    Dictionary(const Dictionary &) = default;            // copy ctor
    Dictionary(Dictionary &&) = default;                 // move ctor
    Dictionary &operator=(const Dictionary &) = default; // copy assignment
    Dictionary &operator=(Dictionary &&) = default;      // move assignment
    friend std::ostream &operator<<(std::ostream &sout, const Dictionary &dict);
};
#endif