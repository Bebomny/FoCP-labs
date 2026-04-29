cmake_minimum_required(VERSION 4.1)
project(CP2_lab_4)

set(CMAKE_CXX_STANDARD 26)

add_executable(CP2_labs_4 main.cpp
        Employee.h
        FullTimeEmployee.h
        PartTimeEmployee.h
        Manager.h
        Engineer.h
        Intern.h)
