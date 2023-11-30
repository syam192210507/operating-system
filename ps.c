#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int priority[]) {
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n];

    findWaitingTime(processes, n, bt, wt, priority);
    findTurnaroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {30, 5, 12};
    int priority[] = {2, 1, 3};

    findAverageTime(processes, n, burst_time, priority);

    return 0;
}
