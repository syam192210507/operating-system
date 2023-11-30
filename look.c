#include <stdio.h>
#include <stdlib.h>

void look(int tracks[], int n, int start) {
    int head = start;
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

    // LOOK algorithm - Move towards higher track numbers
    for (int i = head_index; i < n; i++) {
        total_head_movement += abs(head - tracks[i]);
        head = tracks[i];
    }

    // Move towards lower track numbers
    for (int i = head_index - 1; i >= 0; i--) {
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
    look(tracks, n, start);

    return 0;
}
