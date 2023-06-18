#include <stdio.h>
#include <ctype.h>

void toggleCase(char* str) {
    while (*str != '\0') {
        if (islower(*str)) {
            *str = toupper(*str);
        } else if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}

int main() {
    char str[] = "Hello, World!";
    
    printf("Original string: %s\n", str);

    toggleCase(str);

    printf("Toggled case string: %s\n", str);

    return 0;
}
