#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 3
#define MAX_PRODUCE 4

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full, mutex;

void *producer(void *arg) {
    int produced = 0;

    while (produced < MAX_PRODUCE) {
        // Wait for an empty slot in the buffer
        sem_wait(&empty);
        // Wait for exclusive access to the buffer
        sem_wait(&mutex);

        // Produce data and add it to the buffer
        buffer[in] = produced;
        printf("Produced item %d\n", produced);

        // Update buffer index and counter
        in = (in + 1) % BUFFER_SIZE;
        produced++;

        // Release exclusive access and signal that the buffer is not empty
        sem_post(&mutex);
        sem_post(&full);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    while (1) {
        // Wait for a filled slot in the buffer
        sem_wait(&full);
        // Wait for exclusive access to the buffer
        sem_wait(&mutex);

        // Consume data from the buffer
        printf("Consumed item %d\n", buffer[out]);

        // Update buffer index
        out = (out + 1) % BUFFER_SIZE;

        // Release exclusive access and signal that the buffer is not full
        sem_post(&mutex);
        sem_post(&empty);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread, consumerThread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create producer and consumer threads
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Sleep to demonstrate the specified test case
    sleep(1);

    // Print buffer status
    printf("Buffer status: %s\n", (in == out) ? "EMPTY" : "NOT EMPTY");

    // Produce additional items to fill the buffer
    for (int i = 0; i < MAX_PRODUCE; ++i) {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = i;
        printf("Produced item %d\n", i);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);
    }

    // Join threads
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
