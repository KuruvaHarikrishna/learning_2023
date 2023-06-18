#include <stdio.h>

int findMax(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int a, b;

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    int max = findMax(a, b);

    printf("The biggest number is: %d\n", max);

    return 0;
}
