#include <stdio.h>
#include <unistd.h>


int main() {
    for (int i = 0; i < 5; ++i) {
        fork();
        sleep(5);
    }
}

/*
Result of execution with 3 fork() calls is 8 processes
ex2---ex2---ex2---ex2
    |     `-ex2
    |
    |-ex2---ex2
    `-ex2

So, we have 2^3 processes which are created by 3 fork()

For 5 fork() we will have 2^5 = 32 processes

ex2---ex2---ex2---ex2---ex2---ex2
    |     |     |     `-ex2
    |     |     |-ex2---ex2
    |     |     `-ex2
    |     |-ex2---ex2---ex2
    |     |     `-ex2
    |     |-ex2---ex2
    |     `-ex2
    |-ex2---ex2---ex2---ex2
    |     |     `-ex2
    |     |-ex2---ex2
    |     `-ex2
    |-ex2---ex2---ex2
    |     `-ex2
    |-ex2---ex2
    `-ex2

*/
