#include <stdio.h>
void printPattern1ToN(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
    }
}
void printSpaces(int n) {
    for (int i = 1; i<= n; i++) {
        printf(" ");
    }
}
void printPatternNTo1(int n) {
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
    }
}
void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        printPattern1ToN(i);
        printSpaces(2 * (n - i));
        printPatternNTo1(i);
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPattern(n);
    return 0;
}