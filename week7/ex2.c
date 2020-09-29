#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;
    printf("Enter the size of array ");
    scanf("%d", &N);

    int *array = malloc(sizeof(int)*N); //allocate memory for an array

    //fill the array
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }

    //print the array
    for (int j = 0; j < N; ++j) {
        printf("array[%d] = %d\n", j, array[j]);
    }

    free(array); //deallocate the memory

    return 0;
}
