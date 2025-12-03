#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <fstream>
#include <map>
#include <numeric>

std::pair<std::string, int> getWordWithHighestCount(std::map<std::string, int> map);

int main() {
    printf("----------Part 1----------\n");
    // 1. Fixed-size arrays.
    // Declare a std::array<int, 10> and initialize it with values from 1 to 10.
    // Write a function that computes the average of all elements.
    // Print the first, last, and middle elements using .front(), .back(), and indexing.
    // Iterate with a range-based for loop and print all values.
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int avg = 0;
    std::ranges::for_each(arr,[&avg](int i) { avg += i; });
    avg /= arr.size();

    int first = arr.front();
    int last = arr.back();
    int middle = arr[arr.size() / 2];
    printf("avg: %d, first: %d, last: %d, middle: %d\n", avg, first, last, middle);
    printf("Array: [");
    std::ranges::for_each(arr, [](int i) { printf("%d,", i); });
    printf("]\n");

    printf("----------Part 2----------\n");
    // 1. Associative containers (std::map, std::unordered_map).
    // Open the file Shakespeare.txt.
    // Read words one by one and count their occurrences using std::map<std::string, int>.
    // Print the 10 most frequent words. Repeat using std::unordered_map and compare performance.
    // Here is an example of code measuring time:
    auto start = std::chrono::high_resolution_clock::now();
    std::fstream shakespeareFile;
    shakespeareFile.open("Shakespeare.txt");
    std::map<std::string, int> wordMap;

    std::string line;
    while (std::getline(shakespeareFile, line)) {
        std::stringstream lineStream (line);
        std::string word;
        while (lineStream >> word) {
            wordMap[word]++;
        }
    }

    //Get highest value x10
    std::map<std::string, int> topWords;

    for (int i = 0; i < 10; ++i) {
        auto word = getWordWithHighestCount(wordMap);
        topWords.insert(word);
        wordMap[word.first] = 0;
    }

    std::ranges::for_each(topWords, [](std::pair<std::string, int> p) {printf("Word [%s] with %d occurrences\n", p.first.data(), p.second); });

    auto end =std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_ms = end - start;
    printf("Took %fms to complete", duration_ms.count());
    return 0;
}

std::pair<std::string, int> getWordWithHighestCount(std::map<std::string, int> map) {
    std::pair<std::string, int> result;
    for (auto & it : map) {
        if (it.second > result.second) {
            result = make_pair(it.first, it.second);
        }
    }
    return result;
}
