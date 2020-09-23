#include <stdio.h>
#include <stdlib.h>

int main() {

    int numberOfProcesses;
    printf("Enter the number of processes\n");
    scanf("%d", &numberOfProcesses);

    int **processes = malloc(sizeof(int*) * numberOfProcesses);
    printf("Enter arrival time and burst time for each process\n");

    for (int i = 0; i < numberOfProcesses; ++i) {

        processes[i] = malloc(sizeof(int) * 6);

        int arrivalTime;
        int burstTime;
        scanf("%d %d", &arrivalTime, &burstTime);

        processes[i][0] = arrivalTime;
        processes[i][1] = burstTime;
        processes[i][2] = 0; //CT
        processes[i][3] = 0; //TAT
        processes[i][4] = 0; //WT
        processes[i][5] = 0; //if process terminated
    }

    for (int i = 0; i < numberOfProcesses; ++i) {
        for (int j = i+1; j < numberOfProcesses; ++j) {
            if (processes[i][0] > processes[j][0]) {
                int *temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    double sumOfTAT = 0;
    double sumOfWT = 0;
    int time = 0;

    for (int i = 0; i < numberOfProcesses; ++i) {
        int CT;
        int TAT;
        int WT;

        int* process;

        int isprocess1 = 0;
        int* process1 = NULL;
        int* process2 = NULL; // if time < all arrival times of all processes
        int minimumBurst1 = 100000000;
        int minimumBurst2 = 100000000;
        int minimumNextArrival = 100000000;

        for (int k = 0; k < numberOfProcesses; ++k) {
            if (processes[k][5] == 0){
                if (processes[k][0] < minimumNextArrival) {
                    process2 = processes[k];
                    minimumNextArrival = processes[k][0];
                    minimumBurst2 = 100000000;
                }
                else if (processes[k][0] == minimumNextArrival && processes[k][1] < minimumBurst2) {
                    process2 = processes[k];
                    minimumBurst2 = processes[k][1];
                }
                if (processes[k][0] <= time && processes[k][1] < minimumBurst1) {
                    process1 = processes[k];
                    minimumBurst1 = processes[k][1];
                    isprocess1 = 1;
                }
            }
        }

        if (isprocess1)
            process = process1;
        else
            process = process2;

        if (time < process[0])
            time = process[0];

        CT = time + process[1];
        TAT = CT - process[0];
        WT = TAT - process[1];
        process[2] = CT;
        process[3] = TAT;
        process[4] = WT;
        sumOfTAT = sumOfTAT + TAT;
        sumOfWT = sumOfWT + WT;

        process[5] = 1;
        time = time + process[1];
    }

    for (int i = 0; i < numberOfProcesses; ++i) {
        printf("P%d(%d, %d):\t\t\v CT = %d \v\t\tTAT = %d \v\t\tWT = %d\n", i, processes[i][0], processes[i][1], processes[i][2], processes[i][3], processes[i][4]);
    }
    printf("Average TAT = %f\n", sumOfTAT/numberOfProcesses);
    printf("Average WT = %f\n", sumOfWT/numberOfProcesses);

    return 0;
}
