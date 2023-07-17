#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int h, int w, char p = '*', std::string n = "Door");
    ~Rectangle() = default;

    double areaGeo() const override;
    double perimeterGeo() const override;
    int areaScr() const override;
    int perimeterScr() const override;

    Canvas draw() const override;
};

#endif