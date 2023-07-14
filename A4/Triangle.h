#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape {
    int base;
public:
    Triangle() = delete;
    Triangle(int b);
    virtual ~Triangle() = default; // unsure if must be virtual since Shape is virtual

    void setHeight(int h) = 0;
    void setWidth(int w) override;
    int getBase() const;
    void setBase(int b);

    double areaGeo() const override;
    double perimeterGeo() const = 0;
    int areaScr() const = 0;
    int perimeterScr() const = 0;

    Canvas draw() const = 0;
};

#endif