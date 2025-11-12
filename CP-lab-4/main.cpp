#include <iostream>
#include <print>
#include <vector>

int myStrLen(char *str);

int gcd(int a, int b);

int lcm(int a, int b);

std::vector<int> sieve(int max);

int main() {
    printf("----------Task 1----------\n");
    char str[16] = "Hello World!";
    const int len = myStrLen(str);
    printf("The length of the string \"%s\" is: %d\n", str, len);

    printf("----------Task 2----------\n");
    int a = 64;
    int b = 128;
    int g = gcd(a, b);
    printf("The gcd(%d, %d) is %d\n", a, b, g);

    printf("----------Task 3----------\n");
    int c = 64;
    int d = 32;
    int lc = lcm(c, d);
    printf("The lcm(%d, %d) is %d\n", c, d, lc);

    printf("----------Task 4----------\n");
    std::vector<int> v = sieve(200);
    printf("The sieve(200) is: \n");
    for (int val : v) {
        printf("%d, ", val);
    }
    printf("\n");

    return 0;
}

int myStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int gcd(const int a, const int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(const int a, const int b) {
    return a * b / gcd(a, b);
}

std::vector<int> sieve(int max) {
    //fill
    std::vector<int> vec = {};
    for (int i = 2; i < max; i++) {
        vec.push_back(i);
    }

    for (int i = 2; i < max; i++) {
        for (int j = 2*i; j < max; j+=i) {
            vec.at(j-2) = 0;
        }
    }

    std::vector<int> finalVec = {};
    for (int num : vec) {
        if (num != 0) {
            finalVec.push_back(num);
        }
    }
    return finalVec;
}
