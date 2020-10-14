#include <stdio.h>
#include <stdlib.h>

struct pageFrame {
    unsigned int age;
    int numberOfPage;
};

int main(int argc, char *argv[]) {

    FILE *input = fopen("input.txt", "r");

    int hit = 0;
    int miss = 0;
    int numberOfFrames;
    sscanf(argv[1], "%d", &numberOfFrames); // get as a parameter

    struct pageFrame *frames = malloc(sizeof(struct pageFrame) * numberOfFrames);

    // initialize all page frames
    for (int i = 0; i < numberOfFrames; ++i) {
        frames[i].numberOfPage = -1;
        frames[i].age = 0;
    }

    int page;
    // reading from file
    while (fscanf(input, "%d", &page) != EOF) {
        int isFound = 0; // check if we have necessary page frame in all frames
        // checking for this
        for (int i = 0; i < numberOfFrames; ++i) {
            if (frames[i].numberOfPage == page) {
                isFound = 1;
                break;
            }
        }
        // if we found necessary page frame then just update all frames
        if (isFound) {
            hit++; // update counter for hits
            for (int i = 0; i < numberOfFrames; ++i) {
                if (frames[i].numberOfPage != -1) {
                    frames[i].age >>= 1; // shift left all pages
                    if (frames[i].numberOfPage == page)
                        frames[i].age |= (1 << 31); // add R bit to age for necessary page frame
                }
            }
        }
        // if we did not find necessary page frame
        else {
            miss++; // update counter for misses
            int indexOfMinAge = 0; // index of page frame with minimum age
            int index; // index of page frame that is empty
            int EmptyWasFound = 0; // check for empty page frame
            for (int i = 0; i < numberOfFrames; ++i) {
                // if we found empty page frame
                if (frames[i].numberOfPage == -1) {
                    index = i; // save index of this page frame
                    EmptyWasFound = 1; // update checker
                    // insert new page
                    frames[i].numberOfPage = page;
                    frames[i].age = 1 << 31; // add R bit to age for necessary page frame
                    break;
                }
                // searching for page frame with minimum age
                if (frames[i].age < frames[indexOfMinAge].age)
                    indexOfMinAge = i; // update index
            }
            // if we found empty page frame
            if (EmptyWasFound) {
                // update all page frames, except what we have already updated
                for (int i = 0; i < numberOfFrames; ++i) {
                    if (frames[i].numberOfPage != -1 && i != index) {
                        frames[i].age >>= 1; // shift left
                    }
                }
            }
            // if we did not find empty page frame
            else {
                // update all page frames
                for (int i = 0; i < numberOfFrames; ++i) {
                    if (frames[i].numberOfPage != -1) {
                        frames[i].age >>= 1; // shift left
                        // insert new page
                        if (indexOfMinAge == i) {
                            frames[i].age = 1 << 31; // add R bit to age for necessary page frame
                            frames[i].numberOfPage = page;
                        }
                    }
                }
            }
        }
    }

    printf("hits:\t%d\n", hit);
    printf("misses:\t%d\n", miss);
    printf("hit/miss:\t%f\n", (double)hit/(double)miss);

    return 0;
}

/*
for numberOfFrames = 10:
    hits:	10
    misses:	990
    hit/miss:	0.010101

for numberOfFrames = 50:
    hits:	51
    misses:	949
    hit/miss:	0.053741

for numberOfFrames = 100:
    hits:	95
    misses:	905
    hit/miss:	0.104972
 */