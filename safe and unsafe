#include <stdio.h>

#define MAX_PROCESSES 4
#define MAX_RESOURCES 3

void calculateNeedMatrix(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES]) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int isSafeState(int processes[MAX_PROCESSES], int available[MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES]) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeedMatrix(need, max, allocation);

    int finish[MAX_PROCESSES] = {0}; // Array to track if a process has finished

    int work[MAX_RESOURCES];
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }

    int safeSequence[MAX_PROCESSES];
    int count = 0;

    while (count < MAX_PROCESSES) {
        int found = 0;

        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == MAX_RESOURCES) {
                    for (int k = 0; k < MAX_RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            // If no process is found, the system is in an unsafe state
            return 0;
        }
    }

    // If all processes finish, the system is in a safe state
    printf("Safe Sequence: ");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");

    return 1;
}

int main() {
    int processes[MAX_PROCESSES] = {0, 1, 2, 3};
    int available[MAX_RESOURCES] = {9, 3, 6};

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {3, 2, 2},
        {6, 1, 3},
        {3, 1, 4},
        {4, 2, 2},
    };

    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {1, 0, 0},
        {6, 1, 2},
        {3, 1, 4},
        {0, 0, 2},
    };

    if (isSafeState(processes, available, max, allocation)) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is in an unsafe state.\n");
    }

    return 0;
}
