#include <stdio.h>
#include <stdlib.h>

int main() {

    int numberOfProcesses;
    int quantum;
    printf("Enter the number of processes and the quantum\n");
    scanf("%d %d", &numberOfProcesses, &quantum);

    int **processes = malloc(sizeof(int*) * numberOfProcesses);
    printf("Enter arrival time and burst time for each process\n");

    for (int i = 0; i < numberOfProcesses; ++i) {

        processes[i] = malloc(sizeof(int) * 7);

        int arrivalTime;
        int burstTime;
        scanf("%d %d", &arrivalTime, &burstTime);

        processes[i][0] = arrivalTime;
        processes[i][1] = burstTime;
        processes[i][2] = 0; //CT
        processes[i][3] = 0; //TAT
        processes[i][4] = 0; //WT
        processes[i][5] = 0; //if process terminated
        processes[i][6] = burstTime; //remaining
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

    int isAllProcessFinished = 0;
    while (!isAllProcessFinished) {
        int* process;
        int processWasTaken = 0;
        int i = 0;
        while (i < numberOfProcesses && processes[i][0] <= time) {
            process = processes[i];
            if (!process[5]) {
                processWasTaken = 1;
                if (process[6] < quantum) {
                    time = time + process[6];
                    process[6] = 0;
                }
                else {
                    time = time + quantum;
                    process[6] = process[6] - quantum;
                }

                if (process[6] <= 0) {
                    process[5] = 1;
                    int CT;
                    int TAT;
                    int WT;
                    CT = time;
                    TAT = CT - process[0];
                    WT = TAT - process[1];
                    process[2] = CT;
                    process[3] = TAT;
                    process[4] = WT;
                }
            }
            if (i+1 >= numberOfProcesses && processWasTaken == 0)
                isAllProcessFinished = 1;
            i++;
        }

        if (!processWasTaken && i+1 < numberOfProcesses)
            time = processes[i+1][0];

        for (int j = 0; j < numberOfProcesses; ++j) {
            if (processes[j][0] > time && processes[j][5] == 0) {
                time = processes[j][0];
                break;
            }
        }
    }

    for (int j = 0; j < numberOfProcesses; ++j) {
        sumOfTAT = sumOfTAT + processes[j][3];
        sumOfWT = sumOfWT + processes[j][4];
    }

    for (int i = 0; i < numberOfProcesses; ++i) {
        printf("P%d(%d, %d):\t\t\v CT = %d \v\t\tTAT = %d \v\t\tWT = %d\n", i, processes[i][0], processes[i][1], processes[i][2], processes[i][3], processes[i][4]);
    }
    printf("Average TAT = %f\n", sumOfTAT/numberOfProcesses);
    printf("Average WT = %f\n", sumOfWT/numberOfProcesses);

    return 0;
}

