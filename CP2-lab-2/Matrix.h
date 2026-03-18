//
// Created by Luka on 18/03/2026.
//

#ifndef CP2_LAB_2_MATRIX_H
#define CP2_LAB_2_MATRIX_H
#include <random>
#include <vector>


class Matrix {
    public:
    std::vector<std::vector<double>> matrix;
    int rows, cols;

    // Generates a fresh matrix filled with 0
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;

        for (int i = 0; i < rows; i++) {
            std::vector<double> row;
            for (int j = 0; j < cols; j++) {
                row.push_back(0);
            }
            matrix.push_back(row);
        }
    }

    Matrix(std::vector<std::vector<double>> freshMatrix) {
        this->matrix = freshMatrix;
        this->rows = freshMatrix.size();
        this->cols = freshMatrix[0].size();
    }

    Matrix operator*(const Matrix &m2) {
        Matrix newMatrix = Matrix(this->rows, m2.cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                for (int k = 0; k < this->rows; k++) {
                    newMatrix.matrix[i][j] += this->cellAt(i, k) * m2.cellAt(k, j);
                }
            }
        }
        return newMatrix;
    }

    Matrix operator+(const Matrix &m2) {
        Matrix newMatrix = Matrix(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                newMatrix.matrix[i][j] = this->cellAt(i, j) + m2.cellAt(i, j);
            }
        }
        return newMatrix;
    }

    void initializeRandomMatrix() {
        std::random_device rd;
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                matrix.at(i).at(j) = dist(rd);
            }
        }
    }

    double cellAt(int row, int col) const {
        return matrix.at(row).at(col);
    }

    void printMatrix() {
        for (int i = 0; i < this->rows; i++) {
            std::printf("[");
            for (int j = 0; j < this->cols; j++) {
                std::printf("%.2f, ", matrix.at(i).at(j));
            }
            std::printf("]\n");
        }
    }
};


#endif //CP2_LAB_2_MATRIX_H