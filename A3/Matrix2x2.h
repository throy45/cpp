#ifndef MATRIX2X2_H_
#define MATRIX2X2_H_

#include <array>
#include <iostream>
#include <stdexcept>

class Mat2x2
{
    std::array<std::array<double, 2>, 2> matrix;

public:
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

    double determinant() const;
    double trace() const;
    Mat2x2 transpose() const;
    bool isSymmetric() const;
    bool isSimilar(const Mat2x2& m) const;
    bool isInvertible() const;

    Mat2x2 inverse() const;

    Mat2x2& operator+=(const Mat2x2& m);
    Mat2x2& operator-=(const Mat2x2& m);
    Mat2x2& operator*=(const Mat2x2& m);
    Mat2x2& operator/=(const Mat2x2& m);
    Mat2x2& operator+=(double i);
    Mat2x2& operator-=(double i);
    Mat2x2& operator*=(double i);
    Mat2x2& operator/=(double i);

    friend Mat2x2 operator+(const Mat2x2& lhs, const Mat2x2& rhs);
    friend Mat2x2 operator-(const Mat2x2& lhs, const Mat2x2& rhs);
    friend Mat2x2 operator*(const Mat2x2& lhs, const Mat2x2& rhs);
    friend Mat2x2 operator/(const Mat2x2& lhs, const Mat2x2& rhs);
    friend Mat2x2 operator+(const Mat2x2& lhs, double rhs);
    friend Mat2x2 operator-(const Mat2x2& lhs, double rhs);
    friend Mat2x2 operator*(const Mat2x2& lhs, double rhs);
    friend Mat2x2 operator/(const Mat2x2& lhs, double rhs);
    friend Mat2x2 operator+(double lhs, const Mat2x2& rhs);
    friend Mat2x2 operator-(double lhs, const Mat2x2& rhs);
    friend Mat2x2 operator*(double lhs, const Mat2x2& rhs);
    friend Mat2x2 operator/(double lhs, const Mat2x2& rhs);

    friend bool operator==(const Mat2x2& lhs, const Mat2x2& rhs);
    friend bool operator!=(const Mat2x2& lhs, const Mat2x2& rhs);

    Mat2x2& operator++();
    Mat2x2 operator++(int);

    Mat2x2& operator--();
    Mat2x2 operator--(int);

    double& operator[](int i);
    const double& operator[](int i) const;

    bool operator!() const;

    double operator()() const;

    operator bool() const;

    friend Mat2x2 operator+(const Mat2x2& m);
    friend Mat2x2 operator-(const Mat2x2& m);

    const std::array<std::array<double, 2>, 2>& getMatrix() const {
        return matrix;
    };



    Mat2x2& operator+=(int i);
    Mat2x2& operator-=(int i);
    Mat2x2& operator*=(int i);
    Mat2x2& operator/=(int i);
    friend Mat2x2 operator+(const Mat2x2& lhs, int rhs);
    friend Mat2x2 operator-(const Mat2x2& lhs, int rhs);
    friend Mat2x2 operator*(const Mat2x2& lhs, int rhs);
    friend Mat2x2 operator/(const Mat2x2& lhs, int rhs);
    friend Mat2x2 operator+(int lhs, const Mat2x2& rhs);
    friend Mat2x2 operator-(int lhs, const Mat2x2& rhs);
    friend Mat2x2 operator*(int lhs, const Mat2x2& rhs);
    friend Mat2x2 operator/(int lhs, const Mat2x2& rhs);
};

#endif