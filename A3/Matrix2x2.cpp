#include "Matrix2x2.h"


/**
 * This is a constructor for a 2x2 matrix class in C++, initializing all elements to
 * zero.
 */
Mat2x2::Mat2x2() : matrix({ { {0, 0}, {0, 0} } })
{
}

/**
 * The Mat2x2 constructor initializes a 2x2 matrix with the given values.
 *
 * @param a The value of the top left element of the 2x2 matrix.
 * @param b The parameter "b" represents the value in the top right position of the 2x2 matrix.
 * @param c The parameter "c" represents the value of the element in the second row and first column of
 * the 2x2 matrix.
 * @param d The parameter "d" represents the value of the bottom right element in the 2x2 matrix.
 */
Mat2x2::Mat2x2(double a, double b, double c, double d) : matrix({ { {a, b}, {c, d} } })
{
}

/**
 * The function overloads the >> operator to allow input of matrix elements into a Mat2x2 object.
 *
 * @return The `std::istream&` object `is` is being returned.
 */
std::istream& operator>>(std::istream& is, Mat2x2& m)
{
    std::cout << "Enter matrix elements: ";
    is >> m.matrix[0][0] >> m.matrix[0][1] >> m.matrix[1][0] >> m.matrix[1][1];
    return is;
}

/**
 * The function overloads the << operator to allow for easy printing of a 2x2 matrix.
 *
 * @return a reference to the std::ostream object.
 */
std::ostream& operator<<(std::ostream& os, const Mat2x2& m)
{
    os << "|" << m.matrix[0][0] << " " << m.matrix[0][1] << "|\n";
    os << "|" << m.matrix[1][0] << " " << m.matrix[1][1] << "|\n";
    return os;
}
/**
 * The function calculates the determinant of a 2x2 matrix.
 *
 * @return The determinant of the 2x2 matrix.
 */

double Mat2x2::determinant() const
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

/**
 * The function calculates the trace of a 2x2 matrix.
 *
 * @return the sum of the diagonal elements of the 2x2 matrix.
 */
double Mat2x2::trace() const
{
    return matrix[0][0] + matrix[1][1];
}

/**
 * The function returns the transpose of a 2x2 matrix.
 *
 * @return The transpose of the 2x2 matrix.
 */
Mat2x2 Mat2x2::transpose() const
{
    return Mat2x2(matrix[0][0], matrix[1][0], matrix[0][1], matrix[1][1]);
}

/**
 * The function checks if a 2x2 matrix is symmetric by comparing the values at indices (0,1) and (1,0).
 *
 * @return a boolean value, indicating whether the matrix is symmetric or not.
 */
bool Mat2x2::isSymmetric() const
{
    return matrix[0][1] == matrix[1][0];
}

/**
 * The function checks if two 2x2 matrices are similar based on their determinants and traces.
 *
 * @param m The parameter `m` is a reference to a `Mat2x2` object.
 * @return a boolean value.
 */
bool Mat2x2::isSimilar(const Mat2x2& m) const
{
    return (abs(determinant() - m.determinant()) < tolerance) && (abs(trace() - m.trace()) < tolerance);
}

/**
 * The function checks if a 2x2 matrix is invertible by calculating its determinant and comparing it to
 * the tolerance value.
 *
 * @return a boolean value.
 */
bool Mat2x2::isInvertible() const
{
    return !(abs(determinant()) < tolerance);
}

/**
 * The function calculates the inverse of a 2x2 matrix if it is invertible, otherwise it throws an
 * exception.
 *
 * @return The inverse of the 2x2 matrix.
 */
Mat2x2 Mat2x2::inverse() const
{
    if (isInvertible())
    {
        double det = determinant();
        return Mat2x2(matrix[1][1] / det, -matrix[0][1] / det, -matrix[1][0] / det, matrix[0][0] / det);
    }
    else
    {
        throw std::overflow_error("Inverse undefined");
    }
}

/**
 * The function overloads the += operator to add two 2x2 matrices together and update the calling
 * object (rhs) with the result.
 *
 * @return The `operator+=` function returns a reference to the modified `Mat2x2` object.
 */
Mat2x2& Mat2x2::operator+=(const Mat2x2& m)
{
    matrix[0][0] += m.matrix[0][0];
    matrix[0][1] += m.matrix[0][1];
    matrix[1][0] += m.matrix[1][0];
    matrix[1][1] += m.matrix[1][1];
    return *this;
}

/**
 * The function subtracts the elements of a 2x2 matrix from another 2x2 matrix and updates the original
 * matrix. It uses the += operator overload for code reuse.
 *
 * @return a reference to the current object, which is of type Mat2x2.
 */
Mat2x2& Mat2x2::operator-=(const Mat2x2& m)
{
    return *this += -m;
}

/**
 * The function performs matrix multiplication and updates the calling object with the result.
 * Copies are made because you don't want the new value of a in the calculation of b.
 *
 * @return a reference to the modified object itself (i.e., the current instance of the Mat2x2 class).
 */
Mat2x2& Mat2x2::operator*=(const Mat2x2& m)
{
    double a = matrix[0][0] * m.matrix[0][0] + matrix[0][1] * m.matrix[1][0];
    double b = matrix[0][0] * m.matrix[0][1] + matrix[0][1] * m.matrix[1][1];
    double c = matrix[1][0] * m.matrix[0][0] + matrix[1][1] * m.matrix[1][0];
    double d = matrix[1][0] * m.matrix[0][1] + matrix[1][1] * m.matrix[1][1];
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;
    return *this;
}

/**
 * The function overloads the /= operator for the Mat2x2 class to divide the current matrix by another
 * matrix. This needs special care because it is done by multiplying the current matrix by the inverse
 * of the other matrix.
 *
 * @return The `operator/=` function returns a reference to the modified `Mat2x2` object.
 */
Mat2x2& Mat2x2::operator/=(const Mat2x2& m)
{
    if (m.isInvertible())
    {
        *this *= m.inverse();
        return *this;
    }
    else
    {
        throw std::overflow_error("Division by non-invertible matrix");
    }
}

/**
 * The function overloads the += operator to add a scalar value to all elements of a 2x2 matrix.
 *
 * @return a reference to the modified matrix object.
 */
Mat2x2& Mat2x2::operator+=(double i)
{
    matrix[0][0] += i;
    matrix[0][1] += i;
    matrix[1][0] += i;
    matrix[1][1] += i;
    return *this;
}

/**
 * The function subtracts a scalar value from each element of a 2x2 matrix and returns a reference to
 * the modified matrix. It uses the += operator overload for code reuse.
 *
 * @return a reference to the current object, which is of type Mat2x2.
 */
Mat2x2& Mat2x2::operator-=(double i)
{
    return *this += -i;
}

/**
 * The function multiplies each element of a 2x2 matrix by a given scalar value.
 *
 * @return a reference to the modified object itself, which is denoted by `*this`.
 */
Mat2x2& Mat2x2::operator*=(double i)
{
    matrix[0][0] *= i;
    matrix[0][1] *= i;
    matrix[1][0] *= i;
    matrix[1][1] *= i;
    return *this;
}

/**
 * The function overloads the division operator for a 2x2 matrix and divides each element of the matrix
 * by a given scalar value.
 *
 * @return a reference to the current object, which is of type Mat2x2.
 */
Mat2x2& Mat2x2::operator/=(double i)
{
    if (i != 0)
    {
        matrix[0][0] /= i;
        matrix[0][1] /= i;
        matrix[1][0] /= i;
        matrix[1][1] /= i;
        return *this;
    }
    else
    {
        throw std::overflow_error("Division by zero");
    }
}

/**
 * The function overloads the '+' operator to add two Mat2x2 objects and return the result.
 *
 * @param lhs The lhs parameter is a constant reference to a Mat2x2 object, which represents the
 * left-hand side matrix in the addition operation.
 * @param rhs The parameter "rhs" is a reference to a constant Mat2x2 object.
 * @return a new Mat2x2 object that is the result of adding the two input Mat2x2 objects together.
 */
Mat2x2 operator+(const Mat2x2& lhs, const Mat2x2& rhs)
{
    Mat2x2 m(lhs);
    m += rhs;
    return m;
}

/**
 * The function overloads the subtraction operator for 2x2 matrices.
 *
 * @param lhs A constant reference to a Mat2x2 object, representing the left-hand side of the
 * subtraction operation.
 * @param rhs The parameter "rhs" is a constant reference to a Mat2x2 object.
 * @return a new instance of the Mat2x2 class, which is the result of subtracting the rhs matrix from
 * the lhs matrix.
 */
Mat2x2 operator-(const Mat2x2& lhs, const Mat2x2& rhs)
{
    Mat2x2 m(lhs);
    m -= rhs;
    return m;
}

/**
 * The function overloads the multiplication operator for 2x2 matrices.
 *
 * @param lhs The parameter "lhs" is a constant reference to a Mat2x2 object.
 * @param rhs The parameter "rhs" is of type "Mat2x2", which is a user-defined type representing a 2x2
 * matrix.
 * @return a new instance of the Mat2x2 class, which is the result of multiplying the two input
 * matrices (lhs and rhs) together.
 */
Mat2x2 operator*(const Mat2x2& lhs, const Mat2x2& rhs)
{
    Mat2x2 m(lhs);
    m *= rhs;
    return m;
}

/**
 * The function overloads the division operator for two 2x2 matrices.
 * No need for special care here because /= is already overloaded
 *
 * @param lhs The parameter "lhs" is a constant reference to a Mat2x2 object. It represents the
 * left-hand side matrix in the division operation.
 * @param rhs The parameter "rhs" is a constant reference to a Mat2x2 object.
 * @return a Mat2x2 object.
 */
Mat2x2 operator/(const Mat2x2& lhs, const Mat2x2& rhs)
{
    Mat2x2 m(lhs);
    m /= rhs;
    return m;
}

/**
 * The function overloads the '+' operator to add a scalar value to each element of a 2x2 matrix.
 *
 * @param lhs The parameter "lhs" is a constant reference to a Mat2x2 object.
 * @param rhs The parameter "rhs" is a double value that represents the right-hand side of the addition
 * operation.
 * @return a new Mat2x2 object that is the result of adding the double value `rhs` to each element of
 * the input Mat2x2 object `lhs`.
 */
Mat2x2 operator+(const Mat2x2& lhs, double rhs)
{
    Mat2x2 m(lhs);
    m += rhs;
    return m;
}

/**
 * The function overloads the subtraction operator for a 2x2 matrix and a scalar value.
 *
 * @param lhs A constant reference to a Mat2x2 object, representing the left-hand side of the
 * subtraction operation.
 * @param rhs The parameter "rhs" is a double value.
 * @return a new Mat2x2 object that is the result of subtracting the value of rhs from each element of
 * the lhs Mat2x2 object.
 */
Mat2x2 operator-(const Mat2x2& lhs, double rhs)
{
    Mat2x2 m(lhs);
    m -= rhs;
    return m;
}

/**
 * The function overloads the multiplication operator to multiply a 2x2 matrix by a scalar.
 *
 * @param lhs The parameter "lhs" is a constant reference to a Mat2x2 object.
 * @param rhs The parameter "rhs" is a double value that represents the scalar value by which each
 * element of the matrix "lhs" will be multiplied.
 * @return a new Mat2x2 object that is the result of multiplying the input Mat2x2 object (lhs) by a
 * scalar value (rhs).
 */
Mat2x2 operator*(const Mat2x2& lhs, double rhs)
{
    Mat2x2 m(lhs);
    m *= rhs;
    return m;
}


/**
 * The function overloads the division operator for a 2x2 matrix and a scalar value.
 *
 * @param lhs The parameter "lhs" is a constant reference to a Mat2x2 object.
 * @param rhs The parameter "rhs" is a double value that represents the divisor in the division
 * operation.
 * @return a new Mat2x2 object that is the result of dividing each element of the input Mat2x2 object
 * `lhs` by the scalar value `rhs`.
 */
Mat2x2 operator/(const Mat2x2& lhs, double rhs)
{
    Mat2x2 m(lhs);
    m /= rhs;
    return m;
}


/**
 * The function overloads the addition operator to allow adding a scalar value to a 2x2 matrix.
 *
 * @param lhs A double value representing the left-hand side operand of the addition operation.
 * @param rhs The parameter "rhs" is a constant reference to a Mat2x2 object.
 * @return a new Mat2x2 object that is the result of adding a scalar value (lhs) to each element of the
 * input Mat2x2 object (rhs).
 */
Mat2x2 operator+(double lhs, const Mat2x2& rhs)
{
    Mat2x2 m(rhs);
    m += lhs;
    return m;
}

/**
 * The function overloads the subtraction operator for a double and a 2x2 matrix, returning the result
 * of subtracting the matrix from the double.
 *
 * @param lhs The parameter "lhs" is a double, which represents the left-hand side value in the
 * subtraction operation.
 * @param rhs The parameter "rhs" is a constant reference to a Mat2x2 object.
 * @return a Mat2x2 object.
 */
Mat2x2 operator-(double lhs, const Mat2x2& rhs)
{
    Mat2x2 m(rhs);
    m -= lhs;
    m *= -1;
    return m;
}


/**
 * The function overloads the multiplication operator to allow a scalar value to be multiplied with a
 * 2x2 matrix.
 *
 * @param lhs The parameter "lhs" is a double, which represents the left-hand side scalar value in the
 * multiplication operation.
 * @param rhs The parameter "rhs" is a constant reference to a Mat2x2 object.
 * @return a new Mat2x2 object that is the result of multiplying the given double value (lhs) with the
 * given Mat2x2 object (rhs).
 */
Mat2x2 operator*(double lhs, const Mat2x2& rhs)
{
    Mat2x2 m(rhs);
    m *= lhs;
    return m;
}


/**
 * The function overloads the division operator to divide a scalar by a 2x2 matrix.
 *
 * @param lhs A double value representing the left-hand side of the division operation.
 * @param rhs The parameter "rhs" is a constant reference to a Mat2x2 object.
 * @return a Mat2x2 object.
 */
Mat2x2 operator/(double lhs, const Mat2x2& rhs)
{
    Mat2x2 m = rhs.inverse();
    m *= lhs;
    return m;
}


/**
 * The function checks if two Mat2x2 objects are equal within a certain tolerance.
 *
 * @param lhs The `lhs` parameter is a reference to a `Mat2x2` object, which represents the left-hand
 * side matrix in the comparison operation.
 * @param rhs The parameter "rhs" is a reference to a constant object of type Mat2x2.
 * @return a boolean value.
 */
bool operator==(const Mat2x2& lhs, const Mat2x2& rhs)
{
    return (abs(lhs.matrix[0][0] - rhs.matrix[0][0]) < Mat2x2::tolerance) &&
        (abs(lhs.matrix[0][1] - rhs.matrix[0][1]) < Mat2x2::tolerance) &&
        (abs(lhs.matrix[1][0] - rhs.matrix[1][0]) < Mat2x2::tolerance) &&
        (abs(lhs.matrix[1][1] - rhs.matrix[1][1]) < Mat2x2::tolerance);
}

/**
 * The function checks if two Mat2x2 objects are not equal within a certain tolerance.
 *
 * @param lhs A constant reference to a Mat2x2 object, representing the left-hand side of the
 * inequality operator.
 * @param rhs The rhs parameter is a reference to a constant Mat2x2 object.
 * @return a boolean value.
 */
bool operator!=(const Mat2x2& lhs, const Mat2x2& rhs)
{
    return !(lhs == rhs);
}

/**
 * The function overloads the pre-increment operator for a 2x2 matrix, incrementing all elements
 * by 1 and returning a reference to the modified matrix with code reuse.
 *
 * @return a reference to the updated matrix object.
 */
Mat2x2& Mat2x2::operator++()
{
    return *this += 1;
}

/**
 * The function overloads the post-increment operator for a 2x2 matrix.
 *
 * @param i The parameter "i" in the above code is not used in the implementation of the operator++. It
 * is declared but not used anywhere in the code.
 * @return The post-incremented value of the Mat2x2 object.
 */
Mat2x2 Mat2x2::operator++(int i)
{
    Mat2x2 m(*this);
    ++(*this);
    return m;
}

/**
 * The above function overloads the pre-decrement operator for a 2x2 matrix, subtracting 1 from each
 * element and returning a reference to the modified matrix with code reuse.
 *
 * @return The operator--() function is returning a reference to a Mat2x2 object.
 */
Mat2x2& Mat2x2::operator--()
{
    return *this -= 1;
}

/**
 * The above function overloads the post-decrement operator for a 2x2 matrix.
 *
 * @param i The parameter "i" in the above code is not used and does not have any significance in the
 * implementation of the operator--(int i) function. It is just a placeholder parameter that is not
 * being used in the function body.
 * @return The post-decremented value of the Mat2x2 object before the decrement operation is performed.
 */
Mat2x2 Mat2x2::operator--(int i)
{
    Mat2x2 m(*this);
    --(*this);
    return m;
}

/**
 * The function returns a reference to the element at the specified index in a 2x2 matrix.
 *
 * @return The code is returning a reference to a double value in the 2x2 matrix. The specific value
 * being returned depends on the value of the input parameter `i`. If `i` is 0, the code returns a
 * reference to `matrix[0][0]`. If `i` is 1, the code returns a reference to `matrix[0][1]`. If `
 */
double& Mat2x2::operator[](int i)
{
    switch (i)
    {
    case 0:
        return matrix[0][0];
    case 1:
        return matrix[0][1];
    case 2:
        return matrix[1][0];
    case 3:
        return matrix[1][1];
    default:
        throw std::invalid_argument("Index out of bounds");
    }
}


const double& Mat2x2::operator[](int i) const
{
    switch (i)
    {
    case 0:
        return matrix[0][0];
    case 1:
        return matrix[0][1];
    case 2:
        return matrix[1][0];
    case 3:
        return matrix[1][1];
    default:
        throw std::invalid_argument("Index out of bounds");
    }
}

/**
 * The function returns true if the matrix is not invertible, and false otherwise.
 *
 * @return The operator returns the logical negation of the result of the `isInvertible()` function.
 */
bool Mat2x2::operator!() const
{
    return !isInvertible();
}

/**
 * The functor returns the determinant of a 2x2 matrix.
 *
 * @return The `determinant()` of the `Mat2x2` object is being returned.
 */
double Mat2x2::operator()() const
{
    return determinant();
}

/**
 * The function converts a Mat2x2 object to a boolean value based on whether it is invertible or not.
 *
 * @return The operator bool() function is returning the result of the isInvertible() function.
 */
Mat2x2::operator bool() const
{
    return isInvertible();
}


/**
 * The unary operator overload returns the input matrix unchanged.
 *
 * @param m The parameter "m" is a constant reference to a Mat2x2 object.
 * @return The Mat2x2 object "m" is being returned.
 */
Mat2x2 operator+(const Mat2x2& m)
{
    return m;
}

/**
 * The function overloads the unary minus operator for a 2x2 matrix, returning the negation of the
 * matrix.
 *
 * @param m The parameter `m` is a constant reference to an object of type `Mat2x2`.
 * @return a new Mat2x2 object that is the negation of the input matrix.
 */
Mat2x2 operator-(const Mat2x2& m)
{
    std::array<std::array<double, 2>, 2> m1 = m.getMatrix();
    return -1 * m; // here check!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}


Mat2x2& Mat2x2::operator+=(int i) { return this->operator+=(static_cast<double>(i)); }
Mat2x2& Mat2x2::operator-=(int i) { return this->operator-=(static_cast<double>(i)); }
Mat2x2& Mat2x2::operator*=(int i) { return this->operator*=(static_cast<double>(i)); }
Mat2x2& Mat2x2::operator/=(int i) { return this->operator/=(static_cast<double>(i)); }
Mat2x2 operator+(const Mat2x2& lhs, int rhs) { return lhs + static_cast<double>(rhs); }
Mat2x2 operator-(const Mat2x2& lhs, int rhs) { return lhs - static_cast<double>(rhs); }
Mat2x2 operator*(const Mat2x2& lhs, int rhs) { return lhs * static_cast<double>(rhs); }
Mat2x2 operator/(const Mat2x2& lhs, int rhs) { return lhs / static_cast<double>(rhs); }
Mat2x2 operator+(int lhs, const Mat2x2& rhs) { return static_cast<double>(lhs) + rhs; }
Mat2x2 operator-(int lhs, const Mat2x2& rhs) { return static_cast<double>(lhs) - rhs; }
Mat2x2 operator*(int lhs, const Mat2x2& rhs) { return static_cast<double>(lhs) * rhs; }
Mat2x2 operator/(int lhs, const Mat2x2& rhs) { return static_cast<double>(lhs) / rhs; }