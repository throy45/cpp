#include "Rhombus.h"

#include <cmath>

Rhombus::Rhombus(int d, char p, std::string n) : Shape(d, d, p, n) {
    setDiagonal(d);
}

void Rhombus::setHeight(int d) {
    setDiagonal(d);
}


void Rhombus::setWidth(int d) {
    setDiagonal(d);
}

int Rhombus::getDiagonal() const {
    return getHeight();
}

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

double Rhombus::areaGeo() const {
    return getHeight() * getHeight() / 2.0;
}

double Rhombus::perimeterGeo() const {
    return 2.0 * getHeight() * std::sqrt(2.0);
}

int Rhombus::areaScr() const {
    int n = getHeight() / 2;
    return 2 * n * (n + 1) + 1;
}

int Rhombus::perimeterScr() const {
    if (getHeight() > 1) {
        return 2 * (getHeight() - 1);
    }
    else {
        return 1;
    }
}

Canvas Rhombus::draw() const {
    Canvas can{ getHeight(), getWidth() };
    int n = getHeight() / 2;
    // top half
    for (int row = 0; row < n; ++row) {
        // col = n - row is the leftmost column
        // col = n + row is the rightmost column
        // col = n is the middle column
        for (int col = n - row; col <= n + row; ++col) {
            can.put(row, col, getPen());
        }
    }
    // middle row
    for (int col = 0; col < getWidth(); ++col) {
        can.put(n, col, getPen());
    }
    // bottom half
    for (int row = n + 1; row < getHeight(); ++row) {
        // col = row - n is the leftmost column
        // col = 3 * n - row is the rightmost column
        // col = n is the middle column
        for (int col = row - n; col <= 3 * n - row; ++col) {
            can.put(row, col, getPen());
        }
    }
    return can;
}
