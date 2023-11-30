#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

pthread_mutex_t mutex;
pthread_cond_t condition[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

void printState(int philosopher, int action) {
    const char *actions[] = {"THINKING", "HUNGRY", "EATING"};
    printf("Philosopher %d is %s\n", philosopher, actions[action]);
}

void test(int philosopher) {
    if (state[philosopher] == HUNGRY &&
        state[(philosopher + 4) % NUM_PHILOSOPHERS] != EATING &&
        state[(philosopher + 1) % NUM_PHILOSOPHERS] != EATING) {
        // The philosopher can start eating
        state[philosopher] = EATING;
        printState(philosopher, EATING);
        pthread_cond_signal(&condition[philosopher]);
    }
}

void pickupChopsticks(int philosopher) {
    pthread_mutex_lock(&mutex);
    state[philosopher] = HUNGRY;
    printState(philosopher, HUNGRY);
    test(philosopher);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&mutex);
    while (state[philosopher] != EATING) {
        pthread_cond_wait(&condition[philosopher], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void putdownChopsticks(int philosopher) {
    pthread_mutex_lock(&mutex);
    state[philosopher] = THINKING;
    printState(philosopher, THINKING);
    test((philosopher + 4) % NUM_PHILOSOPHERS);
    test((philosopher + 1) % NUM_PHILOSOPHERS);
    pthread_mutex_unlock(&mutex);
}

void *philosopher(void *arg) {
    int philosopher_id = *((int *)arg);

    while (1) {
        // Thinking
        usleep(rand() % 5);

        // Hungry
        pickupChopsticks(philosopher_id);

        // Eating
        usleep(rand() % 5);

        // Done eating, put down chopsticks
        putdownChopsticks(philosopher_id);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_cond_init(&condition[i], NULL);
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, (void *)&philosopher_ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(philosophers[i], NULL);
        pthread_cond_destroy(&condition[i]);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
