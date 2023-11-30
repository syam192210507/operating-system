#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_numbers(int start, int step, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", start + i * step);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            switch (i) {
                case 0:
                    printf("Odd Numbers (PID %d): ", getpid());
                    print_numbers(1, 2, 10);
                    break;
                case 1:
                    printf("Even Numbers (PID %d): ", getpid());
                    print_numbers(2, 2, 10);
                    break;
                case 2:
                    printf("Multiples of 3 (PID %d): ", getpid());
                    print_numbers(3, 3, 10);
                    break;
                case 3:
                    printf("Multiples of 5 (PID %d): ", getpid());
                    print_numbers(5, 5, 10);
                    break;
                default:
                    break;
            }
            // Child process should exit after printing
            _exit(0);
        } else if (pid < 0) {
            // Error occurred
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else {
            // Parent process
            wait(NULL); // Wait for the child to finish
        }
    }

    return 0;
}
