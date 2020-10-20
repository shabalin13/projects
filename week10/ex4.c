#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char *argv[]) {

    DIR *dirp = opendir("tmp/");
    FILE *file = fopen("ex4.txt", "w");

    struct dirent *dp;
    char *allPaths[1024];
    struct stat buf1;
    struct stat buf2;
    char *allCheckedPaths[1024];

    int i = 0;
    while ((dp = readdir(dirp)) != NULL) {
        allPaths[i] = dp->d_name;
        i++;
    }
    int numberOfPaths = i;
    int y = 0;

    for (int j = 0; j < numberOfPaths; ++j) {
        int isMoreThanOneLink = 0;
        for (int k = j + 1; k < numberOfPaths; ++k) {
            char path1[1024];
            snprintf(path1, sizeof(path1), "%s%s", "tmp/", allPaths[j]);
            char path2[1024];
            snprintf(path2, sizeof(path2), "%s%s", "tmp/", allPaths[k]);

            stat(path1, &buf1);
            stat(path2, &buf2);

            int isAlreadyWasChecked = 0;
            for (int m = 0; m < y; ++m) {
                if (!strcmp(allCheckedPaths[m], allPaths[k])) {
                    isAlreadyWasChecked = 1;
                    break;
                }
            }

            if (!isAlreadyWasChecked && buf1.st_ino == buf2.st_ino) {
                if (!isMoreThanOneLink) {
                    fprintf(file, "%s %s", allPaths[j], allPaths[k]);
                    isMoreThanOneLink = 1;
                } else
                    fprintf(file, " %s", allPaths[k]);

                allCheckedPaths[y] = allPaths[k];
                y++;
            }
        }
        if (isMoreThanOneLink)
            fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}
