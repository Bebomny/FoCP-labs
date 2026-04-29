#ifndef CP2_LABS_4_ENGINEER_H
#define CP2_LABS_4_ENGINEER_H
#include "FullTimeEmployee.h"

class Engineer : public FullTimeEmployee {
    private:
    double projectsCompleted;
    double bonus;

public:
    Engineer(double monthly_salary, double projects_completed, double bonus)
        : FullTimeEmployee(monthly_salary),
          projectsCompleted(projects_completed),
          bonus(bonus) {
    }

    double getSalary() const override {
        return FullTimeEmployee::getSalary() + (projectsCompleted * bonus);
    }

    std::string getRole() const override {
        return "Engineer";
    };
};

#endif //CP2_LABS_4_ENGINEER_H