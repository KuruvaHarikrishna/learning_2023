#include <stdio.h>

int find_biggest_if_else(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int find_biggest_ternary_operator(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int biggest_if_else = find_biggest_if_else(num1, num2);
    int biggest_ternary_operator = find_biggest_ternary_operator(num1, num2);

    printf("Using if-else: %d\n", biggest_if_else);
    printf("Using ternary operator: %d\n", biggest_ternary_operator);

    return 0;
}
