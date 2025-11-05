#include <iostream>
#include <print>
#include <ranges>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

int getNextEven();

int countPositive(int testArray[], int length);

std::vector<int> addLongInt(std::vector<int> vec1, std::vector<int> vec2);

long double approxPi(int iterations);

int main() {
    /*
     * 1. Understanding static variables in functions.
     *  Create a function called next_even()  that returns consecutive even numbers starting from 0.
     *  Use a static variable to keep track of the current even number.
     *  Each call should return the next even number (0, 2, 4, 6, ...).
     *  Test it by calling it 5 times in a loop and printing the results
     **/
    printf("----------Task 1----------\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d, ", getNextEven());
    }
    printf("\n");
    printf("----------Task 2----------\n");
    /*
    *2. Passing arrays to functions.
    *   Write a function called count_positive() that takes an array of integers and its size,
    *   then returns how many positive numbers (> 0) are in the array. Test it with:
    *   int numbers[] = {1, -2, 3, -4, 5, 0, 7};
    **/
    int numbers[] = {1, -2, 3, -4, 5, 0, 7};
    printf("Positive: %d", countPositive(numbers, 7));
    printf("\n");
    printf("----------Task 3----------\n");
    /*
     *3. Using the vector<> template.
     *   Write a function addlongint() that takes two vectors of integers,
     *   assuming that each vector is a sequence of decimal digits in two numbers x and y.
     *   The functions should return the sum x+y in the same form, as a vector of digits.
     *   Pay attention to the situation when the numbers x, y have a different number of digits.
     **/
    std::vector<int> test1 = {1, 3, 9, 3, 4, 5, 1};
    std::vector<int> test2 = {5, 6, 4, 7, 9};
    for (int number: test1) {
        printf("%d, ", number);
    }
    printf("\n");
    for (int number: test2) {
        printf("%d, ", number);
    }
    printf("\n");
    std::vector<int> result = addLongInt(test1, test2);
    for (int number: result) {
        printf("%d, ", number);
    }
    printf("\n");
    printf("----------Task 4----------\n");
    /*
     *4. Approximating Pi.
     *   Suppose we can only perform addition, subtraction, multiplication, and division on real numbers.
     *   Write a program that uses these operations to approximate Pi using Machin's formula (https://en.wikipedia.org/wiki/Machin-like_formula):
     **/
    long double a = 0.0;
    printf("Size of long double: %llu\n", sizeof(a));
    long double res = approxPi(10000);
    printf("Final Result: %.100Lg", res);
}

int getNextEven() {
    static int even = -2;
    return even += 2;
}

int countPositive(int testArray[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (testArray[i] > 0) {
            sum++;
        }
    }
    return sum;
}

std::vector<int> addLongInt(std::vector<int> vec1, std::vector<int> vec2) {
    std::vector<int> result;
    std::ranges::reverse(vec1);
    std::ranges::reverse(vec2);
    //Equalize vectors
    if (vec1.size() > vec2.size()) {
        int diff = vec1.size() - vec2.size();
        for (int i = 0; i < diff; i++) {
            vec2.push_back(0);
        }
    } else {
        int diff = vec2.size() - vec1.size();
        for (int i = 0; i < diff; i++) {
            vec1.push_back(0);
        }
    }
    //add them
    bool carry = false;
    for (int i = 0; i < vec2.size(); ++i) {
        int digit = vec1[i] + vec2[i] + carry;
        carry = false;
        if (digit > 9) {
            carry = true;
            digit %= 10;
        }
        result.push_back(digit);
    }

    std::ranges::reverse(result);
    return result;
}

long double approxPi(const int iterations) {
    long double result = 0;
    result = (16.0/5.0) - (4.0/239.0);
    for (int i = 1; i < iterations; i++) {
        const long double part1 = 16.0/(std::pow(5.0, 1.0+2.0*i));
        const long double part2 = 4.0/(std::pow(239.0, 1.0+2.0*i));
        result -= (1.0/(1.0+2.0*i)) * (part1 - part2);
        printf("Iter %d, Result: %.10Lg\n", i, result);
        //printf("\r");
    }
    printf("\n");
    return result;
}
