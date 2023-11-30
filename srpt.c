	
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int startTime;
    int endTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to swap two processes
void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform SRPT scheduling
void srptScheduling(struct Process processes[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int shortest = -1;
        int shortestTime = INT_MAX;

        // Find the process with the shortest remaining time
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortestTime && processes[i].remainingTime > 0) {
                shortest = i;
                shortestTime = processes[i].remainingTime;
            }
        }

        // If no process is available, move to the next time
        if (shortest == -1) {
            currentTime++;
            continue;
        }

        // Execute the process for one time unit
        processes[shortest].remainingTime--;
        currentTime++;

        // Update start time if the process is just started
        if (processes[shortest].startTime == -1) {
            processes[shortest].startTime = currentTime - 1;
        }

        // Check if the process is completed
        if (processes[shortest].remainingTime == 0) {
            processes[shortest].endTime = currentTime;
            processes[shortest].turnaroundTime = processes[shortest].endTime - processes[shortest].arrivalTime;
            processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
            completedProcesses++;
        }
    }
}

// Function to calculate and print the average waiting time and turnaround time
void calculateAndPrintAverageTimes(struct Process processes[], int n) {
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    float averageWaitingTime = totalWaitingTime / n;
    float averageTurnaroundTime = totalTurnaroundTime / n;

    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main() {
    int n = 4; // Number of processes

    struct Process processes[] = {
        {1, 0, 5, 5, -1, -1, 0, 0},
        {2, 1, 3, 3, -1, -1, 0, 0},
        {3, 2, 3, 3, -1, -1, 0, 0},
        {4, 4, 1, 1, -1, -1, 0, 0}
    };

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    srptScheduling(processes, n);
    calculateAndPrintAverageTimes(processes, n);

    return 0;
}
