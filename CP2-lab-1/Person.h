#ifndef CP2_LAB_1_PERSON_H
#define CP2_LAB_1_PERSON_H
#include <string>

class Person {
public:
    int age;
    std::string name;

    // Move and Copy operators
    Person(const Person &other) { //: age(other.age), name(other.name)
        age = other.age;
        name = other.name;
    }

    Person(Person &&other) { //: age(other.age), name(std::move(other.name))
        age = other.age;
        name = std::move(other.name);
    }

    Person() : age(0), name("unknown") {}

    Person(const int age, const std::string &name) : age(age), name(name) {}

    ~Person() = default;

    void sayHello() {
        std::printf("Hello, I'm %s, at age: %d!\n", name.c_str(), age);
    };
};


#endif //CP2_LAB_1_PERSON_H
