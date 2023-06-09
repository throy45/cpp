#include "Word.h"

/**
 * This is a constructor for the Word class that initializes the text and frequency variables and adds
 * the line number to a vector.
 *
 * @param textIn textIn is a string parameter that represents the text of a word. It is used to
 * initialize the "text" data member of the Word class.
 * @param line_number line_number is a variable of type size_t that represents the line number where
 * the Word object was found in a text document. It is used to keep track of the different lines where
 * the Word object appears and is stored in a vector called line_number_vec.
 */
Word::Word(string textIn, size_t line_number) : text{textIn}, frequency{1}
{
    line_number_vec.push_back(line_number);
};

/**
 * This function compares the text of two Word objects.
 *
 * @param other `other` is a reference to a `Word` object, which is being passed as a parameter to the
 * `compare` method of another `Word` object. The `compare` method is used to compare the `text` member
 * variable of the current `Word` object with the `text`
 * @return The `compare` function is returning the result of comparing the `text` member variable of
 * the current `Word` object with the `text` member variable of the `other` `Word` object. The
 * `compare` function of the `std::string` class is used to perform the comparison, which returns an
 * integer value indicating the relationship between the two strings. If the two strings are equal
 */
int Word::compare(const Word &other) const
{
    return text.compare(other.text);
};

/**
 * The function prints the word's text, frequency, and line numbers to an output stream.
 *
 * @param sout sout is a reference to an output stream (such as std::cout) where the output of the
 * print function will be directed to.
 */
void Word::print(std::ostream &sout) const
{
    sout << text << " (" << frequency << ") ";
    for (auto i : line_number_vec)
    {
        sout << i << " ";
    }
};

/**
 * This function returns the text of a Word object.
 *
 * @return The `text` member variable of the `Word` class is being returned as a `string`.
 */
string Word::get_word_text() const
{
    return text;
};

/**
 * This function returns the frequency of a word.
 *
 * @return The `get_frequency()` function is returning the value of the `frequency` member variable of
 * the `Word` class.
 */
int Word::get_frequency() const
{
    return frequency;
};

/**
 * The function returns a vector of line numbers where the word appears.
 *
 * @return A vector of size_t values representing the line numbers where the Word object appears in a
 * text document.
 */
vector<size_t> Word::get_number_list() const
{
    return line_number_vec;
};

/**
 * The function returns the length of the text in a Word object.
 *
 * @return The `length()` function returns the length of the `text` string in the `Word` object. The
 * `size_t` data type is used to represent the size of an object in bytes. Therefore, the function
 * returns the number of characters in the `text` string as a `size_t` value.
 */
size_t Word::length() const
{
    return text.length();
};

/**
 * The function increments the frequency of a word.
 */
void Word::increment_frequency()
{
    frequency++;
};

/**
 * This function adds a line number to a vector of line numbers in a Word object.
 *
 * @param lineNum lineNum is a parameter of type size_t, which represents the line number to be added
 * to the vector of line numbers in the Word class. This function, push_back_line_number, adds the line
 * number to the end of the vector using the push_back method.
 */
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

/**
 * This is an overloaded less than operator for comparing two Word objects.
 *
 * @param lhs A constant reference to a Word object, which is the left-hand side operand of the less
 * than operator.
 * @param rhs The parameter "rhs" is a reference to an object of the class "Word".
 * @return The `operator<` function is returning a boolean value that indicates whether the `lhs`
 * object is less than the `rhs` object, based on the result of calling the `compare` function on the
 * `lhs` object with the `rhs` object as an argument. If the result of the comparison is less than 0,
 * then `true` is returned, indicating that `lhs` is less than `rhs`. Otherwise, `false` is returned.
 */
bool operator<(const Word &lhs, const Word &rhs)
{
    return lhs.compare(rhs) < 0;
};

/**
 * The function compares two Word objects based on their length and returns true if the first one is
 * shorter or if they have the same length but the first one comes before the second one
 * alphabetically.
 *
 * @param lhs A constant reference to a Word object, representing the left-hand side of the comparison.
 * @param rhs The parameter "rhs" is a reference to a constant object of type "Word".
 * @return The function `is_shorter` returns a boolean value. It returns `true` if the length of the
 * `lhs` word is shorter than the length of the `rhs` word, or if the lengths are equal but the `lhs`
 * word comes before the `rhs` word in lexicographical order. Otherwise, it returns `false`.
 */
bool is_shorter(const Word &lhs, const Word &rhs)
{
    if (lhs.length() == rhs.length())
    {
        return lhs < rhs;
    }
    return lhs.length() < rhs.length();
};

/**
 * The function compares two Word objects based on their frequency and returns true if the frequency of
 * the first object is less than the frequency of the second object.
 *
 * @param lhs A constant reference to an object of the class "Word", representing the left-hand side of
 * the comparison operation.
 * @param rhs The "rhs" parameter is a reference to a constant object of the class "Word".
 * @return A boolean value indicating whether the frequency of the left-hand side `Word` object is less
 * than the frequency of the right-hand side `Word` object. If the frequencies are equal, it returns
 * the result of the `<` operator applied to the `lhs` and `rhs` objects.
 */
bool is_less_frequent(const Word &lhs, const Word &rhs)
{
    if (lhs.get_frequency() == rhs.get_frequency())
    {
        return lhs < rhs;
    }
    return lhs.get_frequency() < rhs.get_frequency();
};