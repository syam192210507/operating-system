#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES_PER_USER 3
#define MAX_FILENAME_LENGTH 50

struct File {
    char name[MAX_FILENAME_LENGTH];
};

struct UserDirectory {
    char name[MAX_FILENAME_LENGTH];
    struct File files[MAX_FILES_PER_USER];
    int fileCount;
};

struct RootDirectory {
    struct UserDirectory users[MAX_USERS];
    int userCount;
};

void createUserDirectory(struct RootDirectory* rootDir, const char* username) {
    if (rootDir->userCount < MAX_USERS) {
        struct UserDirectory newUserDir;
        strcpy(newUserDir.name, username);
        newUserDir.fileCount = 0;

        rootDir->users[rootDir->userCount++] = newUserDir;
        printf("User directory '%s' created successfully.\n", username);
    } else {
        printf("Cannot create user directory. Maximum user limit reached.\n");
    }
}

void createFile(struct RootDirectory* rootDir, const char* username, const char* filename) {
    for (int i = 0; i < rootDir->userCount; ++i) {
        if (strcmp(rootDir->users[i].name, username) == 0) {
            struct UserDirectory* userDir = &rootDir->users[i];

            if (userDir->fileCount < MAX_FILES_PER_USER) {
                struct File newFile;
                strcpy(newFile.name, filename);

                userDir->files[userDir->fileCount++] = newFile;
                printf("File '%s' created in user directory '%s'.\n", filename, username);
            } else {
                printf("Cannot create file. Maximum file limit reached for user '%s'.\n", username);
            }

            return;
        }
    }

    printf("User directory '%s' not found.\n", username);
}

int main() {
    struct RootDirectory rootDirectory;
    rootDirectory.userCount = 0;

    // Create user directories
    createUserDirectory(&rootDirectory, "user1");
    createUserDirectory(&rootDirectory, "user2");
    createUserDirectory(&rootDirectory, "user3");

    // Create files for each user
    createFile(&rootDirectory, "user1", "file1.txt");
    createFile(&rootDirectory, "user1", "file2.txt");
    createFile(&rootDirectory, "user1", "file3.txt");

    createFile(&rootDirectory, "user2", "file4.txt");
    createFile(&rootDirectory, "user2", "file5.txt");

    createFile(&rootDirectory, "user3", "file6.txt");
    createFile(&rootDirectory, "user3", "file7.txt");

    return 0;
}
