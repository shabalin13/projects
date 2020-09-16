#include <stdio.h>
#include <pthread.h>

void *functForThread(void *id) {
    printf("It is thread #%ld\n", (long)id);
    pthread_exit(NULL);
}

int main() {

    int numOfThreads;
    scanf("%d", &numOfThreads);
    pthread_t threads[numOfThreads];

    for (int i = 0; i < numOfThreads; ++i) {
        pthread_create(&(threads[i]), NULL, functForThread, (void *)i);
        pthread_join(threads[i], NULL);
    }

    return 0;
}