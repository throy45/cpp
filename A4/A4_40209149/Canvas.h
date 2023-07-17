#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <ostream>

class Canvas {
public:
    // all special members are defaulted because ’grid’,
    // a 2D std::vector, is self-sufficient and efficient,
    // designed to handle the corresponding special operations efficiently
    Canvas() = default;
    virtual ~Canvas() = default;
    Canvas(const Canvas&) = default;
    Canvas(Canvas&&) = default;
    Canvas& operator=(const Canvas&) = default;
    Canvas& operator=(Canvas&&) = default;
protected:
    std::vector<std::vector<char> > grid{}; // a 2D vector representing a canvas
    char fillChar{ ' ' }; // fill or clear character
    bool check(int r, int c)const; // validates row r and column c, 0-based
    void resize(size_t rows, size_t cols); // resizes this Canvas’s dimensions
public:
    // creates this canvas’s (rows x columns) grid filled with blank characters
    Canvas(int rows, int columns, char fillChar = ' ');

    char getFillChar()const;
    void setFillChar(char ch);

    int getRows()const; // returns height of this Canvas object
    int getColumns()const; // returns width of this Canvas object
    Canvas flip_horizontal()const; // flips this canvas horizontally
    Canvas flip_vertical()const; // flips this canvas vertically
    void print(std::ostream&) const; // prints this Canvas to ostream
    char get(int r, int c) const; // returns char at row r and column c, 0-based;
    // throws std::out_of_range{ "Canvas index out of range" }
    // if r or c is invalid.
    void put(int r, int c, char ch); // puts ch at row r and column c, 0-based;
    // the only function used by a shape’s draw functon;
    // throws std::out_of_range{ "Canvas index out of range" }
    // if r or c is invalid.

    // draws text starting at row r and col c on this canvas
    void drawString(int r, int c, const std::string text);

    // copies the non-fill characters of "can" onto the invoking Canvas object;
    // maps can’s origin to row r and column c on the invoking Canvas object
    void overlap(const Canvas& can, size_t r, size_t c);
};
std::ostream& operator<< (std::ostream& sout, const Canvas& can);

#endif