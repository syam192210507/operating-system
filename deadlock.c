#include <stdio.h>

#define MAX_PROCESSES 3
#define MAX_RESOURCES 3

void calculateNeedMatrix(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES]) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int isDeadlocked(int processes[MAX_PROCESSES], int available[MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES]) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeedMatrix(need, max, allocation);

    int finish[MAX_PROCESSES] = {0}; // Array to track if a process has finished
    int work[MAX_RESOURCES];
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }

    int deadlockDetected = 1; // Assume deadlock is detected by default

    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (!finish[i]) {
            int j;
            for (j = 0; j < MAX_RESOURCES; j++) {
                if (need[i][j] > work[j]) {
                    break;
                }
            }

            if (j == MAX_RESOURCES) {
                // Process i can complete, release its resources
                for (int k = 0; k < MAX_RESOURCES; k++) {
                    work[k] += allocation[i][k];
                }
                finish[i] = 1;
                deadlockDetected = 0; // No deadlock is detected if a process can complete
            }
        }
    }

    return deadlockDetected;
}

int main() {
    int processes[MAX_PROCESSES] = {0, 1, 2};
    int available[MAX_RESOURCES] = {1, 2, 0};

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {3, 6, 8},
        {4, 3, 3},
        {3, 4, 4},
    };

    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {3, 3, 3},
        {2, 0, 3},
        {1, 2, 4},
    };

    if (isDeadlocked(processes, available, max, allocation)) {
        printf("The system is in a deadlock state.\n");

        // Identify deadlocked processes
        printf("Deadlocked processes: ");
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!allocation[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("The system is not in a deadlock state.\n");
    }

    return 0;
}


