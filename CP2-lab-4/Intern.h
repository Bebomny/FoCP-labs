#ifndef CP2_LABS_4_INTERN_H
#define CP2_LABS_4_INTERN_H
#include "PartTimeEmployee.h"

class Intern : public PartTimeEmployee {
    public:
    Intern(double hourly_rate, double hours_worked)
        : PartTimeEmployee(hourly_rate, hours_worked) {
    }

    double getSalary() const override {
        return 0.8 * PartTimeEmployee::getSalary();
    }

    std::string getRole() const override {
        return "Intern";
    };

    std::string getMessage() const {
        return "Git whats that?";
    };
};

#endif //CP2_LABS_4_INTERN_H