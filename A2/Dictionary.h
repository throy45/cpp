#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include <set>
#include <forward_list>
#include <iomanip>

#include "Word.h"

using std::array;
using std::forward_list;
using std::list;
using std::ostream;
using std::set;
using std::string;
using std::vector;

class Dictionary
{
    string filename;
    const string theDelimiters;
    vector<string> input_lines;
    array<list<Word>, 27> wordListBuckets; // 26 alpha buckets + 1 none-alpha bucket
    size_t bucket_index(const string &wordText) const;
    vector<string> extract_words_from_line(const string &line) const;
    void push_back_into_bucket(const string &wordText, size_t &lineNumber);
    void extract_and_push(const string &line, size_t &lineNumber);

public:
    explicit Dictionary(const string &input_text_file, const string &delimiters = " \t\n");
    Dictionary() = delete;                               // no default ctor
    ~Dictionary() = default;                             // default dtor
    Dictionary(const Dictionary &) = default;            // copy ctor
    Dictionary(Dictionary &&) = default;                 // move ctor
    Dictionary &operator=(const Dictionary &) = default; // copy assignment
    Dictionary &operator=(Dictionary &&) = default;      // move assignment
    void print_input_lines(const set<size_t> &line_number_set) const;
    void print_original_buckets(const set<char> &charSet) const;
    void print_buckets_sorted_on_word_text(const set<char> &charSet) const;
    void print_buckets_sorted_on_word_frequency(const set<char> &charSet) const;
    void print_buckets_sorted_on_word_length(const set<char> &charSet) const;
    string get_filename() const { return filename; }
    string get_delimiters() const { return theDelimiters; }
};
#endif