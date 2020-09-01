#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int length) {

    bool swapped;

    do {
        swapped = false;
        for (int i = 1; i < length; ++i) {
            if (array[i-1] > array[i]) {
                swapped = true;
                swap(&array[i-1], &array[i]);
            }
        }
    }while (swapped);
}

int main() {

    int arr[11] = {1, 5, 2, 8, 4, 9, 3, 7, 6, 0, 5};

    int length = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < length; ++i) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    bubble_sort(arr, length);

    for (int i = 0; i < length; ++i) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
