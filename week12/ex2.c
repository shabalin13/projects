#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int num_of_file = 0;
    int append = 0;
    int fd[argc];
    char character;

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
                if (strcmp(argv[i], "-a") == 0)
                    append = 1;
                else {
                    fd[num_of_file] = i;
                    num_of_file++;
                }
        }
    }

    for (int j = 0; j < num_of_file; ++j) {
        if (append) {
            fd[j] = open(argv[fd[j]], O_RDWR | O_APPEND | O_CREAT, 0664);
        } else {
            fd[j] = open(argv[fd[j]], O_RDWR | O_CREAT, 0664);
        }
    }

    fd[num_of_file] = STDOUT_FILENO;

    while (read(STDIN_FILENO, &character, 1) > 0) {
        for (int i = 0; i <= num_of_file; ++i) {
            write(fd[i], &character, 1);
        }
    }

    for (int i = 0; i < num_of_file; ++i) {
        close(fd[i]);
    }

    return 0;
}


