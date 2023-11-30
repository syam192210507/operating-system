#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = bt[i];
        wt[i] = 0;
    }

    int t = 0; // Current time

    // Keep traversing the processes while all processes are not done
    while (1) {
        int done = 1; // Flag to check if all processes are done

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {

                done = 0; // There is a pending process

                if (remaining_time[i] > quantum) {
                    // Process exceeds the time quantum
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    // Process finishes within the time quantum
                    t += remaining_time[i];
                    wt[i] = t - bt[i];
                    remaining_time[i] = 0;
                }
            }
        }

        // All processes are done
        if (done == 1)
            break;
    }
}

// Function to calculate turnaround time
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void findAverageTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];

    // Function to find waiting time
    findWaitingTime(processes, n, bt, wt, quantum);

    // Function to find turnaround time
    findTurnaroundTime(processes, n, bt, wt, tat);

    // Calculate total waiting time and total turnaround time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate and display average waiting time and average turnaround time
    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;

    printf("Average Waiting Time: %.2f ms\n", avg_wt);
    printf("Average Turnaround Time: %.2f ms\n", avg_tat);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {24, 3, 3};
    int quantum_time = 4;

    findAverageTime(processes, n, burst_time, quantum_time);

    return 0;
}
