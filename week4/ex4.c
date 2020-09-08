#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

#define BUFFER 1024


int main() {

    char command[BUFFER];
    char *argv[BUFFER];

    printf("-> ");
    while (1) {

        if (strcmp(gets(command), "exit") == 0)
            return 0;

        for (int i = 0; i < BUFFER; ++i)
            argv[i] = NULL;

        int length = strlen(command);

        int j = 0;
        int counterForWords = 0;
        argv[counterForWords]=(char*)malloc(BUFFER);

        for (int i = 0; i <= length; ++i) {
            if (command[i] != '\0' && command[i] != '\n') {
                if (command[i] == ' ') {
                    j = 0;
                    counterForWords++;
                    argv[counterForWords]=(char*)malloc(BUFFER);
                }
                else {
                    argv[counterForWords][j] = command[i];
                    j++;
                }
            }
            else
                break;
        }

        int PID = fork();
        int statusOfWaiting;

        if (PID == 0) {
            execvp(argv[0], argv);
        } else {
            while (wait(&statusOfWaiting) != PID);
        }

        printf("-> ");

    }
    return 0;
}
