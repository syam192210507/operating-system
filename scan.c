#include <stdio.h>
#include <stdlib.h>

// Function to simulate SCAN disk scheduling algorithm
void scanDiskScheduling(int tracks[], int n, int initialHeadPosition, int direction) {
    // Create an array to mark whether a track has been visited or not
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Head starts at the initial head position
    int headPosition = initialHeadPosition;

    // Initialize the head movement
    int headMovement = 0;

    // Determine the direction of movement (1 for right, -1 for left)
    int moveDirection = direction;

    // Traverse the tracks in the specified direction
    while (1) {
        // Print the current head position
        printf("Move to %d\n", headPosition);

        // Find the next track in the current direction
        int nextIndex = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if ((moveDirection == 1 && tracks[i] >= headPosition) || (moveDirection == -1 && tracks[i] <= headPosition)) {
                    if (nextIndex == -1 || abs(tracks[i] - headPosition) < abs(tracks[nextIndex] - headPosition)) {
                        nextIndex = i;
                    }
                }
            }
        }

        // Break if no next track is found in the current direction
        if (nextIndex == -1) {
            break;
        }

        // Mark the next track as visited
        visited[nextIndex] = 1;

        // Update the head position
        headPosition = tracks[nextIndex];

        // Accumulate the head movement
        headMovement += abs(tracks[nextIndex] - headPosition);
    }

    // Display the total head movement
    printf("\nTotal Head Movement: %d\n", headMovement);

    // Calculate and display the average head movement
    float averageHeadMovement = (float)headMovement / n;
    printf("Average Head Movement: %.2f\n", averageHeadMovement);
}

int main() {
    // Test case
    int tracks[] = {55, 58, 60, 70, 18};
    int numberOfTracks = sizeof(tracks) / sizeof(tracks[0]);

    int initialHeadPosition = 50; // Initial head position
    int direction = 1; // 1 for right, -1 for left

    printf("Track Positions: ");
    for (int i = 0; i < numberOfTracks; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    // Execute SCAN disk scheduling algorithm
    scanDiskScheduling(tracks, numberOfTracks, initialHeadPosition, direction);

    return 0;
}
