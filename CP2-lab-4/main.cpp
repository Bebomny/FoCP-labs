#include <iostream>
#include <memory>
#include <vector>

#include "Employee.h"
#include "Engineer.h"
#include "Intern.h"
#include "Manager.h"

int main() {
    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::make_unique<Intern>(1, 69));
    employees.push_back(std::make_unique<Intern>(1, 69));
    employees.push_back(std::make_unique<Manager>(3000, 500));
    employees.push_back(std::make_unique<Manager>(3000, 500));
    employees.push_back(std::make_unique<Manager>(3000, 500));
    employees.push_back(std::make_unique<Manager>(3000, 500));
    employees.push_back(std::make_unique<Manager>(3000, 500));
    employees.push_back(std::make_unique<Engineer>(1000, 1, 100));

    double totalSalary = 0;
    for (const auto & employee : employees) {
        totalSalary += employee->getSalary();
    }

    std::string team;
    for (const auto & employee : employees) {
        team.append(employee->getRole());
        team.append(",");
    }

    std::printf("Total Team salary: %f for a team of [%s]\n", totalSalary, team.c_str());

    const auto *intern = dynamic_cast<Intern *>(employees[0].get());
    std::printf("Intern comment: \"%s\"\n", intern->getMessage().c_str());
}
