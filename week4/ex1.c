#include <stdio.h>
#include <zconf.h>

int main() {
    int id = fork();

    if (id == -1)
        printf("Failed to create child process.");
    else if (id == 0) {
        pid_t n = getpid();
        printf("Hello from child [PID - %d]\n", n);
    }
    else{
        pid_t n = getpid();
        printf("Hello from parent [PID - %d]\n", n);
    }
    return 0;
}

/*
We get different IDs by running the program 10 times as we create different processes.

Hello from parent [PID - 11356]
Hello from child [PID - 11357]
Hello from parent [PID - 11358]
Hello from child [PID - 11359]
Hello from parent [PID - 11360]
Hello from child [PID - 11361]
Hello from parent [PID - 11362]
Hello from child [PID - 11363]
Hello from parent [PID - 11364]
Hello from child [PID - 11365]
Hello from parent [PID - 11366]
Hello from child [PID - 11367]
Hello from parent [PID - 11368]
Hello from child [PID - 11369]
Hello from parent [PID - 11370]
Hello from child [PID - 11371]
Hello from parent [PID - 11372]
Hello from child [PID - 11373]
Hello from parent [PID - 11374]
Hello from child [PID - 11375]
 */