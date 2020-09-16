#include <stdio.h>
#include <pthread.h>
#include <zconf.h>
#include <stdlib.h>

const int MaxSize = 17;

pthread_cond_t full;
pthread_cond_t empty;
int count = 0;
int buffer[MaxSize];

void *procedureOfProducer(void *id) {
    while (1) {
        if (count == MaxSize) {
            printf("Producer needs to get some sleep while consumer is doing his job\n");
            sleep(1);
        }

        buffer[count++] = rand()%50;
        printf("Producer inserted item #%d\n", count);


        if (count == 1) {
            printf("Producer inserted the first item and must wake up consumer to remove items\n");
            pthread_cond_signal(&empty);
        }
    }
}

void *procedureOfConsumer(void *id) {
    while (1) {
        if (count == 0) {
            printf("Consumer needs to get some sleep while producer is doing his job\n");
            sleep(1);
        }

        count = count - 1;
        printf("Consumer removed item #%d\n", count);

        if (count == MaxSize - 1) {
            printf("Consumer removed item and must wake up producer to insert new items\n");
            pthread_cond_signal(&full);
        }
    }
}

int main() {
    pthread_t producer;
    pthread_t consumer;

    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);

    pthread_create(&consumer, NULL, procedureOfConsumer, (void *)&consumer);
    pthread_create(&producer, NULL, procedureOfProducer, (void *)&producer);

    pthread_join(consumer, NULL);
    pthread_join(producer, NULL);

    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    pthread_exit(NULL);

    return 0;
}
