#include "Rectangle.h"

/**
 * The Rectangle constructor initializes a Rectangle object with the given height, width, pattern, and
 * name.
 *
 * @param h The height of the rectangle.
 * @param w The parameter "w" represents the width of the rectangle.
 * @param p The parameter "p" is of type char and represents the character used to draw the shape.
 * @param n The parameter "n" is a string that represents the name of the rectangle.
 */
Rectangle::Rectangle(int h, int w, char p, std::string n) : Shape(h, w, p, n) {}

/**
 * The function calculates the area of a rectangle using its height and width.
 *
 * @return The area of the rectangle as a double value.
 */
double Rectangle::areaGeo() const {
    return static_cast<double>(getHeight()) * getWidth();
}

/**
 * The function calculates the perimeter of a rectangle using its height and width.
 *
 * @return The perimeter of the rectangle in geometric units.
 */
double Rectangle::perimeterGeo() const {
    return 2.0 * (getHeight() + getWidth());
}

/**
 * The function calculates the area of a rectangle.
 *
 * @return The area of the rectangle is being returned.
 */
int Rectangle::areaScr() const {
    return getHeight() * getWidth();
}

/**
 * The function calculates the perimeter of a rectangle, taking into account the special case when the
 * height or width is less than or equal to 1.
 *
 * @return the perimeter of the rectangle. If both the height and width of the rectangle are greater
 * than 1, it calculates the perimeter using the formula 2 * (height + width) - 4. Otherwise, it
 * returns the product of the height and width, which represents the area of the rectangle.
 */
int Rectangle::perimeterScr() const {
    if (getHeight() > 1 && getWidth() > 1) {
        return 2 * (getHeight() + getWidth()) - 4;
    }
    else {
        return getHeight() * getWidth();
    }
}

/**
 * The function draws a rectangle on a canvas by filling it with a specified pen character.
 *
 * @return a Canvas object.
 */
Canvas Rectangle::draw() const {
    char p = getPen();
    int h = getHeight();
    int w = getWidth();
    Canvas can{ h, w };
    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            can.put(row, col, p);
        }
    }
    return can;
}
