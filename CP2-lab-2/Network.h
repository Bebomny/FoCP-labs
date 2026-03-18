//
// Created by Luka on 18/03/2026.
//

#ifndef CP2_LAB_2_NETWORK_H
#define CP2_LAB_2_NETWORK_H
#include "Matrix.h"


class Network {
public:
    std::vector<Matrix> matrices;

    Network() = default;

    void addMatrix(Matrix m) {
        matrices.push_back(m);
    }

    Matrix calculate() {
        Matrix result = matrices[0];
        for (int i = 1; i < matrices.size(); i++) {
            result = result * matrices[i];
        }
        return result;
    }
};


#endif //CP2_LAB_2_NETWORK_H