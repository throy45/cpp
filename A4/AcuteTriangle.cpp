#include "AcuteTriangle.h"
#include <cmath>

AcuteTriangle::AcuteTriangle(int b) : Triangle(b)
{
    if (b % 2 == 0)
    {
        throw std::invalid_argument("Base must be odd");
    }
}

void AcuteTriangle::setHeight(int b)
{
    if (b % 2 == 0)
    {
        throw std::invalid_argument("Base must be odd");
    }
    Triangle::setHeight((b + 1) / 2);
    Triangle::setWidth(b);
}

void AcuteTriangle::setWidth(int b)
{
    if (b % 2 == 0)
    {
        throw std::invalid_argument("Base must be odd");
    }
    Triangle::setWidth(b);
    Triangle::setHeight((b + 1) / 2);
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
    Canvas can{ getHeight(), getBase() };
    for (int i = 0; i < getHeight(); ++i)
    { // i is the row
        for (int j = 0; j < getBase(); ++j)
        { // j is the column
            // If: j is greater than or equal to the height - i - 1
            // and j is less than or equal to the height + i - 1
            // Then: put a star
            if (j >= getHeight() - i - 1 && j <= getHeight() + i - 1)
            {
                can.put(i, j, '*');
            }
        }
    }
    return can;
}