#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 100

struct File {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
};

struct Directory {
    struct File files[MAX_FILES];
    int fileCount;
};

void createFile(struct Directory* directory, const char* filename, const char* content) {
    if (directory->fileCount < MAX_FILES) {
        struct File newFile;
        strcpy(newFile.name, filename);
        strcpy(newFile.content, content);

        directory->files[directory->fileCount++] = newFile;
        printf("File '%s' created successfully.\n", filename);
    } else {
        printf("Cannot create file. Maximum file limit reached.\n");
    }
}

void readFile(struct Directory* directory, const char* filename) {
    for (int i = 0; i < directory->fileCount; ++i) {
        if (strcmp(directory->files[i].name, filename) == 0) {
            printf("File '%s' content: %s\n", filename, directory->files[i].content);
            return;
        }
    }
    printf("File '%s' not found.\n", filename);
}

void deleteFile(struct Directory* directory, const char* filename) {
    for (int i = 0; i < directory->fileCount; ++i) {
        if (strcmp(directory->files[i].name, filename) == 0) {
            // Remove the file by shifting the remaining files
            for (int j = i; j < directory->fileCount - 1; ++j) {
                directory->files[j] = directory->files[j + 1];
            }
            directory->fileCount--;
            printf("File '%s' deleted successfully.\n", filename);
            return;
        }
    }
    printf("File '%s' not found.\n", filename);
}

int main() {
    struct Directory rootDirectory;
    rootDirectory.fileCount = 0;

    createFile(&rootDirectory, "file1.txt", "This is file 1 content.");
    createFile(&rootDirectory, "file2.txt", "This is file 2 content.");
    createFile(&rootDirectory, "file3.txt", "This is file 3 content.");

    readFile(&rootDirectory, "file2.txt");

    deleteFile(&rootDirectory, "file2.txt");

    readFile(&rootDirectory, "file2.txt");

    return 0;
}
