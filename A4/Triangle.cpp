#include "Triangle.h"

Triangle::Triangle(int b) : Shape(b, b) {
}

void Triangle::setWidth(int w) {
    setBase(w);
}

int Triangle::getBase() const {
    return getWidth();
}

void Triangle::setBase(int b) {
    if (b <= 0) {
        throw std::invalid_argument("Base must be positive");
    }
    Shape::setWidth(b);
    base = b;
}

double Triangle::areaGeo() const {
    return getHeight() * getBase() / 2.0;
}
