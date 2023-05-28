#include "NumList.h"

NumList::NumList() : pArray{new int[1]}, mcapacity{1}, msize{0} {}; // default ctor
NumList::NumList(const NumList &array) : msize{array.msize}, mcapacity{array.mcapacity}, pArray{new int[array.mcapacity]}
{ // copy ctor
    for (int k = 0; k < array.msize; ++k)
    {
        pArray[k] = array.pArray[k];
    }
};
NumList::NumList(NumList &&array) : msize{array.msize}, mcapacity{array.mcapacity}, pArray{array.pArray}
{ // move ctor
    array.pArray = nullptr;
    array.mcapacity = 0;
    array.msize = 0;
};
NumList &NumList::operator=(const NumList &rhs) // copy assignment operator
{
    if (this == &rhs) // if the address of the current object is the same as the address of the rhs object
        return *this; // where & is address and not reference in that context
    delete[] pArray;
    int cap = rhs.getCapacity();
    this->pArray = new int[cap];
    for (int k = 0; k < cap; ++k)
    {
        pArray[k] = rhs.pArray[k];
    }
    this->mcapacity = cap;
    this->msize = rhs.msize;
    return *this;
};
NumList &NumList::operator=(NumList &&rhs) // move assignment operator
{
    if (this == &rhs)
        return *this;
    delete[] pArray;
    this->pArray = rhs.pArray;
    rhs.pArray = nullptr;
    this->mcapacity = rhs.mcapacity;
    this->msize = rhs.msize;
    return *this;
};

NumList::~NumList()
{
    delete[] pArray;
};

void NumList::expand()
{
    int *temp = new int[mcapacity * 2];
    for (int k = 0; k < msize; ++k)
    {
        temp[k] = pArray[k];
    }
    delete[] pArray;
    pArray = temp;
    mcapacity *= 2;
};

bool NumList::empty() const
{
    return msize == 0; // return msize==0 ? true : false;
};
bool NumList::full() const
{
    return msize == mcapacity;
};
int NumList::size() const
{
    return msize;
};
int NumList::getCapacity() const
{
    return mcapacity;
};
bool NumList::contains(int x) const
{
    for (int k = 0; k < msize; ++k)
    {
        if (pArray[k] == x)
        {
            return true;
        }
    }
    return false;
};
void NumList::append(int x)
{
    if (contains(x))
    {
        return;
    }
    if (full())
    {
        expand();
    }
    pArray[msize] = x;
    ++msize;
};
void NumList::print(std::ostream &sout) const
{
    for (int k = 0; k < msize; ++k)
    {
        sout << pArray[k]; // same as *(pArray+k)
        if (k < msize - 1)
        {
            sout << ", ";
        }
    }
};
int NumList::get(int index) const
{
    if (index >= msize)
    {
        throw std::out_of_range("Index out of range");
    }
    return pArray[index];
};
bool NumList::get(int index, int &value) const
{
    if (index >= msize)
    {
        return false;
    }
    value = pArray[index];
    return true;
};

std::ostream &operator<<(std::ostream &sout, const NumList &list)
{
    list.print(sout);
    return sout;
};