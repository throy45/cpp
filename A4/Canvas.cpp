#include "Canvas.h"

// A canvas is a two-dimensional grid of characters. The grid is represented by a 2D vector of characters.

bool Canvas::check(int r, int c) const
{
    // Check if r and c are within the bounds of the grid
    return r >= 0 && r < static_cast<int>(grid.size())
        && c >= 0 && c < static_cast<int>(grid[r].size());
}

void Canvas::resize(size_t rows, size_t cols)
{
    // Resize the grid to have the specified number of rows and columns
    grid.resize(rows);
    for (auto& row : grid)
        row.resize(cols);
}

Canvas::Canvas(int rows, int columns, char fillChar)
{
    // Create a canvas with the specified number of rows and columns, filled with the specified character
    resize(rows, columns);
    this->fillChar = fillChar;
    // fill with the character
    for (auto& row : grid)
        for (auto& ch : row)
            ch = fillChar;
}

char Canvas::getFillChar() const
{
    return fillChar;
}


void Canvas::setFillChar(char ch)
{
    fillChar = ch;
}

int Canvas::getRows() const
{
    return grid.size();
}

int Canvas::getColumns() const
{
    return grid[0].size();
}

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

void Canvas::print(std::ostream& sout) const
{
    for (auto& row : grid) {
        for (auto& ch : row)
            sout << ch;
        sout << '\n';
    }
}

char Canvas::get(int r, int c) const
{
    if (!check(r, c))
        throw std::out_of_range{ "Canvas index out of range" };
    return grid[r][c];
}

void Canvas::put(int r, int c, char ch)
{
    if (!check(r, c))
        throw std::out_of_range{ "Canvas index out of range" };
    grid[r][c] = ch;
}

void Canvas::drawString(int r, int c, const std::string text)
{
    for (int i = 0; i < static_cast<int>(text.size()); ++i)
        put(r, c + i, text[i]);
}

void Canvas::overlap(const Canvas& can, size_t r, size_t c)
{
    for (int i = 0; i < can.getRows(); ++i)
        for (int j = 0; j < can.getColumns(); ++j)
            if (can.get(i, j) != can.getFillChar())
                put(r + i, c + j, can.get(i, j));
}

std::ostream& operator<<(std::ostream& sout, const Canvas& can)
{
    can.print(sout);
    return sout;
}
