#include <stdio.h>
#include <stdlib.h>

#define BUFFER 1024

int main() {

    char command[BUFFER];

    printf("-> ");
    while(scanf("%s", command) != 0) {
        system(command);
        printf("-> ");
    }
    return 0;
}

