#ifndef CP2_LABS_4_EMPLOYEE_H
#define CP2_LABS_4_EMPLOYEE_H
#include <string>

class Employee {
public:
    virtual double getSalary() const = 0;

    virtual std::string getRole() const = 0;

    virtual ~Employee() = default;
};

#endif //CP2_LABS_4_EMPLOYEE_H
