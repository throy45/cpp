#include "Rectangle.h"

Rectangle::Rectangle(int h, int w, char p, std::string n) : Shape(h, w, p, n) {}

double Rectangle::areaGeo() const {
    return static_cast<double>(getHeight()) * getWidth();
}

double Rectangle::perimeterGeo() const {
    return 2.0 * (getHeight() + getWidth());
}

int Rectangle::areaScr() const {
    return getHeight() * getWidth();
}

int Rectangle::perimeterScr() const {
    if (getHeight() > 1 && getWidth() > 1) {
        return 2 * (getHeight() + getWidth()) - 4;
    }
    else {
        return getHeight() * getWidth();
    }
}

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
