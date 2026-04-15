#ifndef CP2_LAB_2_MATRIX_H
#define CP2_LAB_2_MATRIX_H
#include <functional>
#include <random>
#include <vector>


class Matrix {
    public:
    std::vector<double> data;
    int rows, cols;

    // Generates a fresh matrix filled with 0
    Matrix(int inRows = 0, int inCols = 0) : rows(inRows), cols(inCols) {
        data.resize(rows * cols, 0.0);
    }

    inline double& at(int r, int c) {return data[r * cols + c];}
    inline double at(int r, int c) const {return data[r * cols + c];}

    static void randomize(Matrix& m, double min, double max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(min, max);
        for (double& cell : m.data) {
            cell = dist(gen);
        }
    }

    void printMatrix() {
        for (int i = 0; i < this->rows; i++) {
            std::printf("data: [");
            for (int j = 0; j < this->cols; j++) {
                std::printf(" %.2f, ", at(i, j));
            }
            std::printf("]\n");
        }
        std::printf("---------------\n");
    }

    void multiply(double n) {
        for (double& cell : this->data) {
            cell *= n;
        }
    }

    void add(double n) {
        for (double& cell : this->data) {
            cell += n;
        }
    }

    void addMatrix(const Matrix &m2) {
        if (this->rows != m2.rows || this->cols != m2.cols) {
            std::printf("[err] Matrix dimension mismatch in addMatrix\n");
            return;
        }

        for (size_t i = 0; i < this->data.size(); i++) {
            this->data[i] += m2.data[i];
        }
    }

    static Matrix hadamardProduct(const Matrix &m1, const Matrix &m2) {
        if (m1.rows != m2.rows || m1.cols != m2.cols) {
            std::printf("[err] Matrix dimension mismatch in hadamardProduct\n");
            return {0, 0};
        }

        Matrix result(m1.rows, m1.cols);
        for (size_t i = 0; i < m1.data.size(); i++) {
            result.data[i] = m1.data[i] * m2.data[i];
        }
        return result;
    }

    static Matrix multiplyMatrix(const Matrix &m1, const Matrix &m2) {
        if (m1.cols != m2.rows) {
            std::printf("[err] Matrix dimension mismatch in multiplyMatrix [m1.cols=%d != m2.rows=%d]\n", m1.cols, m2.rows);
            return {0, 0};
        }

        Matrix result(m1.rows, m2.cols);
        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.cols; j++) {
                double sum = 0;
                for (int k = 0; k < m1.cols; k++) {
                    sum += m1.at(i, k) * m2.at(k, j);
                }
                result.at(i, j) = sum;
            }
        }
        return result;
    }

    static Matrix addTwoMatrices(const Matrix &m1, const Matrix &m2) {
        Matrix result(m1.rows, m1.cols);
        for (size_t i = 0; i < m1.data.size(); i++) {
            result.data[i] = m1.data[i] + m2.data[i];
        }
        return result;
    }

    static Matrix transpose(const Matrix &m) {
        Matrix result(m.cols, m.rows);
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.at(j, i) = m.at(i, j);
            }
        }
        return result;
    }

    static Matrix map(Matrix m, const std::function<double(double)> &func) {
        for (double& cell : m.data) {
            cell = func(cell);
        }
        return m;
    }

    static double sigmoid(double x) {
        return 1.0 / (1.0 + std::exp(-x));
    }

    static double dsigmoid(double y) {
        return y * (1.0 - y);
    }

    static Matrix fromArray(const std::vector<double> &arr) {
        Matrix m(arr.size(), 1);
        for (size_t i = 0; i < arr.size(); i++) {
            m.at(i, 0) = arr[i];
        }
        return m;
    }

    static std::vector<double> toArray(const Matrix &m) {
        std::vector<double> arr(m.data.size());
        for (size_t i = 0; i < m.data.size(); i++) {
            arr[i] = m.data[i];
        }
        return arr;
    }

    static Matrix findDifference(const Matrix &m1, const Matrix &m2) {
        Matrix result(m1.rows, m1.cols);
        for (size_t i = 0; i < m1.data.size(); i++) {
            result.data[i] = m1.data[i] - m2.data[i];
        }
        return result;
    }

    // Easier with functions corresponding to these operations above
    Matrix operator+(const Matrix &m2) {
        Matrix newMatrix = Matrix(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                newMatrix.at(i, j) = this->at(i, j) + m2.at(i, j);
            }
        }
        return newMatrix;
    }

    Matrix operator*(const Matrix &m2) {
        if (this->cols != m2.rows) {
            std::printf("[err] Matrix dimension mismatch in multiplyMatrix [m1.cols=%d != m2.rows=%d]\n", this->cols, m2.rows);
            return {0, 0};
        }

        Matrix newMatrix = Matrix(this->rows, m2.cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                for (int k = 0; k < this->rows; k++) {
                    newMatrix.at(i, j) += this->at(i, k) * m2.at(k, j);
                }
            }
        }
        return newMatrix;
    }
};


#endif //CP2_LAB_2_MATRIX_H