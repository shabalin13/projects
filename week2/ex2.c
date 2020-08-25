#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char input[1000];
    char output[1000];

    scanf("%s", input);

    int lengthOfInput = strlen(input);
    int end = lengthOfInput - 1;

    for (int i = 0; i < lengthOfInput; ++i) {
        output[i] = input[end];
        end--;
    }

    output[lengthOfInput] = '\0';
    printf("%s\n", output);

    return 0;
}