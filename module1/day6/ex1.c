#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parse_string(const char* str, struct Student* students, int size) {
    char temp_name[20];
    float temp_marks;
    int temp_rollno;

    // Tokenize the string and parse the values
    sscanf(str, "%d %s %f", &temp_rollno, temp_name, &temp_marks);

    // Initialize the array of structures
    for (int i = 0; i < size; ++i) {
        students[i].rollno = temp_rollno;
        strcpy(students[i].name, temp_name);
        students[i].marks = temp_marks;
    }
}

int main() {
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();  // Consume the newline character

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char input_str[100];
    printf("Enter the input string: ");
    fgets(input_str, sizeof(input_str), stdin);
    input_str[strcspn(input_str, "\n")] = '\0';  // Remove trailing newline character

    parse_string(input_str, students, size);

    printf("\nStudent Details:\n");
    for (int i = 0; i < size; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
