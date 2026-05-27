#ifndef CP2_LAB_5_RECTANGLE_H
#define CP2_LAB_5_RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(const std::string &name, float width, float height)
        : Shape(name),
          width(width),
          height(height) {
    }

    Rectangle(float width, float height)
        : Shape("circle"),
          width(width),
          height(height) {
    }

    float width, height;

    float area() override {
        return width * height;
    };
};

#endif //CP2_LAB_5_RECTANGLE_H