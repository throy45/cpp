#include "Word.h"

Word::Word(string textIn, size_t line_number) : text{textIn}, frequency{1}
{
    line_number_vec.push_back(line_number);
};

int Word::compare(const Word &other) const
{
    return text.compare(other.text);
};

void Word::print(std::ostream &sout) const
{
    sout << text << " (" << frequency << ") ";
    for (auto i : line_number_vec)
    {
        sout << i << " ";
    }
};

string Word::get_word_text() const
{
    return text;
};

int Word::get_frequency() const
{
    return frequency;
};

vector<size_t> Word::get_number_list() const
{
    return line_number_vec;
};

size_t Word::length() const
{
    return text.length();
};

void Word::increment_frequency()
{
    frequency++;
};

void Word::push_back_line_number(size_t lineNum)
{
    line_number_vec.push_back(lineNum);
};

/**
 * This is an overloaded operator function that prints a Word object to an output stream.
 *
 * @return The `operator<<` function returns a reference to the `std::ostream` object `sout`.
 */
std::ostream &operator<<(std::ostream &sout, const Word &word)
{
    word.print(sout);
    return sout;
};

bool operator<(const Word &lhs, const Word &rhs)
{
    return lhs.compare(rhs) < 0;
};

bool is_shorter(const Word &lhs, const Word &rhs)
{
    if (lhs.length() == rhs.length())
    {
        return lhs < rhs;
    }
    return lhs.length() < rhs.length();
};

bool is_less_frequent(const Word &lhs, const Word &rhs)
{
    if (lhs.get_frequency() == rhs.get_frequency())
    {
        return lhs < rhs;
    }
    return lhs.get_frequency() < rhs.get_frequency();
};