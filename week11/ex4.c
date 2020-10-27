#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <zconf.h>
#include <string.h>

int main() {
    int in = open("ex1.txt", O_RDONLY);
    int out = open("ex1.memcp.txt", O_RDWR | O_CREAT);

    struct stat buf;
    fstat(in, &buf);

    char *src = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, in, 0);
    ftruncate(out, buf.st_size);
    char *dest = mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, out, 0);

    memcpy(dest, src, buf.st_size);

    munmap(src, buf.st_size);
    munmap(dest, buf.st_size);
    close(in);
    close(out);

    return 0;
}
