#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

// Function to find the turnaround time for all processes
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time by adding burst time and waiting time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average waiting and turnaround times
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];

    // Find waiting time
    findWaitingTime(processes, n, bt, wt);

    // Find turnaround time
    findTurnaroundTime(processes, n, bt, wt, tat);

    // Calculate average waiting time
    float avg_wt = 0;
    for (int i = 0; i < n; i++)
        avg_wt += wt[i];
    avg_wt /= n;

    // Calculate average turnaround time
    float avg_tat = 0;
    for (int i = 0; i < n; i++)
        avg_tat += tat[i];
    avg_tat /= n;

    // Print results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    // Number of processes
    int n = 4;

    // Process IDs
    int processes[] = {1, 2, 3, 4};

    // Burst times
    int burst_time[] = {6, 8, 7, 3};

    // Calculate average waiting and turnaround times
    findAverageTime(processes, n, burst_time);

    return 0;
}

