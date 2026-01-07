#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <vector>

int main() {
    printf("----------Task 1----------\n");
    std::vector<int> vec = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    // print
    printf("Print:\n");
    std::ranges::for_each(vec, [](const int &i) {
       printf("%d, ", i);
    });
    printf("\n");

    // modify with += 5 and print
    printf("Modify and print:\n");
    std::ranges::for_each(vec, [](int &i) {
        i+=5;
    });
    std::ranges::for_each(vec, [](const int &i) {
       printf("%d, ", i);
    });
    printf("\n");

    //reverse and print
    printf("Reverse and print:\n");
    std::ranges::reverse(vec);
    std::ranges::for_each(vec, [](const int &i) {
       printf("%d, ", i);
    });
    printf("\n");

    printf("----------Task 2----------\n");
    struct Point {
        double x, y;
    };
    std::vector<Point> points = {};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-10.0, 10.0);
    for (int i = 0; i < 8; ++i) {
        points.push_back({dis(gen), dis(gen)});
    }
    std::ranges::for_each(points, [](const Point &p) {
       printf("{%.2f, %.2f},", p.x, p.y);
    });
    printf("\n");

    printf("Sort and print\n");
    std::ranges::sort(points, [](const Point &p1, const Point &p2) {
        return (std::sqrt(p1.x*p1.x + p1.y*p1.y) - std::sqrt(p2.x*p2.x + p2.y*p2.y)) > 0;
    });
    std::ranges::for_each(points, [](const Point &p) {
       printf("{%.2f, %.2f},", p.x, p.y);
    });
    printf("\n");

    printf("In first quadrant: ");
    int countInFirstQuadrant = 0;
    std::ranges::for_each(points, [&countInFirstQuadrant](const Point &p) {
        if (p.x > 0 && p.y > 0) {
            countInFirstQuadrant += 1;
        }
    });
    printf("%d\n", countInFirstQuadrant);


    printf("----------Task 3----------\n");
    std::map<std::string, int> wordMap = {};
    for (int i = 0; i < 10; ++i) {
        printf("Please provide a word: ");
        std::string in;
        std::cin >> in;

        int val = 1;
        if (wordMap.contains(in)) {
            val = wordMap[in];
            val+=1;
        }
        wordMap.insert_or_assign(in, val);
        printf("\n");
    }
    std::ranges::for_each(wordMap, [](const std::pair<std::string, int>& pair) {
        printf("{%s, %d},", pair.first.c_str(), pair.second);
    });
    printf("\n");

    printf("Remove single words\n");
    std::erase_if(wordMap, [](const std::pair<std::string, int>& pair) {
        return pair.second == 1;
    });
    std::ranges::for_each(wordMap, [](const std::pair<std::string, int>& pair) {
        printf("{%s, %d},", pair.first.c_str(), pair.second);
    });
    printf("\n");

    printf("----------Task 4----------\n");
    printf("Multiples of 3 and print: \n");
    std::vector<int> ints = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int counter = 1;
    std::ranges::for_each(ints, [&counter](int &i) {
        i = 3*counter;
        ++counter;
    });
    std::ranges::for_each(ints, [](int &i) {
        printf("%d, ", i);
    });
    printf("\n");

    printf("Square and print\n");
    std::ranges::for_each(ints, [](int &i) {
        i = i*i;
    });
    std::ranges::for_each(ints, [](int &i) {
        printf("%d, ", i);
    });
    printf("\n");

}