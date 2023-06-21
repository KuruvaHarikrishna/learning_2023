#include <stdio.h>
#include <string.h>

typedef struct {
    int rollNo;
    char name[50];
    int marks;
} Student;

int searchByName(Student arr[], int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
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
    const char *searchName = "Bob";

    int index = searchByName(students, size, searchName);

    if (index != -1) {
        printf("Student found at index %d\n", index);
        printf("Roll No: %d, Name: %s, Marks: %d\n",
               students[index].rollNo, students[index].name, students[index].marks);
    } else {
        printf("Student not found\n");
    }

    return 0;
}
