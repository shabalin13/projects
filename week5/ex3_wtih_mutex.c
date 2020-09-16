#include <stdio.h>
#include <pthread.h>
#include <zconf.h>
#include <stdlib.h>

const int MaxSize = 17;

pthread_cond_t full;
pthread_cond_t empty;
pthread_mutex_t mutex;
int count = 0;

int buffer[MaxSize];

void *procedureOfProducer(void *id) {
    while (1) {

        pthread_mutex_lock(&mutex);

        if (count == MaxSize) {
            printf("Producer needs to get some sleep while consumer is doing his job\n");
            pthread_cond_wait(&full, &mutex);
        }

        buffer[count] = rand()%50;
        printf("Producer inserted item #%d - %d\n", count, buffer[count]);
        count = count + 1;
        sleep(1);

        if (count == 1) {
            printf("Producer inserted the first item and must wake up consumer to remove items\n");
            pthread_cond_signal(&empty);
        }
        pthread_mutex_unlock(&mutex);
    }
}

void *procedureOfConsumer(void *id) {
    while (1) {

        pthread_mutex_lock(&mutex);

        if (count == 0) {
            printf("Consumer needs to get some sleep while producer is doing his job\n");
            pthread_cond_wait(&empty, &mutex);
        }

        count = count - 1;
        printf("Consumer removed item #%d - %d\n", count, buffer[count]);

        if (count == MaxSize - 1) {
            printf("Consumer removed item and must wake up producer to insert new items\n");
            pthread_cond_signal(&full);
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t producer;
    pthread_t consumer;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);

    pthread_create(&consumer, NULL, procedureOfConsumer, (void *)&consumer);
    pthread_create(&producer, NULL, procedureOfProducer, (void *)&producer);

    pthread_join(consumer, NULL);
    pthread_join(producer, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    pthread_exit(NULL);

    return 0;
}
