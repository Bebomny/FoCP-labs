#ifndef CP2_LAB_5_CYLINDER_H
#define CP2_LAB_5_CYLINDER_H
#include "Circle.h"
#include "Rectangle.h"

class Cylinder : public Circle, public Rectangle {
public:
    Cylinder(float radius, float height)
        : Circle(radius),
          Rectangle(2 * std::numbers::pi * radius, height) {
    }

    float area() override {
        return Circle::area() * 2 + Rectangle::area();
    }
};

#endif //CP2_LAB_5_CYLINDER_H