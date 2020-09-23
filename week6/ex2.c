#include <stdio.h>
#include <stdlib.h>

void sort(int **processes, int numberOfProcesses) {
    for (int i = 0; i < numberOfProcesses; ++i) {
        for (int j = i+1; j < numberOfProcesses; ++j) {
            if (processes[i][0] > processes[j][0]) {
                int *temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {

    int numberOfProcesses;
    printf("Write the number of processes\n");
    scanf("%d", &numberOfProcesses);

    int **processes = malloc(sizeof(int*) * numberOfProcesses);
    printf("Write arrival time and burst time for each process\n");

    for (int i = 0; i < numberOfProcesses; ++i) {

        processes[i] = malloc(sizeof(int) * 6);

        int arrivalTime;
        int burstTime;
        scanf("%d %d", &arrivalTime, &burstTime);

        processes[i][0] = arrivalTime;
        processes[i][1] = burstTime;
        processes[i][2] = 0;
        processes[i][3] = 0;
        processes[i][4] = 0;
        processes[i][5] = 0;
    }

    sort(processes, numberOfProcesses);

    double sumOfTAT = 0;
    double sumOfWT = 0;
    int time = 0;

    for (int i = 0; i < numberOfProcesses; ++i) {
        int CT;
        int TAT;
        int WT;

        int* nextProcess;


        int isNextProcess1 = 0;
        int* nextProcess1 = NULL;
        int* nextProcess2 = NULL; // if time < all arrival times of all processes
        int minimumBurst1 = 100000000;
        int minimumBurst2 = 100000000;
        int minimumNextArrival = 100000000;

        for (int k = 0; k < numberOfProcesses; ++k) {
            if (processes[k][5] == 0){
                if (processes[k][0] < minimumNextArrival) {
                    nextProcess2 = processes[k];
                    minimumNextArrival = processes[k][0];
                    minimumBurst2 = 100000000;
                }
                else if (processes[k][0] == minimumNextArrival && processes[k][1] < minimumBurst2) {
                    nextProcess2 = processes[k];
                    minimumBurst2 = processes[k][1];
                }
                if (processes[k][0] <= time && processes[k][1] < minimumBurst1) {
                    nextProcess1 = processes[k];
                    minimumBurst1 = processes[k][1];
                    isNextProcess1 = 1;
                }
            }
        }

        if (isNextProcess1)
            nextProcess = nextProcess1;
        else
            nextProcess = nextProcess2;



        if (time < nextProcess[0])
            time = nextProcess[0];

        CT = time + nextProcess[1];
        TAT = CT - nextProcess[0];
        WT = TAT - nextProcess[1];
        nextProcess[2] = CT;
        nextProcess[3] = TAT;
        nextProcess[4] = WT;
        sumOfTAT = sumOfTAT + TAT;
        sumOfWT = sumOfWT + WT;

        nextProcess[5] = 1;
        time = time + nextProcess[1];
    }

    for (int i = 0; i < numberOfProcesses; ++i) {
        printf("P%d(%d, %d):\t\t\v CT = %d \v\t\tTAT = %d \v\t\tWT = %d\n", i, processes[i][0], processes[i][1], processes[i][2], processes[i][3], processes[i][4]);
    }
    printf("Average TAT = %f\n", sumOfTAT/numberOfProcesses);
    printf("Average WT = %f\n", sumOfWT/numberOfProcesses);


    return 0;
}
