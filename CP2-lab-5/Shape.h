#ifndef CP2_LAB_5_SHAPE_H
#define CP2_LAB_5_SHAPE_H
#include <string>

class Shape {
public:
    Shape(const std::string &name): name(name) {}

    virtual ~Shape() = default;

    std::string name;
    virtual float area() = 0;
};

#endif //CP2_LAB_5_SHAPE_H