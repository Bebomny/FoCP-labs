cmake_minimum_required(VERSION 4.1)
project(CP2_lab_2)

set(CMAKE_CXX_STANDARD 26)

add_executable(CP2_lab_2 main.cpp
        Matrix.h
        Network.h
        NeuralNet.cpp
        NeuralNet.h
)
