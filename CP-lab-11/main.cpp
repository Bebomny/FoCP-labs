#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

double power(double base, double exp) {
    double result = 1;
    for (int i = 1; i <= exp; i++) {
        result *= base;
    }
    return result;
}

double maxValue(double a, double b) {
    return a > b ? a : b;
}

double minValue(double a, double b) {
    return a < b ? a : b;
}

double average(double a, double b) {
    return (a + b) / 2;
}

//task 2
bool isEven(int number) {
    return number % 2 == 0;
}

bool isPositive(int number) {
    return number > 0;
}

bool isPrime(int number) {
    int count = 0;
    if (number <= 1) {
        return false;
    }

    for (int i = 1; i <= number; i++) {
        if (number % i == 0)
            count++;
    }


    if (count > 2)
        return false;

    return true;
}

int main() {
    //----------Task 1----------
    printf("----------Task 1----------\n");
    double (*powerP)(double, double) = power;
    double (*maxP)(double, double) = maxValue;
    double (*minP)(double, double) = minValue;
    double (*averageP)(double, double) = average;

    double (*funArray[4])(double, double) = {powerP, maxP, minP, averageP};

    printf("Provide the first param: ");
    int param1 = -1;
    std::cin >> param1;
    printf("\nParam2: ");
    int param2 = -1;
    std::cin >> param2;
    printf("Which function to execute[0->power, 1->max, 2->min, 3->avg]: ");
    int inF = -1;
    std::cin >> inF;
    printf("\n");
    double res = -1;
    switch (inF) {
        default:
            printf("Invalid input");
            break;
        case 0:
            res = funArray[0](param1, param2);
            printf("Result of power: %f\n", res);
            break;
        case 1:
            res = funArray[1](param1, param2);
            printf("Result of max: %f\n", res);
            break;
        case 2:
            res = funArray[2](param1, param2);
            printf("Result of min: %f\n", res);
            break;
        case 3:
            res = funArray[3](param1, param2);
            printf("Result of average: %f\n", res);
            break;
    }

    //----------Task 2----------
    printf("----------Task 2----------\n");
    typedef bool (*pib)(int);
    std::vector<pib> pibs = {isEven, isPositive, isPrime};
    int c = 0;
    for (auto pib1: pibs) {
        printf("pib[%d]: %hhd\n", c, pib1(res));
    }

    //----------Task 3----------
    printf("----------Task 3----------\n");
    printf("Provide a size for the array: ");
    int aSize = 0;
    std::cin >> aSize;
    printf("\n");
    auto arr = new double[aSize];
    for (int i = 0; i < aSize; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0.0, 1.0);
        arr[i] = dis(gen);
    }
    double min = 1, max = 0, avg = 0;
    for (int i = 0; i < aSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }

        avg += arr[i];
    }
    avg /= aSize;
    printf("Minimum: %f\n", min);
    printf("Maximum: %f\n", max);
    printf("Average: %f\n", avg);
    delete[] arr;

    //----------Task 4----------
    printf("----------Task 4----------\n");

    auto arr2 = new int[10];
    std::ranges::generate(arr2, arr2 + 10, []() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 10);
        return dis(gen);
    });
    printf("Original Array: {");
    std::ranges::for_each(arr2, arr2 + 10, [](int &i) {
        printf("%d, ", i);
    });
    printf("}\n");

    std::ranges::for_each(arr2, arr2 + 10, [](int &i) {
        i = i * 2;
    });
    printf("Doubled: {");
    std::ranges::for_each(arr2, arr2 + 10, [](int &i) {
        printf("%d, ", i);
    });
    printf("}\n");

    std::ranges::for_each(arr2, arr2 + 10, [](int &i) {
        i += 5;
    });
    printf("Incremented by 5: {");
    std::ranges::for_each(arr2, arr2 + 10, [](int &i) {
        printf("%d, ", i);
    });
    printf("}\n");

    std::ranges::for_each(arr2, arr2 + 10, [](int &i) {
        i = i * i;
    });
    printf("Squared: {");
    std::ranges::for_each(arr2, arr2 + 10, [](int &i) {
        printf("%d, ", i);
    });
    printf("}\n");
    delete[] arr2;
}
