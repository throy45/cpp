#ifndef RHOMBUS_H_
#define RHOMBUS_H_

#include "Shape.h"

class Rhombus : public Shape {
    int diagonal;

public:
    Rhombus(int h, char p = '*', std::string n = "Diamond");
    ~Rhombus() = default;

    void setHeight(int h) override;
    void setWidth(int w) override;
    int getDiagonal() const;
    void setDiagonal(int d);

    double areaGeo() const override;
    double perimeterGeo() const override;
    int areaScr() const override;
    int perimeterScr() const override;

    Canvas draw() const override;
};

#endif