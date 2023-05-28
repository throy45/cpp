#include "Word.h"

Word::Word(const char *pChArr, int n) : frequency{1}, num_list{}
{
    int len = strlen(pChArr);
    pCharArray = new char[len + 1];
    strcpy(pCharArray, pChArr);
    num_list.append(n);
};

Word::Word(const Word &word) : frequency{word.frequency}, num_list{word.num_list}
{
    int len = strlen(word.pCharArray);
    pCharArray = new char[len + 1];
    strcpy(pCharArray, word.pCharArray);
};

Word::Word(Word &&word) : frequency{word.frequency}, num_list{word.num_list}
{
    this->pCharArray = word.pCharArray;
    word.pCharArray = nullptr;
};

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

Word::~Word()
{
    delete[] pCharArray;
};

const char *Word::c_str() const
{
    return pCharArray;
};

void Word::appendNumber(int n)
{
    num_list.append(n);
    ++frequency;
};

size_t Word::size() const
{
    return strlen(pCharArray);
};

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

const NumList &Word::getNumberList() const
{
    return num_list;
};

int Word::compare(const Word &other) const
{ // both must be non-null
    return strcmp(this->pCharArray, other.pCharArray);
};

std::ostream &operator<<(std::ostream &sout, const Word &word)
{
    word.print(sout);
    return sout;
};