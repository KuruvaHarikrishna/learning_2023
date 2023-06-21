#include <stdio.h>

typedef struct {
    int rollNo;
    char name[50];
    int marks;
} Student;

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortDescending(Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].marks < arr[j + 1].marks) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    // Example usage
    Student students[5] = {
        {1, "John", 85},
        {2, "Alice", 92},
        {3, "Bob", 78},
        {4, "Emma", 90},
        {5, "David", 88}
    };

    int size = sizeof(students) / sizeof(students[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %d\n",
               students[i].rollNo, students[i].name, students[i].marks);
    }

    sortDescending(students, size);

    printf("\nAfter sorting in descending order:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %d\n",
               students[i].rollNo, students[i].name, students[i].marks);
    }

    return 0;
}
