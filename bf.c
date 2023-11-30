#include <stdio.h>
#include <limits.h>

#define NUM_PARTITIONS 6
#define NUM_PROCESSES 5

void bestFit(int partitions[], int m, int processes[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int bestFitIndex = -1;
        for (int j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                if (bestFitIndex == -1 || partitions[j] < partitions[bestFitIndex]) {
                    bestFitIndex = j;
                }
            }
        }

        if (bestFitIndex != -1) {
            allocation[i] = bestFitIndex;
            partitions[bestFitIndex] -= processes[i];
        }
    }

    printf("\nProcess\t\tMemory Partition\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t", processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[NUM_PROCESSES] = {115, 500, 358, 200, 375};

    printf("Memory Partitions: ");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("%d KB ", partitions[i]);
    }

    printf("\nProcesses: ");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("%d KB ", processes[i]);
    }

    bestFit(partitions, NUM_PARTITIONS, processes, NUM_PROCESSES);

    return 0;
}
