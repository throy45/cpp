#ifndef NUMLIST_H
#define NUMLIST_H

#include <iostream>

class NumList
{
    int *pArray;
    int mcapacity;
    int msize;
    void expand();

public:
    NumList();                     // = delete if we wanted to prevent empty instances
    NumList(const NumList &array); // pass by reference to prevent copying
    NumList(NumList &&array);
    NumList &operator=(const NumList &rhs);
    NumList &operator=(NumList &&rhs);
    virtual ~NumList();
    bool empty() const;
    bool full() const;
    int size() const;
    int getCapacity() const;
    bool contains(int x) const; // const functions are not allowed to change member variables
    void append(int x);
    void print(std::ostream &sout) const;
    int get(int index) const;
    bool get(int index, int &value) const;
    friend std::ostream &operator<<(std::ostream &sout, const NumList &list);
};

#endif