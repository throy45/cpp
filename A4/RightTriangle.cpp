#include "RightTriangle.h"
#include <cmath>

/**
 * The RightTriangle constructor initializes a RightTriangle object with a given base, character for
 * printing, and name, by calling the Triangle constructor.
 *
 * @param b The parameter "b" represents the length of the base of the right triangle.
 * @param p The parameter "p" is of type char and represents the character used to draw the triangle.
 * @param n The parameter "n" is a string that represents the name of the right triangle.
 */
RightTriangle::RightTriangle(int b, char p, std::string n) : Triangle(b, p, n)
{}

/**
 * The function sets the height of a right triangle by setting the height of a shape and the width of a
 * triangle to the same value.
 *
 * @param h The parameter "h" is an integer representing the height of the right triangle.
 */
void RightTriangle::setHeight(int h)
{
    Shape::setHeight(h);
    Triangle::setWidth(h);
}

/**
 * The function calculates the perimeter of a right triangle using geometric properties.
 *
 * @return The perimeter of the right triangle in geometric units.
 */
double RightTriangle::perimeterGeo() const
{
    return (2 + std::sqrt(2.0)) * getHeight();
}

/**
 * The function calculates the area of a right triangle using the height.
 *
 * @return The area of the right triangle is being returned.
 */
int RightTriangle::areaScr() const
{
    return getHeight() * (getHeight() + 1) / 2;
}

/**
 * The function calculates the perimeter of a right triangle.
 *
 * @return The perimeter of the right triangle is being returned.
 */
int RightTriangle::perimeterScr() const
{
    return 3 * (getHeight() - 1);
}

/**
 * The function draws a right triangle using a specified pen character and height.
 *
 * @return a Canvas object.
 */
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