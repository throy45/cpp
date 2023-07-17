#ifndef SHAPE_H_
#define SHAPE_H_


#include <string>
#include <typeinfo>
#include <stdexcept>
#include <iostream>
#include "Canvas.h"

class Shape {
    int height;
    int width;
    std::string name;
    char pen;
    int id;
    static int nextId;

public:
    Shape(int h, int w, char p = '*', std::string n = "Shape");

    Shape() = delete;
    Shape(const Shape& other) = delete;
    Shape(Shape&& other) = delete;
    Shape& operator=(const Shape& other) = delete;
    Shape& operator=(Shape&& other) = delete;
    virtual ~Shape() = default;

    int getHeight() const;
    int getWidth() const;
    std::string getName() const;
    char getPen() const;
    int getId() const;

    virtual void setHeight(int h);
    virtual void setWidth(int w);
    void setName(std::string n);
    void setPen(char p);

    std::string toString() const;


    virtual double areaGeo() const = 0;
    virtual double perimeterGeo() const = 0;
    virtual int areaScr() const = 0;
    virtual int perimeterScr() const = 0;

    virtual Canvas draw() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Shape& s);



#endif