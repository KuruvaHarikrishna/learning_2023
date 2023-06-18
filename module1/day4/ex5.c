#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    int evenSum = 0;
    int oddSum = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }

    int diff = evenSum - oddSum;

    printf("Sum of even-indexed elements: %d\n", evenSum);
    printf("Sum of odd-indexed elements: %d\n", oddSum);
    printf("Difference: %d\n", diff);

    return 0;
}
