//
// Created by Luka on 18/03/2026.
//

#ifndef CP2_LAB_2_NEURALNET_H
#define CP2_LAB_2_NEURALNET_H
#include <vector>

#include "Matrix.h"


class NeuralNet {
public:
    int inputNodes;
    int hiddenNodes;
    int outputNodes;

    double learningRate = 0.1f;

    Matrix weights_ih, weights_ho;
    Matrix bias_h, bias_o;

    NeuralNet(int numInput, int numHidden, int numOutput) {
        inputNodes = numInput;
        hiddenNodes = numHidden;
        outputNodes = numOutput;

        weights_ih = Matrix(numHidden, numInput);
        weights_ho = Matrix(numOutput, numHidden);
        Matrix::randomize(weights_ih, -1.0, 1.0);
        Matrix::randomize(weights_ho, -1.0, 1.0);

        bias_h = Matrix(numHidden, 1);
        bias_o = Matrix(numOutput, 1);
        Matrix::randomize(bias_h, -1.0, 1.0);
        Matrix::randomize(bias_o, -1.0, 1.0);
    }

    std::vector<double> feedforward(const std::vector<double>& inputArray) {
        Matrix inputs = Matrix::fromArray(inputArray);

        //Hidden layer
        Matrix hidden = Matrix::multiplyMatrix(weights_ih, inputs);
        hidden = Matrix::addTwoMatrices(hidden, bias_h);
        hidden = Matrix::map(hidden, Matrix::sigmoid);

        //Outputt layer
        Matrix output = Matrix::multiplyMatrix(weights_ho, hidden);
        output = Matrix::addTwoMatrices(output, bias_o);
        output = Matrix::map(output, Matrix::sigmoid);

        return Matrix::toArray(output);
    }

    void train(const std::vector<double>& inputArray, const std::vector<double>& targetArray) {
        Matrix inputs = Matrix::fromArray(inputArray);
        Matrix targets = Matrix::fromArray(targetArray);

        Matrix hidden = Matrix::multiplyMatrix(weights_ih, inputs);
        hidden = Matrix::addTwoMatrices(hidden, bias_h);
        hidden = Matrix::map(hidden, Matrix::sigmoid);

        Matrix outputs = Matrix::multiplyMatrix(weights_ho, hidden);
        outputs = Matrix::addTwoMatrices(outputs, bias_o);
        outputs = Matrix::map(outputs, Matrix::sigmoid);

        //output error correction
        Matrix outputErrors = Matrix::findDifference(targets, outputs);

        Matrix gradients = Matrix::map(outputs, Matrix::dsigmoid);
        gradients = Matrix::hadamardProduct(gradients, outputErrors);
        gradients.multiply(learningRate);

        //adjust weights
        Matrix hidden_T = Matrix::transpose(hidden);
        Matrix weight_ho_deltas = Matrix::multiplyMatrix(gradients, hidden_T);
        weights_ho = Matrix::addTwoMatrices(weights_ho, weight_ho_deltas);
        bias_o = Matrix::addTwoMatrices(bias_o, gradients);

        //hidden error correction
        Matrix who_T = Matrix::transpose(weights_ho);
        Matrix hiddenErrors = Matrix::multiplyMatrix(who_T, outputErrors);

        Matrix hiddenGradient = Matrix::map(hidden, Matrix::dsigmoid);
        hiddenGradient = Matrix::hadamardProduct(hiddenGradient, hiddenErrors);
        hiddenGradient.multiply(learningRate);

        //adjust weigths
        Matrix inputs_T = Matrix::transpose(inputs);
        Matrix weight_ih_deltas = Matrix::multiplyMatrix(hiddenGradient, inputs_T);
        weights_ih = Matrix::addTwoMatrices(weights_ih, weight_ih_deltas);
        bias_h = Matrix::addTwoMatrices(bias_h, hiddenGradient);
    }
};


#endif //CP2_LAB_2_NEURALNET_H