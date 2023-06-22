#include <stdio.h>

#define BUFFER_SIZE 4096

int main() {
    FILE *source, *destination;
    char sourcePath[100], destinationPath[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Get source file path
    printf("Enter the path of the source file: ");
    scanf("%s", sourcePath);

    // Open source file in read mode
    source = fopen(sourcePath, "rb");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Get destination file path
    printf("Enter the path of the destination file: ");
    scanf("%s", destinationPath);

    // Open destination file in write mode
    destination = fopen(destinationPath, "wb");
    if (destination == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(source);
        return 1;
    }

    // Copy content from source file to destination file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    printf("File copied successfully.\n");

    // Close files
    fclose(source);
    fclose(destination);

    return 0;
}
