cmake_minimum_required(VERSION 4.1)
project(CP2_lab_5)

set(CMAKE_CXX_STANDARD 26)

add_executable(CP2_lab_5 main.cpp
        Shape.h
        Circle.h
        Rectangle.h
        Cylinder.h)
