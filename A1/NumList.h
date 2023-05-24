#ifndef FOO_H
#define FOO_H

#include <iostream>

class NumList
{
    int *pArray;
    int mcapacity;
    int msize;
    void expand();

public:
    NumList();
    NumList(const NumList &other);
    NumList(NumList &&other);
    NumList &operator=(const NumList &other);
    NumList &operator=(NumList &&other);
    ~NumList();
    bool empty() const;
    bool full() const;
    int size() const;
    int getCapacity() const;
    bool contains(int num) const;
    void append(int num);
    void print(std::ostream &sout) const;
    int get(int index) const;
    bool get(int index, int &value) const;
    friend std::ostream &operator<<(std::ostream &out, const NumList &list);
};

#endif