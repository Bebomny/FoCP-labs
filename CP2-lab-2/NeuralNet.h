//
// Created by Luka on 18/03/2026.
//

#ifndef CP2_LAB_2_NEURALNET_H
#define CP2_LAB_2_NEURALNET_H
#include <vector>

#include "Matrix.h"


class NeuralNet {
    int inputNodes;
    int hiddenNodes;
    int outputNodes;

    std::vector<Matrix> weightsIH;
    std::vector<Matrix> weightsHO;
};


#endif //CP2_LAB_2_NEURALNET_H