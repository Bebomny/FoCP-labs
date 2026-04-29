#ifndef CP2_LABS_4_PARTTIMEEMPLOYEE_H
#define CP2_LABS_4_PARTTIMEEMPLOYEE_H
#include "Employee.h"

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    PartTimeEmployee(double hourly_rate, double hours_worked)
        : hourlyRate(hourly_rate),
          hoursWorked(hours_worked) {
    }

    double getSalary() const override {
        return hourlyRate * hoursWorked;
    }

    std::string getRole() const override {
        return "PartTimeEmployee";
    };
};

#endif //CP2_LABS_4_PARTTIMEEMPLOYEE_H
