#include <stdio.h>

// Function to allocate memory using Worst-Fit algorithm
void worstFit(int memory[], int m, int processes[], int n) {
    int allocation[n]; // To store the allocation status of each process

    // Initialize all allocations as -1 (indicating unallocated)
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    // Traverse each process and allocate memory using the Worst-Fit algorithm
    for (int i = 0; i < n; i++) {
        int worstFitIndex = -1;
        for (int j = 0; j < m; j++) {
            if (memory[j] >= processes[i]) {
                if (worstFitIndex == -1 || memory[j] > memory[worstFitIndex]) {
                    // Update the worst-fit index
                    worstFitIndex = j;
                }
            }
        }

        if (worstFitIndex != -1) {
            // Allocate memory to the process
            allocation[i] = worstFitIndex;

            // Update the memory size after allocation
            memory[worstFitIndex] -= processes[i];
        }
    }

    // Display the allocation result
    printf("\nProcess\tMemory Block\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);
        if (allocation[i] != -1) {
            printf("%d KB\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int memory[] = {300, 600, 350, 200, 750, 125};
    int processes[] = {115, 500, 358, 200, 375};
    int m = sizeof(memory) / sizeof(memory[0]);
    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Memory partitions: ");
    for (int i = 0; i < m; i++) {
        printf("%d KB ", memory[i]);
    }
    printf("\n");

    printf("Process sizes: ");
    for (int i = 0; i < n; i++) {
        printf("%d KB ", processes[i]);
    }
    printf("\n");

    // Call the Worst-Fit algorithm
    worstFit(memory, m, processes, n);

    return 0;
}
