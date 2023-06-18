#include <stdio.h>

void printExponent(double num) {
    unsigned long long* ptr = (unsigned long long*)&num;
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;

    printf("Exponent in Hexadecimal: 0x%llX\n", exponent);
    printf("Exponent in Binary: 0b");
    
    for (int i = 11; i >= 0; i--) {
        int bit = (exponent >> i) & 1;
        printf("%d", bit);
    }

    printf("\n");
}

int main() {
    double x = 0.7;
    
    printf("Value: %.2f\n", x);
    printExponent(x);

    return 0;
}
