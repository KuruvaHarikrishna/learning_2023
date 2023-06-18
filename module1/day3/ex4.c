#include <stdio.h>
#include <limits.h>
void findSmallestAndLargestDigits(int n, int numbers[]) {
    int smallestDigit = INT_MAX;
    int largestDigit = INT_MIN;
    for (int i = 0; i < n; i++) {
        int num = numbers[i];
        while (num != 0) {
            int digit = num % 10;
            if (digit < smallestDigit) {
                smallestDigit = digit;
            }
            if (digit > largestDigit) {
                largestDigit = digit;
            }
            num /= 10;
        }
    }
    if (smallestDigit == INT_MAX || largestDigit == INT_MIN) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallestDigit);
        printf("Largest digit: %d\n", largestDigit);
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int numbers[n];
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    findSmallestAndLargestDigits(n, numbers);
    return 0;
}