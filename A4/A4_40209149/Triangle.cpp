#include "Triangle.h"

/**
 * The Triangle constructor initializes a Triangle object with a given base, character, and name, using
 * the Shape constructor. Triangle is still an abstract class, so it cannot be instantiated.
 *
 * @param b The parameter "b" represents the base length of the triangle.
 * @param p The parameter "p" is of type char and represents the character used to draw the shape.
 * @param n The parameter "n" is a string that represents the name of the triangle.
 */
Triangle::Triangle(int b, char p, std::string n) : Shape(b, b, p, n) {
}

/**
 * The function sets the width of a triangle by setting its base.
 *
 * @param w The parameter "w" is an integer representing the width of the triangle.
 */
void Triangle::setWidth(int w) {
    setBase(w);
}

/**
 * The function "getBase" returns the width of the triangle.
 *
 * @return The `getBase()` function is returning the width of the triangle.
 */
int Triangle::getBase() const {
    return getWidth();
}

/**
 * The function sets the base of a triangle shape, throwing an exception if the base is not positive.
 *
 * @param b The parameter "b" represents the value of the base of the triangle.
 */
void Triangle::setBase(int b) {
    if (b <= 0) {
        throw std::invalid_argument("Base must be positive");
    }
    Shape::setWidth(b);
    base = b;
}

/**
 * The function calculates the area of a triangle using its height and base.
 *
 * @return The area of the triangle is being returned.
 */
double Triangle::areaGeo() const {
    return getHeight() * getBase() / 2.0;
}
