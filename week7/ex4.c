#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *newRealloc(void *ptr, size_t size) {
    if (ptr == NULL)
        return malloc(size);
    else if (size == 0) {
        free(ptr);
        return NULL;
    }else {
        void *new = malloc(size);
        memcpy(new, ptr, size);
        free(ptr);
        return new;
    }
}

int main() {

    int N, N1, N2, N3, N4;
    printf("Enter the size of array ");
    scanf("%d", &N);

    int *array = malloc(N * sizeof(int));

    //fill the array
    for (int i = 0; i < N; ++i) {
        array[i] = 100;
    }

    //print the array
    printf("Initial array:\n");
    for (int j = 0; j < N; ++j) {
        printf("array[%d] = %d\n", j, array[j]);
    }



    printf("Decrease the size of array ");
    scanf("%d", &N1);
    array = newRealloc(array, N1 * sizeof(int));

    //print the array
    printf("Decreased array:\n");
    for (int j = 0; j < N1; ++j) {
        printf("array[%d] = %d\n", j, array[j]);
    }



    printf("Increase the size of array ");
    scanf("%d", &N2);
    array = newRealloc(array, N2 * sizeof(int));

    //print the array
    printf("Increased array:\n");
    for (int j = 0; j < N2; ++j) {
        printf("array[%d] = %d\n", j, array[j]);
    }



    printf("Enter size of array 0 ");
    scanf("%d", &N3);
    array = newRealloc(array, N3 * sizeof(int));
    printf("Free array\n");



    printf("Enter new size of array ");
    scanf("%d", &N4);
    array = newRealloc(NULL, N4 * sizeof(int));

    //print the array
    printf("New array:\n");
    for (int j = 0; j < N4; ++j) {
        printf("array[%d] = %d\n", j, array[j]);
    }

    return 0;
}