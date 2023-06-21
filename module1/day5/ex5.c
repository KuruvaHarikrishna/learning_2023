#include <stdio.h>

typedef struct {
    int field1;
    float field2;
    char field3;
} Structure;

void swap_fields(Structure* struct1, Structure* struct2) {
    Structure temp = *struct1;
    *struct1 = *struct2;
    *struct2 = temp;
}

int main() {
    Structure struct1, struct2;

    // Initialize structure 1
    struct1.field1 = 10;
    struct1.field2 = 3.14;
    struct1.field3 = 'A';

    // Initialize structure 2
    struct2.field1 = 20;
    struct2.field2 = 2.71;
    struct2.field3 = 'B';

    printf("Before swapping:\n");
    printf("Structure 1: field1=%d, field2=%.2f, field3=%c\n", struct1.field1, struct1.field2, struct1.field3);
    printf("Structure 2: field1=%d, field2=%.2f, field3=%c\n", struct2.field1, struct2.field2, struct2.field3);

    swap_fields(&struct1, &struct2);

    printf("\nAfter swapping:\n");
    printf("Structure 1: field1=%d, field2=%.2f, field3=%c\n", struct1.field1, struct1.field2, struct1.field3);
    printf("Structure 2: field1=%d, field2=%.2f, field3=%c\n", struct2.field1, struct2.field2, struct2.field3);

    return 0;
}
