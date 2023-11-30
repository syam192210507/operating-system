#include <stdio.h>

// Function to calculate the Need matrix
void calculateNeedMatrix(int processes, int resources, int allocation[processes][resources], int max[processes][resources], int need[processes][resources]) {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            // Need matrix calculation: Need[i][j] = Max[i][j] - Allocation[i][j]
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int processes, int resources, int matrix[processes][resources], char* name) {
    printf("\n%s Matrix:\n", name);
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int processes = 5; // Number of processes
    int resources = 3; // Number of resource types

    // Allocation matrix
    int allocation[5][3] = {{1, 1, 2}, {2, 1, 2}, {3, 0, 1}, {0, 2, 0}, {1, 1, 2}};

    // Max matrix
    int max[5][3] = {{5, 4, 4}, {4, 3, 3}, {9, 1, 3}, {8, 6, 4}, {2, 2, 3}};

    // Available matrix
    int available[1][3] = {3, 2, 1};

    // Need matrix
    int need[5][3];

    // Calculate the Need matrix
    calculateNeedMatrix(processes, resources, allocation, max, need);

    // Display matrices
    displayMatrix(processes, resources, allocation, "Allocation");
    displayMatrix(processes, resources, max, "Max");
    displayMatrix(1, resources, available, "Available");
    displayMatrix(processes, resources, need, "Need");

    return 0;
}
