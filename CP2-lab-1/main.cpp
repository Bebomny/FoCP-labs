#include <iostream>

#include "Person.h"
#include "Section.h"

int main() {
    Person p1 = Person(57, "Almar");
    Person p2 = Person(43, "John");

    std::printf("Declaration One:\n");
    Section section = Section(&p1, &p2);
    section.printSection();

    std::printf("Copy constructor:\n");
    Section sec2 = section;
    sec2.p1->age = 56;
    sec2.p2->age = 42;
    sec2.printSection();

    std::printf("Move Constructor:\n");
    Section sec3 = std::move(sec2);
    sec3.p1->age = 55;
    sec3.p2->age = 41;
    sec3.printSection();

    return 0;
}
