#include<stdio.h>
#include<stdlib.h>

// Function to calculate the absolute difference between two numbers
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to calculate the total head movement
int calculateTotalHeadMovement(int *requestQueue, int size) {
    int totalMovement = 0;
    for (int i = 1; i < size; i++) {
        totalMovement += absDiff(requestQueue[i - 1], requestQueue[i]);
    }
    return totalMovement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = sizeof(tracks) / sizeof(tracks[0]);

    printf("Request Queue: ");
    for (int i = 0; i < numTracks; i++) {
        printf("%d ", tracks[i]);
    }

    printf("\n");

    // Calculate total head movement
    int totalHeadMovement = calculateTotalHeadMovement(tracks, numTracks);

    // Print the total head movement
    printf("Total Head Movement: %d\n", totalHeadMovement);

    // Calculate and print the average head movement
    float averageHeadMovement = (float)totalHeadMovement / numTracks;
    printf("Average Head Movement: %.2f\n", averageHeadMovement);

    return 0;
}
