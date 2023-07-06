#ifndef MATRIX2X2_H_
#define MATRIX2X2_H_

// Thomas Roy 40209149
// COMP 5461 - A3
// July 2023

#include <array>
#include <iostream>
#include <stdexcept>

/**
 * The `class Mat2x2` is defining a matrix class for 2x2 matrices. It provides various member functions and overloaded
 * operators for performing operations on matrices, such as addition, subtraction, multiplication, and division. It
 * also includes functions for calculating the determinant, trace, transpose, and inverse of a matrix.
 */
class Mat2x2
{
    /**
     * The line `std::array<std::array<double, 2>, 2> matrix;` is declaring a member variable named `matrix` of type
     * `std::array<std::array<double, 2>, 2>`. This is a 2-dimensional array of size 2x2, where each element is of type
     * `double`. It is used to store the values of the matrix.
     */
    std::array<std::array<double, 2>, 2> matrix;

public:
    /**
     * The line `constexpr static const double tolerance = 1.0E-6;` is declaring a constant variable named `tolerance`
     * of type `double`. The `constexpr` keyword indicates that the value of `tolerance` can be computed at compile -
     * time. The `static` keyword means that the variable is shared among all instances of the class `Mat2x2`. The
     * `const` keyword ensures that the value of `tolerance` cannot be modified once it is initialized.
     */
    constexpr static const double tolerance = 1.0E-6;

    Mat2x2();

    Mat2x2(double a, double b, double c, double d);

    Mat2x2(const Mat2x2& m) = default;
    Mat2x2(Mat2x2&& m) = default;
    Mat2x2& operator=(const Mat2x2& m) = default;
    Mat2x2& operator=(Mat2x2&& m) = default;
    ~Mat2x2() = default;

    friend std::istream& operator>>(std::istream& is, Mat2x2& m);

    friend std::ostream& operator<<(std::ostream& os, const Mat2x2& m);

    double determinant() const noexcept;
    double trace() const noexcept;
    Mat2x2 transpose() const noexcept;
    bool isSymmetric() const noexcept;
    bool isSimilar(const Mat2x2& m) const noexcept;
    bool isInvertible() const noexcept;

    Mat2x2 inverse() const;

    Mat2x2& operator+=(const Mat2x2& m) noexcept;
    Mat2x2& operator-=(const Mat2x2& m) noexcept;
    Mat2x2& operator*=(const Mat2x2& m) noexcept;
    Mat2x2& operator/=(const Mat2x2& m);
    Mat2x2& operator+=(double i) noexcept;
    Mat2x2& operator-=(double i) noexcept;
    Mat2x2& operator*=(double i) noexcept;
    Mat2x2& operator/=(double i);

    friend Mat2x2 operator+(const Mat2x2& lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator-(const Mat2x2& lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator*(const Mat2x2& lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator/(const Mat2x2& lhs, const Mat2x2& rhs);
    friend Mat2x2 operator+(const Mat2x2& lhs, double rhs) noexcept;
    friend Mat2x2 operator-(const Mat2x2& lhs, double rhs) noexcept;
    friend Mat2x2 operator*(const Mat2x2& lhs, double rhs) noexcept;
    friend Mat2x2 operator/(const Mat2x2& lhs, double rhs);
    friend Mat2x2 operator+(double lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator-(double lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator*(double lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator/(double lhs, const Mat2x2& rhs);

    friend bool operator==(const Mat2x2& lhs, const Mat2x2& rhs) noexcept;
    friend bool operator!=(const Mat2x2& lhs, const Mat2x2& rhs) noexcept;

    Mat2x2& operator++() noexcept;
    Mat2x2 operator++(int) noexcept;

    Mat2x2& operator--() noexcept;
    Mat2x2 operator--(int) noexcept;

    double& operator[](int i);
    const double& operator[](int i) const;

    bool operator!() const noexcept;

    double operator()() const noexcept;

    operator bool() const noexcept;

    friend Mat2x2 operator+(const Mat2x2& m) noexcept;
    friend Mat2x2 operator-(const Mat2x2& m) noexcept;

    const std::array<std::array<double, 2>, 2>& getMatrix() const noexcept {
        return matrix;
    };

    // Helper methods for integer operations (the compiler has a hard time with implicit conversions from int to double)

    Mat2x2& operator+=(int i) noexcept;
    Mat2x2& operator-=(int i) noexcept;
    Mat2x2& operator*=(int i) noexcept;
    Mat2x2& operator/=(int i);
    friend Mat2x2 operator+(const Mat2x2& lhs, int rhs) noexcept;
    friend Mat2x2 operator-(const Mat2x2& lhs, int rhs) noexcept;
    friend Mat2x2 operator*(const Mat2x2& lhs, int rhs) noexcept;
    friend Mat2x2 operator/(const Mat2x2& lhs, int rhs);
    friend Mat2x2 operator+(int lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator-(int lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator*(int lhs, const Mat2x2& rhs) noexcept;
    friend Mat2x2 operator/(int lhs, const Mat2x2& rhs);
};

#endif