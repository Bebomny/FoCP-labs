#ifndef CP2_LABS_4_MANAGER_H
#define CP2_LABS_4_MANAGER_H
#include "FullTimeEmployee.h"

class Manager : public FullTimeEmployee {
private:
    double bonus;

public:
    Manager(double monthly_salary, double bonus)
        : FullTimeEmployee(monthly_salary),
          bonus(bonus) {
    }

    double getSalary() const override {
        return FullTimeEmployee::getSalary() + bonus;
    }

    std::string getRole() const override {
        return "Manager";
    };
};

#endif //CP2_LABS_4_MANAGER_H
