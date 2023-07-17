#include "Canvas.h"

// A canvas is a two-dimensional grid of characters. The grid is represented by a 2D vector of characters.

/**
 * The function checks if the given row and column values are within the bounds of the grid.
 *
 * @param r The parameter "r" represents the row index of the grid. It is used to check if the row
 * index is within the bounds of the grid.
 * @param c The parameter "c" represents the column index in the grid.
 * @return a boolean value.
 */
bool Canvas::check(int r, int c) const
{
    // Check if r and c are within the bounds of the grid
    return r >= 0 && r < static_cast<int>(grid.size())
        && c >= 0 && c < static_cast<int>(grid[r].size());
}

/**
 * The resize function resizes the grid to have the specified number of rows and columns.
 *
 * @param rows The number of rows that the grid should have after resizing.
 * @param cols The parameter "cols" represents the number of columns that the grid should have after
 * resizing.
 */
void Canvas::resize(size_t rows, size_t cols)
{
    if (rows <= 0 || cols <= 0)
    {
        throw std::invalid_argument("Invalid size");
    }
    // Resize the grid to have the specified number of rows and columns
    grid.resize(rows);
    for (auto& row : grid)
        row.resize(cols);
}

/**
 * The Canvas constructor creates a canvas with the specified number of rows and columns, filled with
 * the specified character.
 *
 * @param rows The number of rows in the canvas.
 * @param columns The "columns" parameter specifies the number of columns in the canvas grid.
 * @param fillChar The fillChar parameter is a character that will be used to fill the canvas. It will
 * be used to populate each cell in the grid with the specified character.
 */
Canvas::Canvas(int rows, int columns, char fillChar)
{
    if (rows <= 0 || columns <= 0)
    {
        throw std::invalid_argument("Invalid size");
    }
    // Create a canvas with the specified number of rows and columns, filled with the specified character
    resize(rows, columns);
    this->fillChar = fillChar;
    // fill with the character
    for (auto& row : grid)
        for (auto& ch : row)
            ch = fillChar;
}

/**
 * The function returns the fill character used in the Canvas class.
 *
 * @return the value of the member variable `fillChar`.
 */
char Canvas::getFillChar() const
{
    return fillChar;
}

/**
 * The function sets the fill character for a Canvas object.
 *
 * @param ch The parameter "ch" is of type char and represents the character that will be used to fill
 * the canvas.
 */
void Canvas::setFillChar(char ch)
{
    fillChar = ch;
}

/**
 * The function returns the number of rows in the grid.
 *
 * @return The number of rows in the grid.
 */
int Canvas::getRows() const
{
    return grid.size();
}

/**
 * The function returns the number of columns in the grid.
 *
 * @return The number of columns in the grid.
 */
int Canvas::getColumns() const
{
    return grid[0].size();
}

/**
 * The flip_horizontal function creates a new canvas with the same dimensions as the original canvas,
 * and copies the characters from the original canvas to the new canvas, but flipped horizontally.
 *
 * @return a new instance of the `Canvas` class.
 */
Canvas Canvas::flip_horizontal() const
{
    // Create a new canvas with the same dimensions as this one
    Canvas can{ getRows(), getColumns(), fillChar };
    for (int r = 0; r < getRows(); ++r)
        for (int c = 0; c < getColumns(); ++c)
            // Copy the characters from this canvas to the new one, but flip horizontally
            // so put the character at (r, c) in this canvas at (r, getColumns() - 1 - c) in the new canvas
            can.put(r, c, get(r, getColumns() - 1 - c));
    return can;
}

/**
 * The flip_vertical function creates a new canvas with the same dimensions as the original canvas, and
 * copies the characters from the original canvas to the new canvas, but flips them vertically.
 *
 * @return a new instance of the `Canvas` class.
 */
Canvas Canvas::flip_vertical() const
{
    // Create a new canvas with the same dimensions as this one
    Canvas can{ getRows(), getColumns(), fillChar };
    for (int r = 0; r < getRows(); ++r)
        for (int c = 0; c < getColumns(); ++c)
            // Copy the characters from this canvas to the new one, but flip vertically
            // so put the character at (r, c) in this canvas at (getRows() - 1 - r, c) in the new canvas
            can.put(r, c, get(getRows() - 1 - r, c));
    return can;
}

/**
 * The function prints the contents of a grid to an output stream.
 *
 * @param sout sout is a reference to an output stream (such as std::cout) where the contents of the
 * grid will be printed.
 */
void Canvas::print(std::ostream& sout) const
{
    for (auto& row : grid) {
        for (auto& ch : row)
            sout << ch;
        sout << '\n';
    }
}

/**
 * The function "get" returns the character at the specified row and column position in the grid,
 * throwing an exception if the position is out of range.
 *
 * @param r The parameter "r" represents the row index of the element in the grid.
 * @param c The parameter "c" represents the column index of the element in the grid that we want to
 * retrieve.
 * @return a character value from the grid at the specified row and column indices.
 */
char Canvas::get(int r, int c) const
{
    if (!check(r, c))
        throw std::out_of_range{ "Canvas index out of range" };
    return grid[r][c];
}

/**
 * The `put` function in the `Canvas` class is used to place a character `ch` at the specified row `r`
 * and column `c` on the grid.
 *
 * @param r The parameter "r" represents the row index of the grid where the character "ch" will be
 * placed.
 * @param c The parameter "c" represents the column index of the grid where the character "ch" will be
 * placed.
 * @param ch The parameter "ch" is of type "char" and represents the character that will be placed at
 * the specified position (r, c) on the grid.
 */
void Canvas::put(int r, int c, char ch)
{
    if (!check(r, c))
        throw std::out_of_range{ "Canvas index out of range" };
    grid[r][c] = ch;
}

/**
 * The function `drawString` in the `Canvas` class is used to draw a string on the canvas starting at a
 * specified row and column position.
 *
 * @param r The parameter "r" represents the row number where the string will be drawn on the canvas.
 * @param c The parameter "c" represents the starting column position where the string will be drawn on
 * the canvas.
 * @param text The "text" parameter is a string that represents the text that needs to be drawn on the
 * canvas.
 */
void Canvas::drawString(int r, int c, const std::string text)
{
    for (int i = 0; i < static_cast<int>(text.size()); ++i)
        put(r, c + i, text[i]);
}

/**
 * The `overlap` function copies the contents of another canvas onto the current canvas starting at the
 * specified row and column.
 *
 * @param can The parameter "can" is a reference to a constant object of type Canvas. It represents
 * another canvas object that we want to overlap onto the current canvas.
 * @param r The starting row index in the current canvas where the overlapping should begin.
 * @param c The parameter "c" represents the column index where the top-left corner of the "can" canvas
 * will be placed on the current canvas.
 */
void Canvas::overlap(const Canvas& can, size_t r, size_t c)
{
    for (int i = 0; i < can.getRows(); ++i)
        for (int j = 0; j < can.getColumns(); ++j)
            if (can.get(i, j) != can.getFillChar())
                put(r + i, c + j, can.get(i, j));
}

/**
 * The above function overloads the << operator to print the contents of a Canvas object to an output
 * stream.
 *
 * @return The `std::ostream&` object `sout` is being returned.
 */
std::ostream& operator<<(std::ostream& sout, const Canvas& can)
{
    can.print(sout);
    return sout;
}
