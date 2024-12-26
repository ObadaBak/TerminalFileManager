#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "permissions.h"

void change_permissions(const char *path, const char *mode_str) {
    mode_t mode = strtol(mode_str, NULL, 8);
    if (chmod(path, mode) < 0) {
        perror("Error changing permissions");
    } else {
        printf("Permissions for %s updated successfully to %s\n", path, mode_str);
    }
}

