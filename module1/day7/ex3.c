#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_FIELD_LENGTH 20
#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[MAX_FIELD_LENGTH];
    float temperature;
    int humidity;
    int light;
    char time[MAX_FIELD_LENGTH];
} LogEntry;

void printLogEntry(LogEntry entry) {
    printf("EntryNo: %d\n", entry.entryNo);
    printf("SensorNo: %s\n", entry.sensorNo);
    printf("Temperature: %.1f\n", entry.temperature);
    printf("Humidity: %d\n", entry.humidity);
    printf("Light: %d\n", entry.light);
    printf("Time: %s\n", entry.time);
    printf("------------------------------------\n");
}

int readLogFile(LogEntry logEntries[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int count = 0;

    // Open the file
    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 0;
    }

    // Read and store each log entry
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Parse the line into individual fields using comma as the delimiter
        token = strtok(line, ",");
        if (token != NULL) {
            logEntries[count].entryNo = atoi(token);

            token = strtok(NULL, ",");
            if (token != NULL) {
                strncpy(logEntries[count].sensorNo, token, MAX_FIELD_LENGTH);

                token = strtok(NULL, ",");
                if (token != NULL) {
                    logEntries[count].temperature = atof(token);

                    token = strtok(NULL, ",");
                    if (token != NULL) {
                        logEntries[count].humidity = atoi(token);

                        token = strtok(NULL, ",");
                        if (token != NULL) {
                            logEntries[count].light = atoi(token);

                            token = strtok(NULL, ",");
                            if (token != NULL) {
                                strncpy(logEntries[count].time, token, MAX_FIELD_LENGTH);
                                count++;
                            }
                        }
                    }
                }
            }
        }

        if (count == MAX_ENTRIES) {
            printf("Maximum number of entries reached.\n");
            break;
        }
    }

    // Close the file
    fclose(file);

    return count;
}

void displayLogEntries(LogEntry logEntries[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        printLogEntry(logEntries[i]);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int count;

    count = readLogFile(logEntries);

    // Display the stored log entries
    displayLogEntries(logEntries, count);

    return 0;
}

