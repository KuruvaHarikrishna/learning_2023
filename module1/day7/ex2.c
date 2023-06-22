#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

// Function to change the file content to uppercase
void convertToUpper(char *buffer) {
    while (*buffer) {
        *buffer = toupper(*buffer);
        buffer++;
    }
}

// Function to change the file content to lowercase
void convertToLower(char *buffer) {
    while (*buffer) {
        *buffer = tolower(*buffer);
        buffer++;
    }
}

// Function to change the file content to sentence case
void convertToSentenceCase(char *buffer) {
    int isFirstChar = 1;
    while (*buffer) {
        if (isFirstChar) {
            *buffer = toupper(*buffer);
            isFirstChar = 0;
        } else {
            *buffer = tolower(*buffer);
        }

        if (*buffer == '.' || *buffer == '?' || *buffer == '!') {
            isFirstChar = 1;
        }

        buffer++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        printf("Options:\n");
        printf("  -u : Convert file content to uppercase\n");
        printf("  -l : Convert file content to lowercase\n");
        printf("  -s : Convert file content to sentence case\n");
        return 1;
    }

    char *option = argv[1];
    char *sourcePath = argv[2];
    char *destinationPath = argv[3];

    FILE *source, *destination;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open source file in read mode
    source = fopen(sourcePath, "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open destination file in write mode
    destination = fopen(destinationPath, "w");
    if (destination == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(source);
        return 1;
    }

    // Copy content from source file to destination file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        if (strcmp(option, "-u") == 0) {
            convertToUpper(buffer);
        } else if (strcmp(option, "-l") == 0) {
            convertToLower(buffer);
        } else if (strcmp(option, "-s") == 0) {
            convertToSentenceCase(buffer);
        }
        fwrite(buffer, 1, bytesRead, destination);
    }

    printf("File copied successfully.\n");

    // Close files
    fclose(source);
    fclose(destination);

    return 0;
}
