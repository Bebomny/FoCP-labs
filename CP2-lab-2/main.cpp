#include <iostream>

#include "Matrix.h"
#include "Network.h"

int main() {

    std::printf("-------------M1-------------\n");
    Matrix m1 = Matrix(2, 2);
    m1.initializeRandomMatrix();
    m1.printMatrix();
    std::printf("-------------M2-------------\n");
    Matrix m2 = Matrix(2, 2);
    m2.initializeRandomMatrix();
    m2.printMatrix();

    //Addition
    std::printf("-------------Added-------------\n");
    Matrix m3 = m1 + m2;
    m3.printMatrix();

    //Multiplication
    std::printf("--------------Mult-------------\n");
    Matrix m4 = m1 * m2;
    m4.printMatrix();

    std::printf("--------------Network-------------\n");
    Network network = Network();
    Matrix m5 = Matrix(2, 2);
    m5.initializeRandomMatrix();
    network.addMatrix(m5);
    Matrix m6 = Matrix(3, 3);
    m6.initializeRandomMatrix();
    network.addMatrix(m6);
    Matrix m7 = Matrix(3, 3);
    m7.initializeRandomMatrix();
    network.addMatrix(m7);
    Matrix m8 = network.calculate();
    m8.printMatrix();

}
