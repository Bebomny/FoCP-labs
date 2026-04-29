#ifndef CP2_LABS_4_FULLTIMEEMPLYEE_H
#define CP2_LABS_4_FULLTIMEEMPLYEE_H
#include "Employee.h"

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(double monthly_salary)
        : monthlySalary(monthly_salary) {
    }

    double getSalary() const override {
        return monthlySalary;
    }

    std::string getRole() const override {
        return "FullTimeEmployee";
    };
};

#endif //CP2_LABS_4_FULLTIMEEMPLYEE_H
