#include "RightTriangle.h"
#include <cmath>

RightTriangle::RightTriangle(int b) : Triangle(b)
{}

void RightTriangle::setHeight(int h)
{
    Triangle::setHeight(h);
    Triangle::setWidth(h);
}

double RightTriangle::perimeterGeo() const
{
    return (2 + std::sqrt(2.0)) * getHeight();
}

int RightTriangle::areaScr() const
{
    return getHeight() * (getHeight() + 1) / 2;
}

int RightTriangle::perimeterScr() const
{
    return 3 * (getHeight() - 1);
}

Canvas RightTriangle::draw() const
{
    Canvas can{ getHeight(), getHeight() };
    for (int i = 0; i < getHeight(); ++i)
    { // i is the row
        for (int j = 0; j < getHeight(); ++j)
        { // j is the column
            if (j <= i)
            {
                can.put(i, j, '*');
            }
        }
    }
    return can;
}