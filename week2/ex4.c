#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    swap(&x, &y);
    printf("First integer is %d, second is %d", x, y);

    return 0;
}


