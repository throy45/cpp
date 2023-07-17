#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H

#include "Triangle.h"

class AcuteTriangle : public Triangle
{
public:
    AcuteTriangle() = delete;
    AcuteTriangle(int b, char p = '*', std::string n = "Wedge");
    virtual ~AcuteTriangle() = default;

    void setHeight(int h) override;
    void setWidth(int w) override;

    double perimeterGeo() const override;
    int areaScr() const override;
    int perimeterScr() const override;

    Canvas draw() const override;
};


#endif