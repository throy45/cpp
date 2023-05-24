#include "NumList.h"
#include <iostream>

NumList::NumList() : pArray{new int{}}, mcapacity{1}, msize{0} {};
NumList::NumList(const NumList &other) : msize{other.msize}, mcapacity{other.mcapacity}, pArray{new int[other.mcapacity]} {};
NumList::NumList(NumList &&other)
{
    this->pArray = other.pArray;
    other.pArray = nullptr;
    this->mcapacity = other.mcapacity;
    this->msize = other.msize;
};
NumList &NumList::operator=(const NumList &other)
{
    if (this == &other)
        return *this;
    delete[] this->pArray;
    int len = other.getCapacity();
    this->pArray = new int[len];
    for (int k = 0; k < len; ++k)
    {
        pArray[k] = other.pArray[k];
    }
    return *this;
};
NumList &NumList::operator=(NumList &&other)
{
    if (this == &other)
        return *this;
    delete[] this->pArray;
    this->pArray = other.pArray;
    other.pArray = nullptr;
    this->mcapacity = other.mcapacity;
    this->msize = other.msize;
    return *this;
};

NumList::~NumList()
{
    delete pArray;
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
    return msize == 0;
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
bool NumList::contains(int num) const
{
    for (int k = 0; k < msize; ++k)
    {
        if (pArray[k] == num)
        {
            return true;
        }
    }
    return false;
};
void NumList::append(int num)
{
    if (full())
    {
        expand();
    }
    pArray[msize] = num;
    ++msize;
};
void NumList::print(std::ostream &sout) const
{
    for (int k = 0; k < msize; ++k)
    {
        sout << pArray[k] << ", ";
    }
};
int NumList::get(int index) const
{
    if (index > msize)
    {
        throw std::out_of_range("Index out of range");
    }
    return pArray[index];
};
bool NumList::get(int index, int &value) const
{
    if (index > msize)
    {
        return false;
    }
    value = pArray[index];
    return true;
};

std::ostream &operator<<(std::ostream &out, const NumList &list)
{
    for (int k = 0; k < list.size(); ++k)
    {
        out << list.get(k) << " ";
    }
    return out;
};