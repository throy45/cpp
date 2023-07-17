#include "AcuteTriangle.h"
#include <cmath>

/**
 * The AcuteTriangle constructor sets the height and width of the triangle based on the given base
 * value, ensuring that the triangle is acute.
 *
 * @param b The parameter "b" represents the base length of the acute triangle.
 * @param p The parameter "p" is of type char and represents the character used to draw the triangle.
 * @param n n is a string parameter that represents the name of the AcuteTriangle object.
 */
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

/**
 * The function sets the height and width of an acute triangle based on the given height value.
 *
 * @param h The parameter "h" represents the height of the acute triangle.
 */
void AcuteTriangle::setHeight(int h)
{
    if (h <= 0)
    {
        throw std::invalid_argument("Height must be positive");
    }
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

/**
 * The function sets the width of an acute triangle based on the given input, ensuring that the width
 * is odd.
 *
 * @param b The parameter "b" represents the width of the acute triangle.
 */
void AcuteTriangle::setWidth(int b)
{
    if (b <= 0)
    {
        throw std::invalid_argument("Width must be positive");
    }
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

/**
 * The function calculates the geometric perimeter of an acute triangle using its base and height.
 *
 * @return The perimeter of the acute triangle.
 */
double AcuteTriangle::perimeterGeo() const
{
    return getBase() + std::sqrt(getBase() * getBase() + 4 * getHeight() * getHeight());
}

/**
 * The function calculates the screen area of an acute triangle using the height of the triangle.
 *
 * @return The area of the acute triangle.
 */
int AcuteTriangle::areaScr() const
{
    return getHeight() * getHeight();
}

/**
 * The function calculates the screen perimeter of an acute triangle.
 *
 * @return the perimeter of the acute triangle.
 */
int AcuteTriangle::perimeterScr() const
{
    return 4 * (getHeight() - 1);
}

/**
 * The function `draw` creates a canvas and draws an acute triangle on it using a specified pen
 * character.
 *
 * @return a Canvas object.
 */
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