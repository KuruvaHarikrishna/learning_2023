#include <stdio.h>
void printExponent(double x) {
    unsigned char* p = (unsigned char*)&x;
    unsigned int exponent = (p[7] & 0x7F) << 4 | (p[6] & 0xF0) >> 4;
    printf("Exponent (hex): 0x%X\n", exponent);
    printf("Exponent (binary): 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}
int main() {
    double x = 0.7;
    printExponent(x);
    return 0;
}
