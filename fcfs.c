#include<stdio.h>

// Structure to represent a process
struct Process {
    int processID;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to calculate average waiting time and average turnaround time
void calculateAvgTimes(struct Process processes[], int n) {
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    // Calculate waiting time for each process
    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    // Calculate averages
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    // Display results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    // Number of processes
    int n = 3;

    // Create an array of processes with given burst times and arrival times
    struct Process processes[] = {
        {0, 2, 0},
        {1, 4, 0},
        {2, 8, 0}
    };

    // Call the function to calculate average times
    calculateAvgTimes(processes, n);

    return 0;
}
