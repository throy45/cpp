#include "Shape.h"

/* The line `int Shape::nextId = 0;` is initializing the static member variable `nextId` of the `Shape`
class to 0. This variable is used to assign a unique id to each `Shape` object created. By
initializing it to 0, the first `Shape` object created will have an id of 1. */
int Shape::nextId = 0;

/**
 * The Shape constructor initializes the height, width, pen, name, and id of a Shape object, and throws
 * an exception if the height or width is not positive.
 *
 * @param h The parameter "h" represents the height of the shape.
 * @param w The parameter "w" represents the width of the shape.
 * @param p The parameter "p" represents the pen character used to draw the shape.
 * @param n n is a string parameter that represents the name of the shape.
 */
Shape::Shape(int h, int w, char p, std::string n) : name(n), pen(p) {
    if (h <= 0 || w <= 0) {
        throw std::invalid_argument("Height and width must be positive");
    }
    height = h;
    width = w;
    id = ++nextId;
}

/**
 * The function returns the height of a shape.
 *
 * @return The height of the shape.
 */
int Shape::getHeight() const {
    return height;
}

/**
 * The function returns the width of a shape.
 *
 * @return The width of the shape.
 */
int Shape::getWidth() const {
    return width;
}

/**
 * The function returns the name of the shape.
 *
 * @return a string, which is the name of the shape.
 */
std::string Shape::getName() const {
    return name;
}

/**
 * The function returns the value of the pen variable.
 *
 * @return a character value, which represents the pen used for drawing the shape.
 */
char Shape::getPen() const {
    return pen;
}

/**
 * The function returns the id of a Shape object.
 *
 * @return the value of the variable "id".
 */
int Shape::getId() const {
    return id;
}

/**
 * The function sets the height of a shape object, but throws an exception if the height is not
 * positive.
 *
 * @param h The parameter "h" is an integer representing the height of the shape.
 */
void Shape::setHeight(int h) {
    if (h <= 0) {
        throw std::invalid_argument("Height must be positive");
    }
    height = h;
}

/**
 * The function sets the width of a shape, but throws an exception if the width is not positive.
 *
 * @param w The parameter "w" is an integer representing the width of the shape.
 */
void Shape::setWidth(int w) {
    if (w <= 0) {
        throw std::invalid_argument("Width must be positive");
    }
    width = w;
}

/**
 * The function sets the name of a shape object.
 *
 * @param n The parameter "n" is a string that represents the new name of the shape.
 */
void Shape::setName(std::string n) {
    name = n;
}

/**
 * The function sets the pen character for a Shape object.
 *
 * @param p The parameter "p" is of type char and represents the pen that will be used for drawing the
 * shape.
 */
void Shape::setPen(char p) {
    pen = p;
}

/**
 * The function returns a string representation of the shape's information.
 *
 * @return a string that contains information about a shape object.
 */
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

/**
 * The above function overloads the << operator to output the string representation of a Shape object
 * to an output stream.
 *
 * @return The `operator<<` function returns a reference to the `std::ostream` object `os`.
 */
std::ostream& operator<<(std::ostream& os, const Shape& s) {
    os << s.toString();
    return os;
}
