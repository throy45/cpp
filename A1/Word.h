#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include "NumList.h"

class Word // delimited by space or \t
{
    char *pCharArray; // a pointer to an array of characters, c-string
    int frequency;
    NumList num_list; // list of line numbers

public:
    Word(const char *pChArr, int n);
    Word() = delete; // no default ctor
    Word(const Word &word);
    Word(Word &&word);
    Word &operator=(const Word &rhs);
    Word &operator=(Word &&rhs);
    virtual ~Word();
    const char *c_str() const;
    void appendNumber(int n);
    size_t size() const;
    void print(std::ostream &sout) const;
    const NumList &getNumberList() const;
    int compare(const Word &other) const;
    friend std::ostream &operator<<(std::ostream &sout, const Word &word);
};

#endif