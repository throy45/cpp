#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include <vector>

using std::ostream;
using std::string;
using std::vector;

class Word
{
    string text;
    vector<size_t> line_number_vec;
    size_t frequency{1};

public:
    Word(string text, size_t line_number);
    Word() = delete;
    Word(const Word &source) = default;         // copy ctor
    Word(Word &&source) = default;              // move ctor
    Word &operator=(const Word &rhs) = default; // copy op=
    Word &operator=(Word &&rhs) = default;      // move op=
    ~Word() = default;                          // dtor
    int compare(const Word &other) const;
    void print(std::ostream &sout) const;
    string get_word_text() const;
    int get_frequency() const;
    vector<size_t> get_number_list() const;
    size_t length() const;
    void increment_frequency();
    void push_back_line_number(size_t lineNum);
};
ostream &operator<<(ostream &sout, const Word &word);
bool operator<(const Word &lhs, const Word &rhs);
bool is_shorter(const Word &lhs, const Word &rhs);
bool is_less_frequent(const Word &lhs, const Word &rhs);

#endif