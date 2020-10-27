#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <zconf.h>


int main() {

    struct stat buf;
    int fd = open("ex1.txt", O_RDWR);

    fstat(fd, &buf);

    char *addr = mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, fd, 0);

    ftruncate(fd, (strlen("This is a nice day")) * sizeof(char));

    fstat(fd, &buf);

    strncpy(addr, "This is a nice day", buf.st_size);

    munmap(addr, buf.st_size);
    close(fd);

    return 0;
}