#include <iostream>
#include <print>
#include <cmath>

void multiplicationTable();
void convertBinary(int num);
inline double powxtox(double x);

int main() {
    int a = 5, b = 3, c = 2, d = 8;
    int result1 = a + b * c - d / c % b;
    int result2 = !a & b | c ^ ~d;
    int result3 = a++ + --b * c;
    int result4 = a > b && c < d || !b;

    std::printf("result1 = %d\n", result1);
    std::printf("result2 = %d\n", result2);
    std::printf("result3 = %d\n", result3);
    std::printf("result4 = %d\n", result4);

    multiplicationTable();
    convertBinary(-8);

    double xtox = powxtox(10);

    return 0;
}

void multiplicationTable() {
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 12; j++) {
            std::printf(" %2d * %2d = %3d |", i, j, i * j);
        }
        std::printf("\n");
    }
}

void convertBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            std::printf("1");
        } else
            std::printf("0");
    }
}

double powxtox(double x) {
    return std::pow(x, x);
}