#include <stdio.h>

int main() {
    
    FILE *input = fopen("/dev/random", "r");
    FILE *output = fopen("../ex1.txt", "w");

    char buffer[21];
    fgets(buffer, 21, input);
    fprintf(output, "%s", buffer);
    printf("%s", buffer);

    fclose(input);
    fclose(output);
    return 0;
}
