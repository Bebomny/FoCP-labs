#include <iostream>

void swap_ptr(int* a, int* b);

struct point {
    double x, y;

    void move (double x_move, double y_move);
};

int main() {
    printf("----------Part 1----------\n");
    int a = 2;
    int b = 3;
    printf(" Before: a = %d, b = %d\n", a, b);
    swap_ptr(&a, &b);
    printf("After: a = %d, b = %d\n", a, b);

    printf("----------Part 2----------\n");
    point p = {2, 3};
    point *p_ptr = &p;
    printf("Point by value, p.x: %f, p.y: %f\n", p.x, p.y);
    printf("Point by reference, p->x: %f, p->y: %f\n", p_ptr->x, p_ptr->y);
    printf("Moving by 4, 6\n");
    p.move(4, 6);
    printf("Result, p.x: %f, p.y: %f\n", p.x, p.y);

    printf("----------Part 3----------\n");
    const int arr[] = {1, 2, 3, 4, 5};
    int sum = 0;
    const int *val = arr;
    int x = 5;
    while (x--) {
        sum += *val++;
    }
    printf("Sum: %d\n", sum);

    printf("----------Part 4----------\n");
    int arr2d[5][5] = {{1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}};
    int sum2 = 0;
    const int *val2 = *arr2d;
    int x2 = 5*5;
    while (x2--) {
        sum2 += *val2++;
    }
    printf("Sum2: %d\n", sum2);

    printf("----------Part 5----------\n");
    char in[] = "";
    scanf("%s", in);
    printf("%s\n", in);
    return 0;
}

void swap_ptr(int* a, int* b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

void point::move (const double x_move, const double y_move) {
    this->x = this->x + x_move;
    this->y = this->y + y_move;
}