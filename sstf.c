#include <stdio.h>
#include <stdlib.h>

// Function to calculate the absolute difference between two numbers
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to find the index of the track with the shortest seek time
int findShortestSeekTime(int *requestQueue, int size, int currentHead) {
    int minDistance = INT_MAX;
    int index = -1;

    for (int i = 0; i < size; i++) {
        int distance = absDiff(currentHead, requestQueue[i]);
        if (distance < minDistance) {
            minDistance = distance;
            index = i;
        }
    }

    return index;
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

    int currentHead = 50; // Assuming an initial head position

    printf("Sequence of head movement: ");
    for (int i = 0; i < numTracks; i++) {
        int nextIndex = findShortestSeekTime(tracks, numTracks, currentHead);
        printf("%d ", tracks[nextIndex]);

        // Move the head to the next track
        currentHead = tracks[nextIndex];

        // Remove the processed track from the request queue
        for (int j = nextIndex; j < numTracks - 1; j++) {
            tracks[j] = tracks[j + 1];
        }

        numTracks--;
    }

    // Calculate total head movement
    int totalHeadMovement = calculateTotalHeadMovement(tracks, numTracks);

    // Print the total head movement
    printf("\nTotal Head Movement: %d\n", totalHeadMovement);

    // Calculate and print the average head movement
    float averageHeadMovement = (float)totalHeadMovement / numTracks;
    printf("Average Head Movement: %.2f\n", averageHeadMovement);

    return 0;
}
