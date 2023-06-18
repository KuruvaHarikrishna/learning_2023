#include <stdio.h>
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
int main() {
    int a[3] = {0x1, 0xF4, 0x10001};
    int arraySize = sizeof(a) / sizeof(a[0]);
    int totalSetBits = 0;
    for (int i = 0; i < arraySize; i++) {
        totalSetBits += countSetBits(a[i]);
    }
    printf("The total number of set bits in the given array is: %d\n", totalSetBits);
    return 0;
}
