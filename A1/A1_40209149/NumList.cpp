#include "NumList.h"

/**
 * This is the default constructor for the NumList class that initializes an empty array and sets
 * the capacity to 1.
 */
NumList::NumList() : pArray{new int[1]}, mcapacity{1}, msize{0} {}; // default ctor

/**
 * This is a copy constructor for the NumList class that creates a new object with the same size and
 * capacity as the input object and copies its elements.
 *
 * @param array The parameter "array" is a constant reference to an object of the class NumList, which
 * is being passed as an argument to the copy constructor of the same class.
 */
NumList::NumList(const NumList &array) : msize{array.msize}, mcapacity{array.mcapacity}, pArray{new int[array.mcapacity]}
{ // copy ctor
    for (int k = 0; k < array.msize; ++k)
    {
        pArray[k] = array.pArray[k];
    }
};

/**
 * This is a move constructor for the NumList class in C++.
 *
 * @param array A reference to a NumList object that is being moved from.
 */
NumList::NumList(NumList &&array) : msize{array.msize}, mcapacity{array.mcapacity}, pArray{array.pArray}
{ // move ctor
    array.pArray = nullptr;
    array.mcapacity = 0;
    array.msize = 0;
};

/**
 * This is a copy assignment operator for a NumList class that copies the contents of one object to
 * another.
 *
 * @return The copy assignment operator is returning a reference to the current object, which is
 * represented by the pointer `this`. This is done using the dereference operator `*` to return the
 * object itself, rather than a pointer to it.
 */
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

/**
 * This is a move assignment operator for a NumList class in C++.
 *
 * @return The move assignment operator is returning a reference to the current object, which is of
 * type NumList&.
 */
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

/**
 * This is a destructor for the NumList class in C++ that deletes the dynamically allocated array
 * pArray.
 */
NumList::~NumList()
{
    delete[] pArray;
};

/**
 * The function expands the capacity of a dynamic array by creating a new array with double the
 * capacity and copying the elements from the old array to the new one.
 */
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

/**
 * The function checks if the NumList object is empty and returns a boolean value accordingly.
 *
 * @return A boolean value indicating whether the NumList object is empty or not. If the size of the
 * list (msize) is equal to 0, then the function returns true, indicating that the list is empty.
 * Otherwise, it returns false, indicating that the list is not empty.
 */
bool NumList::empty() const
{
    return msize == 0; // return msize==0 ? true : false;
};

/**
 * This function checks if the NumList object is full by comparing its size to its capacity.
 *
 * @return The function `full()` returns a boolean value indicating whether the `msize` member variable
 * of the `NumList` object is equal to its `mcapacity` member variable. If `msize` is equal to
 * `mcapacity`, then the function returns `true`, indicating that the list is full. Otherwise, it
 * returns `false`, indicating that there is still space in the list to add
 */
bool NumList::full() const
{
    return msize == mcapacity;
};

/**
 * The function returns the size of a NumList object.
 *
 * @return the value of the member variable `msize`, which represents the size of the `NumList` object.
 */
int NumList::size() const
{
    return msize;
};

/**
 * This function returns the capacity of a NumList object.
 *
 * @return the value of the member variable `mcapacity`, which represents the maximum capacity of the
 * NumList object.
 */
int NumList::getCapacity() const
{
    return mcapacity;
};

/**
 * The function checks if an integer is present in an array and returns true if it is, false otherwise.
 *
 * @param x x is an integer value that is being checked for existence in the NumList object. The
 * function iterates through the array of integers in the object and returns true if it finds a match
 * for x, and false if it does not.
 * @return The function `contains` returns a boolean value (`true` or `false`). It returns `true` if
 * the integer `x` is found in the `pArray` array, and `false` otherwise.
 */
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

/**
 * The function appends an integer to an array if it is not already in the array and expands the array
 * if it is full.
 *
 * @param x x is an integer value that is being added to the end of the NumList.
 * @return If the `contains(x)` condition is true, the function will return without doing anything.
 */
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

/**
 * The function prints the elements of an array separated by commas.
 *
 * @param sout sout is a reference to an output stream object (e.g. std::cout) that is used to print
 * the elements of the NumList object to the console or to a file. The function uses the << operator to
 * output each element of the NumList object to the output stream.
 */
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

/**
 * This function returns the value at a given index in an array, throwing an exception if the index is
 * out of range.
 *
 * @param index The index parameter is an integer representing the position of the element in the array
 * that we want to retrieve.
 * @return an integer value, which is the element at the specified index in the array.
 */
int NumList::get(int index) const
{
    if (index >= msize)
    {
        throw std::out_of_range("Index out of range");
    }
    return pArray[index];
};

/**
 * This function retrieves the value at a specified index in an array and returns true if the index is
 * within the array's bounds.
 *
 * @param index The index parameter is an integer that represents the position of the element in the
 * array that we want to retrieve.
 * @param value A reference to an integer variable that will be used to store the value at the
 * specified index in the NumList object.
 * @return A boolean value is being returned.
 */
bool NumList::get(int index, int &value) const
{
    if (index >= msize)
    {
        return false;
    }
    value = pArray[index];
    return true;
};

/**
 * This is an overloaded operator function that prints the contents of a NumList object to an output
 * stream.
 *
 * @return The `std::ostream` object `sout` is being returned.
 */
std::ostream &operator<<(std::ostream &sout, const NumList &list)
{
    list.print(sout);
    return sout;
};