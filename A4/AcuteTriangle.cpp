#include "AcuteTriangle.h"
#include <cmath>

AcuteTriangle::AcuteTriangle(int b, char p, std::string n) : Triangle(b, p, n)
{
    if (b % 2 == 0)
    { // b is even, add 1
        Shape::setHeight((b + 2) / 2);
        Triangle::setWidth(b + 1);
    }
    else {
        Shape::setHeight((b + 1) / 2);
        Triangle::setWidth(b);
    }
}

void AcuteTriangle::setHeight(int h)
{
    if ((2 * h - 1) % 2 == 0)
    { // b is even, add 1
        Shape::setHeight(h);
        Triangle::setWidth(2 * h);
    }
    else {
        Shape::setHeight(h);
        Triangle::setWidth(2 * h - 1);

    }
}

void AcuteTriangle::setWidth(int b)
{
    if (b % 2 == 0)
    { // b is even, add 1
        Shape::setHeight((b + 2) / 2);
        Triangle::setWidth(b + 1);
    }
    else {
        Shape::setHeight((b + 1) / 2);
        Triangle::setWidth(b);
    }
}

double AcuteTriangle::perimeterGeo() const
{
    return getBase() + std::sqrt(getBase() * getBase() + 4 * getHeight() * getHeight());
}

int AcuteTriangle::areaScr() const
{
    return getHeight() * getHeight();
}

int AcuteTriangle::perimeterScr() const
{
    return 4 * (getHeight() - 1);
}

Canvas AcuteTriangle::draw() const
{
    char p = getPen();
    int h = getHeight();
    int w = getWidth();
    Canvas can{ h, w };
    for (int i = 0; i < h; ++i)
    { // i is the row
        for (int j = 0; j < w; ++j)
        { // j is the column
            // If: j is greater than or equal to the height - i - 1
            // and j is less than or equal to the height + i - 1
            // Then: put a star
            if (j >= h - i - 1 && j <= h + i - 1)
            {
                can.put(i, j, p);
            }
        }
    }
    return can;
}