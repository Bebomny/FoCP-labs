#include <cstring>
#include <fstream>
#include <iostream>
#include <random>
#include <regex>
#include <map>

#define true 0
#define false 1

void fillFileWithRandomNums(std::fstream fileStream, int col, int rows);
std::string caesarEncrypt(std::string str, int shift);

int main() {

    //part one
    std::fstream writeFileStream;
    writeFileStream.open("fileOne.csv");
    if (writeFileStream.is_open()) {
        fillFileWithRandomNums(std::move(writeFileStream), 30, 100);
    }
    writeFileStream.close();

    //part two
    std::fstream readFileStream;
    readFileStream.open("fileOne.csv");
    std::vector<int> sums = {};
    if (readFileStream.is_open()) {
        std::string val = "";
        while (readFileStream >> val) {
            std::vector<int> values = {};
            char *nums = std::strtok(val.data(), ",");
            while (nums != nullptr) {
                values.push_back(std::stoi(nums));
                nums = std::strtok(nullptr, ",");
            }

            int sumTotal = 0;
            for (int i = 0; i < values.size(); i++) {
                sumTotal += values[i];
            }
            sums.push_back(sumTotal);
            printf("Total: %d\n", sumTotal);
        }
    }

    //part three
    std::fstream writeFileStream2;
    writeFileStream2.open("100sums.txt");
    if (writeFileStream2.is_open()) {
        for (int i = 0; i < sums.size(); i++) {
            writeFileStream2 << sums[i] << std::endl;
        }
    }
    writeFileStream2.close();

    std::map<int, int> intervals = {};
    for (int i = 0; i < sums.size(); i++) {
        int num = sums[i];
        int interval = num / 99;
        if (!intervals.contains(interval)) {
            intervals[interval] = 1;
        } else {
            intervals[interval] += 1;
        }
    }

    printf("---------------part d---------------\n");
    for (auto pair : intervals) {
        printf("%d: ", pair.first);
        for (int i = 0; i < pair.second; i++) {
            printf("*");
        }
        printf("\n");
    }

    printf("String to encrypt:\n");
    std::string strToEncrypt;
    std::cin >> strToEncrypt;
    printf("Shift:\n");
    int shift;
    std::cin >> shift;
    std::string encryptedStr = caesarEncrypt(strToEncrypt, shift);
    printf("Encrypted string: [%s]\n", encryptedStr.c_str());

    return 0;
}

void fillFileWithRandomNums(std::fstream fileStream, const int col, const int rows) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 99);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < col; ++j) {
            fileStream << dist(gen) << ",";
        }
        fileStream << std::endl;
    }
}

std::string caesarEncrypt(std::string input, int shift) {
    //A-Z 65->90  space->20
    shift = (shift % 26 + 26) % 26;

    auto shift_char = [shift](char c) -> char {
        if (c == ' ') return ' ';

        // Convert to uppercase
        c = std::toupper(static_cast<unsigned char>(c));

        if (c >= 'A' && c <= 'Z') {
            return static_cast<char>('A' + (c - 'A' + shift) % 26);
        }

        // For unsupported characters you can choose behavior:
        // return c;     // (option 1) pass through unchanged
        // return ' ';   // (option 2) replace with space
        return c;
    };

    std::string output;
    output.reserve(input.size());

    for (char c : input | std::views::transform(shift_char)) {
        output.push_back(c);
    }

    return output;
}