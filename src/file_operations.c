#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "file_operations.h"

void creat_f(const char *path) {
    int fd = creat(path, 0644);
    if (fd < 0) {
        perror("Error creating file");
    } else {
        printf("File created successfully: %s\n", path);
        close(fd);
    }
}

void unlink_f(const char *path) {
    if (unlink(path) < 0) {
        perror("Error deleting file");
    } else {
        printf("File deleted successfully: %s\n", path);
    }
}

void open_f(const char *path) {
    // Construct the command to open the file with nano
    char command[256];
    snprintf(command, sizeof(command), "nano %s", path);

    // Execute the command
    int status = system(command);
    if (status == -1) {
        perror("Error opening file with nano");
    } else {
        printf("File opened with nano: %s\n", path);
    }
}

void read_f(const char *path) {
    char buffer[1024];
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for reading");
        return;
    }

    ssize_t bytes;
    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes);
    }

    close(fd);
}

void rename_f(const char *source, const char *destination) {
    if (rename(source, destination) < 0) {
        perror("Error renaming file/folder");
    } else {
        printf("Renamed successfully from %s to %s\n", source, destination);
    }
}

void write_f(const char *path, const char *data) {
    int fd = open(path, O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Error opening file for writing");
        return;
    }

    if (write(fd, data, strlen(data)) < 0) {
        perror("Error writing to file");
    } else {
        printf("Data written to file successfully: %s\n", path);
    }

    close(fd);
}