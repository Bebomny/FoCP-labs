#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <numeric>

std::unique_ptr<int[]> makeSequence(std::size_t n) {
    auto seq = std::make_unique<int[]>(n);
    for (int i = 0; i < n; i++) {
        seq[i] = i * 2;
    }
    return seq;
}

struct Node {
    int value;
    std::shared_ptr<Node> next;
};

int my_strcmp(const char* a, const char* b) {
    if (a == b) {
        return 0;
    }

    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
    }
    return 0;
}

int main() {
    //----------Task  1----------
    size_t n = 10;
    std::unique_ptr<int[]> sequence = makeSequence(n);
    for (int i = 0; i < n; ++i) {
        printf("%d, ", sequence[i]);
    }
    printf("\n");

    std::unique_ptr<int[]> sequence2;
    sequence2 = std::move(sequence);

    //----------Task  2----------
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();
    auto node3 = std::make_shared<Node>();
    node1->next = node2;
    node2->next = node3;
    printf("UseCount, n1: %d, n2, %d, n3 %d\n", node1.use_count(), node2.use_count(), node3.use_count());

    auto addSharedn2 = node2->next;
    node1->next = nullptr;
    printf("UseCount, n1: %d, n2, %d, n3 %d\n", node1.use_count(), node2.use_count(), node3.use_count());

    //----------Task  3----------
    printf("for \"abc\" and \"abc\": %d\n", my_strcmp("abc", "abc"));
    printf("for \"abd\" and \"abc\": %d\n", my_strcmp("abd", "abc"));
    printf("for \"abf\" and \"abc\": %d\n", my_strcmp("abf", "abc"));
    printf("for \"abc\" and \"abf\": %d\n", my_strcmp("abc", "abf"));

    //----------Task  4----------
    std::string cfg1 = {R"cfg(# Config)cfg"};
    std::string cfg2 = {R"cfg(path = C:\data\files)cfg"};
    std::string cfg3 = {R"cfg(mode = "safe")cfg"};
    printf("%s\n%s\n%s\n", cfg1.c_str(), cfg2.c_str(), cfg3.c_str());

}