#include <cstring>
#include <iostream>
#include <print>
#include <string>
#include <fstream>

void simpleCalc(int argc, char* args[]);

void simpleDB(int argc, char* args[]);
void simpleDBInput(int argc, char* args[]);
void simpleDBOutput(int argc, char* args[]);

struct dbEntry {
    std::string name;
    std::string surname;
    std::string phoneNum;
};

int main(int argc, char* args[]) {
    printf("Hello there!\n");
    if (argc < 5) {
        printf("Please provide at least 5 arguments\n");
        return -1;
    }

    if (strcmp(args[1], "eval") == 0) {
        simpleCalc(argc, args);
    } else if (strcmp(args[1], "db") == 0) {
        simpleDB(argc, args);
    } else {
        printf("First argument should be one of these:\n - eval\n - db\n");
        return -1;
    }

    return 0;
}

void simpleDB(int argc, char *args[]) {
    if (strcmp(args[2], "input") == 0) {
        simpleDBInput(argc, args);
    } else if (strcmp(args[2], "output") == 0) {
        simpleDBOutput(argc, args);
    }
}

void simpleDBOutput(int argc, char *args[]) {

}

void simpleDBInput(int argc, char *args[]) {
    std::fstream file;
    file.open(args[3]);
    if (file.is_open()) {
        std::string line;
        int iter = 0;
        printf("Enter \"end\" to finish\nName: ");
        while (true) {
            std::cin >> line;
            // std::cout << line << std::endl;
            if (line.compare("end") == 0) {
                break;
            }
            file << line;
            iter++;
            if (iter % 3 == 0) {
                file << std::endl;
                printf("name: ");
            } else if (iter % 3 == 1) {
                file << " ";
                printf("surname: ");
            } else if (iter % 3 == 2) {
                file << " ";
                printf("phone num:");
            }
        }
        file.close();
    }
}

void simpleCalc(int argc, char* args[]) {
    // printf("Params: %s, %s, %s, %s\n", args[1], args[2], args[3], args[4]);

    int num1 = atoi(args[2]);
    int num2 = atoi(args[4]);
    int result = 0;
    if (strcmp(args[3], "+") == 0) {
        result = num1 + num2;
    } else if (strcmp(args[3], "-") == 0) {
        result = num1 - num2;
    } else if (strcmp(args[3], "*") == 0) {
        result = num1 * num2;
    } else if (strcmp(args[3], "/") == 0) {
        result = num1 / num2;
    } else {
        printf("Invalid operation: %s", args[3]);
    }

    printf("Result: %s %s %s = %d\n",args[2], args[3], args[4], result);
}