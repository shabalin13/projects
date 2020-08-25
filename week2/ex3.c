#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void createTriangle(int n) {
    int level = 1;
    for (int i = 1; i <= n; ++i) {
        int numberOfSpaces = (2*n - 1 - level)/2;
        for (int j = 0; j < numberOfSpaces; ++j) {
            printf(" ");
        }
        for (int j = 0; j < level; ++j) {
            printf("*");
        }
        /*for (int j = 0; j < numberOfSpaces; ++j) {
            printf(" ");
        }*/
        level += 2;
        printf("\n");

    }
}

int main(int argc, char *argv[]) {
    int n;
    sscanf(argv[1], "%d", &n);
    createTriangle(n);
    return 0;
}