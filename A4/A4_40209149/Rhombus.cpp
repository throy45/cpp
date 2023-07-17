#include "Rhombus.h"

#include <cmath>

/**
 * The Rhombus constructor initializes a Rhombus object with a given diagonal length, pattern
 * character, and name.
 *
 * @param d The parameter "d" represents the length of the diagonal of the rhombus.
 * @param p The parameter "p" represents the character used to draw the shape.
 * @param n The parameter "n" is a string that represents the name of the rhombus.
 */
Rhombus::Rhombus(int d, char p, std::string n) : Shape(d, d, p, n) {
    setDiagonal(d);
}

/**
 * The function sets the height of a rhombus by setting its diagonal length.
 *
 * @param d The parameter "d" represents the height of the rhombus.
 */
void Rhombus::setHeight(int d) {
    if (d <= 0) {
        throw std::invalid_argument("Height must be positive");
    }
    setDiagonal(d);
}

/**
 * The function sets the width of a rhombus object and throws an exception if the width is not
 * positive.
 *
 * @param d The parameter "d" represents the width of the rhombus.
 */
void Rhombus::setWidth(int d) {
    if (d <= 0) {
        throw std::invalid_argument("Width must be positive");
    }
    setDiagonal(d);
}

/**
 * The function "getDiagonal" returns the height of the rhombus.
 *
 * @return The height of the rhombus.
 */
int Rhombus::getDiagonal() const {
    return getHeight();
}

/**
 * The function sets the height and width of a rhombus shape based on the given diagonal length,
 * rounding up if the diagonal is even.
 *
 * @param d The parameter "d" represents the length of the diagonal of the rhombus.
 */
void Rhombus::setDiagonal(int d) {
    if (d <= 0) {
        throw std::invalid_argument("Diagonal must be positive");
    }
    if (d % 2 == 0) { // if d is even, round up
        Shape::setHeight(d + 1);
        Shape::setWidth(d + 1);
    }
    else {
        Shape::setHeight(d);
        Shape::setWidth(d);
    }
    diagonal = d;
}

/**
 * The function calculates the area of a rhombus using its height.
 *
 * @return The area of the rhombus is being returned.
 */
double Rhombus::areaGeo() const {
    return getHeight() * getHeight() / 2.0;
}

/**
 * The function calculates the perimeter of a rhombus using its height.
 *
 * @return The perimeter of the rhombus is being returned.
 */
double Rhombus::perimeterGeo() const {
    return 2.0 * getHeight() * std::sqrt(2.0);
}

/**
 * The function calculates the area of a rhombus using its height.
 *
 * @return the area of the rhombus.
 */
int Rhombus::areaScr() const {
    int n = getHeight() / 2;
    return 2 * n * (n + 1) + 1;
}

/**
 * The function calculates the perimeter of a rhombus based on its height.
 *
 * @return the perimeter of the rhombus.
 */
int Rhombus::perimeterScr() const {
    if (getHeight() > 1) {
        return 2 * (getHeight() - 1);
    }
    else {
        return 1;
    }
}

/**
 * The function `draw()` creates a canvas object and draws a rhombus shape on it using the specified
 * pen character.
 *
 * @return a Canvas object.
 */
Canvas Rhombus::draw() const {
    char p = getPen();
    int h = getHeight();
    int w = getWidth();
    Canvas can{ h, w };
    int n = h / 2;
    // top half
    for (int row = 0; row < n; ++row) {
        // col = n - row is the leftmost column
        // col = n + row is the rightmost column
        // col = n is the middle column
        for (int col = n - row; col <= n + row; ++col) {
            can.put(row, col, p);
        }
    }
    // middle row
    for (int col = 0; col < w; ++col) {
        can.put(n, col, p);
    }
    // bottom half
    for (int row = n + 1; row < h; ++row) {
        // col = row - n is the leftmost column
        // col = 3 * n - row is the rightmost column
        // col = n is the middle column
        for (int col = row - n; col <= 3 * n - row; ++col) {
            can.put(row, col, p);
        }
    }
    return can;
}
