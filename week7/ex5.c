#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s;
    char foo[] = "Hello World";

    s = malloc(sizeof(char*)); //we must allocate memory for "s" not to get segmentation fault

    *s = foo;

    printf("*s is %s\n", *s); //if we want to get value we should write *s instead s
    //printf("s is %p\n", s); //if we want to get address we should write %p instead %s

    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    return(0);
}