#include <iostream>

#include "Matrix.h"
#include "Network.h"
#include "NeuralNet.h"

void testMatrices();

void testXOR();

void testCircle();

int main() {
    //testMatrices();

    // testXOR();
    testCircle();

    return 0;
}

void testMatrices() {

    std::printf("-------------M1-------------\n");
    Matrix m1 = Matrix(2, 2);
    Matrix::randomize(m1, 0.0, 1.0);
    m1.printMatrix();
    std::printf("-------------M2-------------\n");
    Matrix m2 = Matrix(2, 2);
    Matrix::randomize(m2, 0.0, 1.0);
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
    Matrix::randomize(m5, 0.0, 1.0);
    network.addMatrix(m5);
    Matrix m6 = Matrix(3, 3);
    Matrix::randomize(m6, 0.0, 1.0);
    network.addMatrix(m6);
    Matrix m7 = Matrix(3, 3);
    Matrix::randomize(m7, 0.0, 1.0);
    network.addMatrix(m7);
    Matrix m8 = network.calculate();
    m8.printMatrix();

}

void testXOR() {
    std::printf("-------------XOR Test-------------\n");
    NeuralNet nn(2, 4, 1);
    int trainingCycles = 50000;

    std::vector<std::vector<double>> trainingInputs = {
        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 0.0},
        {1.0, 1.0}
    };
    std::vector<std::vector<double>> trainingTargets = {
        {0.0},
        {1.0},
        {1.0},
        {0.0}
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 3);

    std::printf("Going through %d training cycles.\n", trainingCycles);
    for (int i = 0; i < trainingCycles; i++) {
        int r = dist(gen);
        nn.train(trainingInputs[r], trainingTargets[r]);
    }

    std::printf("Training complete. Testing results:\n");

    for (int i = 0; i < 4; i++) {
        std::vector<double> result = nn.feedforward(trainingInputs[i]);
        std::printf("Inputs: [%.2f, %.2f] -> Output: %.2f (Expected: %.2f)\n",
            trainingInputs[i][0], trainingInputs[i][1], result[0], trainingTargets[i][0]);
    }
}

void testCircle() {
    std::printf("-------------Circle Test-------------\n");
    NeuralNet nn(2, 8, 1);
    // nn.learningRate = 0.05;
    int trainingCycles = 100000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    std::printf("Training network on the circle check\n");
    std::printf("Going through %d training cycles.\n", trainingCycles);
    for (int i = 0; i < trainingCycles; i++) {
        double x = dist(gen);
        double y = dist(gen);

        double target = (x*x + y*y < 0.56) ? 1.0 : 0.0;

        nn.train({x, y}, {target});
    }


    std::printf("Training complete. Networks circle model:\n");
    for (double y = 1.0; y >= -1.0; y -= 0.1) {
        for (double x = -1.0; x <= 1.0; x += 0.1) {
            std::vector<double> result = nn.feedforward({x, y});

            if (result[0] > 0.5) {
                std::printf("###");
            } else {
                std::printf("...");
            }
        }
        std::printf("\n");
    }
}
