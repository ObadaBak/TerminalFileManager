#include "logger.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

void log_operation(const char *operation, const char *status) {
    FILE *log_file = fopen("operations.log", "a");
    if (!log_file) {
        perror("Error opening log file");
        return;
    }

    time_t now = time(NULL);
    fprintf(log_file, "[%s] Operation: %s | Status: %s\n", ctime(&now), operation, status);
    fclose(log_file);
}

void view_log(void) {
    FILE *log_file = fopen("operations.log", "r");
    if (!log_file) {
        perror("Error opening log file");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), log_file) != NULL) {
        printf("%s", buffer);
    }

    fclose(log_file);
}

