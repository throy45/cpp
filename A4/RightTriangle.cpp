#include "RightTriangle.h"
#include <cmath>

RightTriangle::RightTriangle(int b, char p, std::string n) : Triangle(b, p, n)
{}

void RightTriangle::setHeight(int h)
{
    Shape::setHeight(h);
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
    char p = getPen();
    int h = getHeight();
    Canvas can{ h, h };
    for (int i = 0; i < h; ++i)
    { // i is the row
        for (int j = 0; j < h; ++j)
        { // j is the column
            if (j <= i)
            {
                can.put(i, j, p);
            }
        }
    }
    return can;
}