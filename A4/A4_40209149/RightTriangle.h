#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
    RightTriangle() = delete;
    RightTriangle(int b, char p = '*', std::string n = "Ladder");
    virtual ~RightTriangle() = default;

    void setHeight(int h) override;

    double perimeterGeo() const override;
    int areaScr() const override;
    int perimeterScr() const override;

    Canvas draw() const override;
};

#endif