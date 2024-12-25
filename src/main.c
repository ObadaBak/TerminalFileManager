#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Include function headers from your modules
#include "directory_ops.h"
#include "file_operations.h"
#include "permissions.h"
#include "logger.h"

void display_help() {
    printf("Available Commands:\n");
    printf("  opendir_f <directory>         - Open a folder\n");
    printf("  readdir_f <directory>         - Read directory contents\n");
    printf("  stat_f <path>                 - Get file or folder information\n");
    printf("  creat_f <file>                - Create a new file\n");
    printf("  unlink_f <file>               - Delete a file\n");
    printf("  rmdir_f <directory>           - Delete a folder\n");
    printf("  chmod <path> <mode>           - Change file/folder permissions\n");
    printf("  open_f <file>                 - Open a file\n");
    printf("  read_f <file>                 - Read a file\n");
    printf("  write_f <file> <data>         - Write to a file\n");
    printf("  rename_f <source> <dest>      - Rename or move a file/folder\n");
    printf("  log                           - View the operation log\n");
    printf("  help                          - Display this help menu\n");
    printf("  exit                          - Exit the program\n");
}

int main() {
    char command[256];

    printf("Welcome to the File Management System.\n");
    printf("Type 'help' for a list of commands.\n");

    while (1) {
        printf("\n> ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character from input
        command[strcspn(command, "\n")] = '\0';

        if (strncmp(command, "opendir_f", 9) == 0) {
            char *path = command + 10;
            log_operation("Open Directory", "Started");
            opendir_f(path);
            log_operation("Open Directory", "Completed");

        } else if (strncmp(command, "readdir_f", 9) == 0) {
            char *path = command + 10;
            log_operation("Read Directory", "Started");
            readdir_f(path);
            log_operation("Read Directory", "Completed");

        } else if (strncmp(command, "stat_f", 6) == 0) {
            char *path = command + 7;
            log_operation("Get File/Folder Info", "Started");
            stat_f(path);
            log_operation("Get File/Folder Info", "Completed");

        } else if (strncmp(command, "creat_f", 7) == 0) {
            char *path = command + 8;
            log_operation("Create File", "Started");
            creat_f(path);
            log_operation("Create File", "Completed");

        } else if (strncmp(command, "unlink_f", 8) == 0) {
            char *path = command + 9;
            log_operation("Delete File", "Started");
            unlink_f(path);
            log_operation("Delete File", "Completed");

        } else if (strncmp(command, "rmdir_f", 7) == 0) {
            char *path = command + 8;
            log_operation("Delete Folder", "Started");
            rmdir_f(path);
            log_operation("Delete Folder", "Completed");

        } else if (strncmp(command, "chmod", 5) == 0) {
            char *args = command + 6;
            char *path = strtok(args, " ");
            char *mode_str = strtok(NULL, " ");
            if (path && mode_str) {
                log_operation("Change Permissions", "Started");
                change_permissions(path, mode_str);
                log_operation("Change Permissions", "Completed");
            } else {
                printf("Invalid arguments. Usage: chmod <path> <mode>\n");
            }

        } else if (strncmp(command, "open_f", 6) == 0) {
            char *path = command + 7;
            log_operation("Open File", "Started");
            open_f(path);
            log_operation("Open File", "Completed");

        } else if (strncmp(command, "read_f", 6) == 0) {
            char *path = command + 7;
            log_operation("Read File", "Started");
            read_f(path);
            log_operation("Read File", "Completed");

        } else if (strncmp(command, "write_f", 7) == 0) {
            char *args = command + 8;
            char *path = strtok(args, " ");
            char *data = strtok(NULL, "");
            if (path && data) {
                log_operation("Write to File", "Started");
                write_f(path, data);
                log_operation("Write to File", "Completed");
            } else {
                printf("Invalid arguments. Usage: write_f <path> <data>\n");
            }

        } else if (strncmp(command, "rename_f", 8) == 0) {
            char *args = command + 9;
            char *source = strtok(args, " ");
            char *destination = strtok(NULL, " ");
            if (source && destination) {
                log_operation("Rename/Move File/Folder", "Started");
                rename_f(source, destination);
                log_operation("Rename/Move File/Folder", "Completed");
            } else {
                printf("Invalid arguments. Usage: rename_f <source> <dest>\n");
            }

        } else if (strcmp(command, "log") == 0) {
            log_operation("View Log", "Started");
            view_log();
            log_operation("View Log", "Completed");

        } else if (strcmp(command, "help") == 0) {
            display_help();

        } else if (strcmp(command, "exit") == 0) {
            log_operation("Exit Program", "Completed");
            printf("Goodbye!\n");
            break;

        } else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}
