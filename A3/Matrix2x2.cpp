#include "Matrix2x2.h"


Mat2x2::Mat2x2()
{
    matrix[0][0] = 0;
    matrix[0][1] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 0;
}

Mat2x2::Mat2x2(double a, double b, double c, double d)
{
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;
}

std::istream& operator>>(std::istream& is, Mat2x2& m)
{
    std::cout << "Enter matrix elements: ";
    is >> m.matrix[0][0] >> m.matrix[0][1] >> m.matrix[1][0] >> m.matrix[1][1];
    return is;
}

std::ostream& operator<<(std::ostream& os, const Mat2x2& m)
{
    os << "|" << m.matrix[0][0] << " " << m.matrix[0][1] << "|\n";
    os << "|" << m.matrix[1][0] << " " << m.matrix[1][1] << "|\n";
    return os;
}

int Mat2x2::determinant() const
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int Mat2x2::trace() const
{
    return matrix[0][0] + matrix[1][1];
}

Mat2x2 Mat2x2::transpose() const
{
    return Mat2x2(matrix[0][0], matrix[1][0], matrix[0][1], matrix[1][1]);
}

bool Mat2x2::isSymmetric() const
{
    return matrix[0][1] == matrix[1][0];
}

bool Mat2x2::isSimilar(const Mat2x2& m) const
{
    return (abs(determinant() - m.determinant()) < tolerance) && (abs(trace() - m.trace()) < tolerance);
}

bool Mat2x2::isInvertible() const
{
    return !(abs(determinant()) < tolerance);
}

Mat2x2 Mat2x2::inverse() const
{
    if (isInvertible())
    {
        int det = determinant();
        return Mat2x2(matrix[1][1] / det, -matrix[0][1] / det, -matrix[1][0] / det, matrix[0][0] / det);
    }
    else
    {
        throw std::overflow_error("Inverse undefined");
    }
}

Mat2x2& Mat2x2::operator+=(const Mat2x2& m)
{
    matrix[0][0] += m.matrix[0][0];
    matrix[0][1] += m.matrix[0][1];
    matrix[1][0] += m.matrix[1][0];
    matrix[1][1] += m.matrix[1][1];
    return *this;
}

Mat2x2& Mat2x2::operator-=(const Mat2x2& m)
{
    matrix[0][0] -= m.matrix[0][0];
    matrix[0][1] -= m.matrix[0][1];
    matrix[1][0] -= m.matrix[1][0];
    matrix[1][1] -= m.matrix[1][1];
    return *this;
}

Mat2x2& Mat2x2::operator*=(const Mat2x2& m)
{
    int a = matrix[0][0] * m.matrix[0][0] + matrix[0][1] * m.matrix[1][0];
    int b = matrix[0][0] * m.matrix[0][1] + matrix[0][1] * m.matrix[1][1];
    int c = matrix[1][0] * m.matrix[0][0] + matrix[1][1] * m.matrix[1][0];
    int d = matrix[1][0] * m.matrix[0][1] + matrix[1][1] * m.matrix[1][1];
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;
    return *this;
}

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

Mat2x2& Mat2x2::operator+=(int i)
{
    matrix[0][0] += i;
    matrix[0][1] += i;
    matrix[1][0] += i;
    matrix[1][1] += i;
    return *this;
}

Mat2x2& Mat2x2::operator-=(int i)
{
    matrix[0][0] -= i;
    matrix[0][1] -= i;
    matrix[1][0] -= i;
    matrix[1][1] -= i;
    return *this;
}

Mat2x2& Mat2x2::operator*=(int i)
{
    matrix[0][0] *= i;
    matrix[0][1] *= i;
    matrix[1][0] *= i;
    matrix[1][1] *= i;
    return *this;
}

Mat2x2& Mat2x2::operator/=(int i)
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

Mat2x2 operator+(const Mat2x2& lhs, const Mat2x2& rhs)
{
    Mat2x2 m(lhs);
    m += rhs;
    return m;
}

Mat2x2 operator-(const Mat2x2& lhs, const Mat2x2& rhs)
{
    Mat2x2 m(lhs);
    m -= rhs;
    return m;
}

Mat2x2 operator*(const Mat2x2& lhs, const Mat2x2& rhs)
{
    Mat2x2 m(lhs);
    m *= rhs;
    return m;
}

Mat2x2 operator/(const Mat2x2& lhs, const Mat2x2& rhs)
{
    Mat2x2 m(lhs);
    m /= rhs;
    return m;
}

Mat2x2 operator+(const Mat2x2& lhs, int rhs)
{
    Mat2x2 m(lhs);
    m += rhs;
    return m;
}

Mat2x2 operator-(const Mat2x2& lhs, int rhs)
{
    Mat2x2 m(lhs);
    m -= rhs;
    return m;
}

Mat2x2 operator*(const Mat2x2& lhs, int rhs)
{
    Mat2x2 m(lhs);
    m *= rhs;
    return m;
}


Mat2x2 operator/(const Mat2x2& lhs, int rhs)
{
    Mat2x2 m(lhs);
    m /= rhs;
    return m;
}


Mat2x2 operator+(int lhs, const Mat2x2& rhs)
{
    Mat2x2 m(rhs);
    m += lhs;
    return m;
}

Mat2x2 operator-(int lhs, const Mat2x2& rhs)
{
    Mat2x2 m(rhs);
    m *= -1;
    m += lhs;
    return m;
}


Mat2x2 operator*(int lhs, const Mat2x2& rhs)
{
    Mat2x2 m(rhs);
    m *= lhs;
    return m;
}


Mat2x2 operator/(int lhs, const Mat2x2& rhs)
{
    Mat2x2 m(rhs);
    m /= lhs;
    return m;
}


bool operator==(const Mat2x2& lhs, const Mat2x2& rhs)
{
    return (abs(lhs.matrix[0][0] - rhs.matrix[0][0]) < Mat2x2::tolerance) &&
        (abs(lhs.matrix[0][1] - rhs.matrix[0][1]) < Mat2x2::tolerance) &&
        (abs(lhs.matrix[1][0] - rhs.matrix[1][0]) < Mat2x2::tolerance) &&
        (abs(lhs.matrix[1][1] - rhs.matrix[1][1]) < Mat2x2::tolerance);
}

bool operator!=(const Mat2x2& lhs, const Mat2x2& rhs)
{
    return !(lhs == rhs);
}

Mat2x2& Mat2x2::operator++()
{
    matrix[0][0]++;
    matrix[0][1]++;
    matrix[1][0]++;
    matrix[1][1]++;
    return *this;
}

Mat2x2 Mat2x2::operator++(int i)
{
    Mat2x2 m(*this);
    ++(*this);
    return m;
}

Mat2x2& Mat2x2::operator--()
{
    matrix[0][0]--;
    matrix[0][1]--;
    matrix[1][0]--;
    matrix[1][1]--;
    return *this;
}

Mat2x2 Mat2x2::operator--(int i)
{
    Mat2x2 m(*this);
    --(*this);
    return m;
}

double& Mat2x2::operator[](int i)
{
    if (i == 0)
    {
        return matrix[0][0];
    }
    else if (i == 1)
    {
        return matrix[0][1];
    }
    else if (i == 2)
    {
        return matrix[1][0];
    }
    else if (i == 3)
    {
        return matrix[1][1];
    }
    else
    {
        throw std::invalid_argument("Index out of bounds");
    }
}

const double& Mat2x2::operator[](int i) const
{
    if (i == 0)
    {
        return matrix[0][0];
    }
    else if (i == 1)
    {
        return matrix[0][1];
    }
    else if (i == 2)
    {
        return matrix[1][0];
    }
    else if (i == 3)
    {
        return matrix[1][1];
    }
    else
    {
        throw std::invalid_argument("Index out of bounds");
    }
}

bool Mat2x2::operator!() const
{
    return !isInvertible();
}

int Mat2x2::operator()() const
{
    return determinant();
}

Mat2x2::operator bool() const
{
    return isInvertible();
}


Mat2x2 operator+(const Mat2x2& m)
{
    return m;
}

Mat2x2 operator-(const Mat2x2& m)
{
    std::array<std::array<double, 2>, 2> m1 = m.getMatrix();
    return Mat2x2(-m1[0][0], -m1[0][1], -m1[1][0], -m1[1][1]);
}

