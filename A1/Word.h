#ifndef WORD_H
#define WORD_H

#include <iostream>
#include "NumList.h"

class Word
{
    int *pCharArray;
    int frequency;
    NumList num_list;

public:
    Word(const char pChArray[], int n);
    Word();
    Word(const Word &other);
    Word(Word &&other);
    Word &operator=(const Word &other);
    Word &operator=(Word &&other);
    virtual ~Word();
    const char *c_str() const;
    void appendNumber(int n);
    size_t size() const;
    void print(std::ostream &sout) const;
    const NumList &getNumberList() const;
    int compare(const Word &other) const;
};

#endif