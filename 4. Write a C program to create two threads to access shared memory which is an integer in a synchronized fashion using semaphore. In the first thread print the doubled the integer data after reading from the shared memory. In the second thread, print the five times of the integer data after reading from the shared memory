#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int sharedData = 5;  // Initial shared data
sem_t mutex;

void *thread1(void *arg) {
    while (1) {
        sem_wait(&mutex);

        // Read shared data and print the doubled value
        int doubledValue = sharedData * 2;
        printf("Thread 1: Doubled Value: %d\n", doubledValue);

        sem_post(&mutex);

        // Sleep for a short time to simulate other operations
        usleep(500000);
    }

    pthread_exit(NULL);
}

void *thread2(void *arg) {
    while (1) {
        sem_wait(&mutex);

        // Read shared data and print five times the value
        int fiveTimesValue = sharedData * 5;
        printf("Thread 2: Five Times Value: %d\n", fiveTimesValue);

        sem_post(&mutex);

        // Sleep for a short time to simulate other operations
        usleep(500000);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    // Initialize semaphore
    sem_init(&mutex, 0, 1);

    // Create threads
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    // Join threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy semaphore
    sem_destroy(&mutex);

    return 0;
}
