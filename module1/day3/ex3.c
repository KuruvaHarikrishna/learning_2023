#include <stdio.h>
int deleteDigitAndGetMax(int num) {
    int maxNum = 0;
    int pow10 = 1;
    for (int i = 0; i < 4; i++) {
        int tempNum = (num / (pow10 * 10)) * pow10 + (num % pow10);
        if (tempNum > maxNum) {
            maxNum = tempNum;
        }
        pow10 *= 10;
    }
    return maxNum;
}
int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    int largestNum = deleteDigitAndGetMax(num);
    printf("The largest number by deleting a single digit is: %d\n", largestNum);
    return 0;
}