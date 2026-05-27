#ifndef CP2_LAB_5_CIRCLE_H
#define CP2_LAB_5_CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(const std::string &name, float radius) : Shape(name), radius(radius) {}

    Circle(float radius) : Shape("circle"), radius(radius) {}

    float radius;

    float area() override {
        return std::numbers::pi * radius * radius;
    }
};

#endif //CP2_LAB_5_CIRCLE_H