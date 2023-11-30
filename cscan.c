#include <stdio.h>
#include <stdlib.h>

void cscan(int tracks[], int n, int start) {
    int total_tracks = 100;  // Assuming total number of tracks on the disk is 100
    int head = start;
    int direction = 1;  // 1 for moving towards higher track numbers, -1 for moving towards lower track numbers
    int total_head_movement = 0;

    // Sort the tracks in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Find the index of the head position in the sorted array
    int head_index;
    for (head_index = 0; head_index < n; head_index++) {
        if (tracks[head_index] >= head) {
            break;
        }
    }

    // CSCAN algorithm
    for (int i = head_index; i < n; i++) {
        total_head_movement += abs(head - tracks[i]);
        head = tracks[i];
    }

    if (head_index > 0) {
        // Move the head to the end of the disk
        total_head_movement += abs(head - total_tracks);
        head = total_tracks;
    }

    for (int i = 0; i < head_index; i++) {
        total_head_movement += abs(head - tracks[i]);
        head = tracks[i];
    }

    // Print the total head movement
    printf("Total head movement: %d\n", total_head_movement);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int start = 50;  // Initial position of the head

    printf("Initial position of the head: %d\n", start);
    cscan(tracks, n, start);

    return 0;
}
