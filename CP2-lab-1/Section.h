#ifndef CP2_LAB_1_SECTION_H
#define CP2_LAB_1_SECTION_H
#include "Person.h"

class Section {
public:
    Person* p1;
    Person* p2;

    //Copy and move construcotr
    Section(const Section &other) { //: p1(other.p1), p2(other.p2)
        p1 = other.p1;
        p2 = other.p2;
    }

    Section(Section &&other) { //: p1(other.p1), p2(other.p2)
        p1 = other.p1;
        p2 = other.p2;
        other.p1 = nullptr;
        other.p2 = nullptr;
    }

    Section(Person* p1, Person* p2): p1(p1), p2(p2) {};
    ~Section() {
        delete p1;
        delete p2;
    }

    void printSection() {
        std::printf("P1: Age %d, Name: %s\nP2: Age %d, Name: %s\n",
            p1->age, p1->name.c_str(), p2->age, p2->name.c_str());
    }
};

#endif //CP2_LAB_1_SECTION_H
