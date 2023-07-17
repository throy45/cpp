#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape {
    int base;
public:
    Triangle() = delete;
    Triangle(int b, char p = '*', std::string n = "Triangle");
    virtual ~Triangle() = default; // unsure if must be virtual since Shape is virtual

    void setHeight(int h) override = 0;
    void setWidth(int w) override;
    int getBase() const;
    void setBase(int b);

    double areaGeo() const override;
    double perimeterGeo() const override = 0;
    int areaScr() const override = 0;
    int perimeterScr() const override = 0;

    Canvas draw() const override = 0;
};

#endif