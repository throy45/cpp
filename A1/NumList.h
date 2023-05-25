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
    NumList(const NumList &other); // pass by reference to prevent copying
    NumList(NumList &&other);
    NumList &operator=(const NumList &other);
    NumList &operator=(NumList &&other);
    virtual ~NumList();
    bool empty() const;
    bool full() const;
    int size() const;
    int getCapacity() const;
    bool contains(int num) const; // const functions are not allowed to change member variables
    void append(int num);
    void print(std::ostream &sout) const;
    int get(int index) const;
    bool get(int index, int &value) const;
    friend std::ostream &operator<<(std::ostream &out, const NumList &list);
};

#endif