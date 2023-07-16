#include "Shape.h"


int Shape::nextId = 0;

Shape::Shape(int h, int w, char p, std::string n) : name(n), pen(p) {
    if (h <= 0 || w <= 0) {
        throw std::invalid_argument("Height and width must be positive");
    }
    height = h;
    width = w;
    id = ++nextId;
}


int Shape::getHeight() const {
    return height;
}

int Shape::getWidth() const {
    return width;
}

std::string Shape::getName() const {
    return name;
}

char Shape::getPen() const {
    return pen;
}

int Shape::getId() const {
    return id;
}

void Shape::setHeight(int h) {
    if (h <= 0) {
        throw std::invalid_argument("Height must be positive");
    }
    height = h;
}

void Shape::setWidth(int w) {
    if (w <= 0) {
        throw std::invalid_argument("Width must be positive");
    }
    width = w;
}

void Shape::setName(std::string n) {
    name = n;
}

void Shape::setPen(char p) {
    pen = p;
}

std::string Shape::toString() const {
    std::string s = "Shape Information\n";
    s += "-----------------\n";
    s += "id:\t\t" + std::to_string(id) + "\n";
    s += "Shape name:\t" + name + "\n";
    s += "Pen character:\t" + std::string(1, pen) + "\n";
    s += "Height:\t\t" + std::to_string(height) + "\n";
    s += "Width:\t\t" + std::to_string(width) + "\n";
    s += "Textual area:\t" + std::to_string(areaScr()) + "\n";
    s += "Geometric area:\t" + std::to_string(areaGeo()) + "\n";
    s += "Textual perimeter: " + std::to_string(perimeterScr()) + "\n";
    s += "Geometric perimeter: " + std::to_string(perimeterGeo()) + "\n";
    s += "Static type: " + std::string(typeid(this).name()) + "\n";
    s += "Dynamic type: " + std::string(typeid(*this).name()) + "\n";
    return s;
}

std::ostream& operator<<(std::ostream& os, const Shape& s) {
    os << s.toString();
    return os;
}
