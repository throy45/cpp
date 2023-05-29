#include "Word.h"

/**
 * The function initializes a Word object with a character array and an integer, setting the frequency
 * to 1 and appending the integer to the numlist.
 *
 * @param pChArr A pointer to a character array (string) that represents the word being created.
 * @param n n is an integer parameter that represents the position of the word in the input text. It is
 * used to keep track of the order in which the words appear in the text.
 */
Word::Word(const char *pChArr, int n) : frequency{1}, num_list{}
{
    int len = strlen(pChArr);
    pCharArray = new char[len + 1];
    strcpy(pCharArray, pChArr);
    num_list.append(n);
};

/**
 * This is a copy constructor for the Word class that creates a deep copy of the input Word object.
 *
 * @param word The parameter "word" is a reference to an object of the class "Word".
 */
Word::Word(const Word &word) : frequency{word.frequency}, num_list{word.num_list}
{
    int len = strlen(word.pCharArray);
    pCharArray = new char[len + 1];
    strcpy(pCharArray, word.pCharArray);
};

/**
 * This is a move constructor for the Word class in C++, which moves the frequency, num_list, and
 * pCharArray data members from one Word object to another.
 *
 * @param word `word` is an rvalue reference to a `Word` object. It is used in a move constructor to
 * move the contents of `word` to a new `Word` object.
 */
Word::Word(Word &&word) : frequency{word.frequency}, num_list{word.num_list}
{
    this->pCharArray = word.pCharArray;
    word.pCharArray = nullptr;
};

/**
 * This is an overloaded assignment operator for the Word class that copies the contents of one Word
 * object to another.
 *
 * @return The overloaded assignment operator is returning a reference to the current object, which is
 * represented by the pointer `this`. The `*this` syntax is used to dereference the pointer and return
 * the object itself.
 */
Word &Word::operator=(const Word &rhs)
{
    if (this == &rhs)
        return *this;
    delete[] pCharArray;
    int len = strlen(rhs.pCharArray);
    this->pCharArray = new char[len + 1];
    strcpy(this->pCharArray, rhs.pCharArray);
    this->frequency = rhs.frequency;
    this->num_list = rhs.num_list;
    return *this;
};

/**
 * This is a move assignment operator for a Word class in C++.
 *
 * @return The `Word` object that was assigned to is being returned by reference (`*this`).
 */
Word &Word::operator=(Word &&rhs)
{
    if (this == &rhs)
        return *this;
    delete[] pCharArray;
    this->pCharArray = rhs.pCharArray;
    rhs.pCharArray = nullptr;
    this->frequency = rhs.frequency;
    this->num_list = rhs.num_list;
    return *this;
};

/**
 * This is a destructor for the Word class in C++ that deletes the dynamically allocated character
 * array.
 */
Word::~Word()
{
    delete[] pCharArray;
};

/**
 * The function returns a pointer to a character array representing the string stored in a Word object.
 *
 * @return a pointer to a constant character array (string) `pCharArray`.
 */
const char *Word::c_str() const
{
    return pCharArray;
};

/**
 * This function appends a number to a list and increments a frequency counter.
 *
 * @param n n is an integer value that is being appended to the num_list vector of the Word object. It
 * represents a numerical value that is associated with the Word object. The function also increments
 * the frequency variable of the Word object by 1.
 */
void Word::appendNumber(int n)
{
    num_list.append(n);
    ++frequency;
};

/**
 * The function returns the size of a character array representing a word.
 *
 * @return The size of the word, which is the length of the character array `pCharArray`. The function
 * `strlen()` returns the number of characters in a C-style string, excluding the null terminator.
 */
size_t Word::size() const
{
    return strlen(pCharArray);
};

/**
 * The function prints the word, its frequency, and a list of line numbers where it appears.
 *
 * @param sout sout is a reference to an output stream object, such as std::cout or a file stream
 * object. The print function uses this stream to output the contents of the Word object.
 * @return The function is not returning anything, it is simply printing the output to the provided
 * output stream.
 */
void Word::print(std::ostream &sout) const
{
    if (pCharArray == nullptr)
    {
        sout << "(0)";
        return;
    }
    sout << std::setw(15) << pCharArray << "  (" << frequency << ") ";
    num_list.print(sout);
};

/**
 * This function returns a constant reference to a NumList object stored in a Word object.
 *
 * @return A constant reference to the `num_list` member variable of the `Word` class.
 */
const NumList &Word::getNumberList() const
{
    return num_list;
};

/**
 * This function compares two Word objects by comparing their character arrays using the strcmp
 * function.
 *
 * @param other `other` is a reference to a `Word` object, which is being passed as a parameter to the
 * `compare` function. It is used to compare the `pCharArray` member variable of the current `Word`
 * object with the `pCharArray` member variable of the `other` `
 * @return the result of the comparison between the character arrays of the current Word object and the
 * other Word object using the `strcmp` function. The return value is an integer that indicates the
 * lexicographic relationship between the two character arrays. If the two character arrays are equal,
 * the function returns 0. If the current Word object's character array is greater than the other Word
 * object's character
 */
int Word::compare(const Word &other) const
{ // both must be non-null
    return strcmp(this->pCharArray, other.pCharArray);
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