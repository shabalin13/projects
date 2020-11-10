#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int num_of_proc;
    int num_of_res;

    printf("Enter number of processes: ");
    scanf("%d", &num_of_proc);
    printf("Enter number of resource types: ");
    scanf("%d", &num_of_res);

    int *E = malloc(sizeof(int) * num_of_res);
    for (int i = 0; i < num_of_res; i++)
        fscanf(input, "%d", &E[i]);

    int *A = malloc(sizeof(int) * num_of_res);
    for (int i = 0; i < num_of_res; i++)
        fscanf(input, "%d", &A[i]);

    int **C = malloc(sizeof(int*) * num_of_proc);
    for (int i = 0; i < num_of_proc; i++) {
        C[i] = malloc(sizeof(int) * num_of_res);
        for (int j = 0; j < num_of_res; j++) {
            fscanf(input, "%d", &C[i][j]);
        }
    }

    int **R = malloc(sizeof(int*) * num_of_proc);
    for (int i = 0; i < num_of_proc; i++) {
        R[i] = malloc(sizeof(int) * num_of_res);
        for (int j = 0; j < num_of_res; j++) {
            fscanf(input, "%d", &R[i][j]);
        }
    }

    int *F = malloc(sizeof(int) * num_of_proc);
    for (int i = 0; i < num_of_proc; i++)
        F[i] = 0;

    while (1) {
        int num_of_cur_proc = -1;
        for (int i = 0; i < num_of_proc; i++) {
            if (!F[i]) {
                int isGood = 1;
                for (int j = 0; j < num_of_res; j++) {
                    if (R[i][j] > A[j])
                        isGood = 0;
                }
                if (isGood) {
                    num_of_cur_proc = i;
                    F[num_of_cur_proc] = 1;
                    break;
                }
            }
        }
        int isA_biggerThan_E = 0;
        if (num_of_cur_proc == -1)
            break;
        else {
            for (int j = 0; j < num_of_res; j++) {
                A[j] = A[j] + C[num_of_cur_proc][j];
                if (A[j] > E[j])
                    isA_biggerThan_E = 1;
            }
        }

        if (isA_biggerThan_E) {
            F[num_of_cur_proc] = 0;
            break;
        }

    }

    int num_of_dl = 0;
    for (int i = 0; i < num_of_proc; i++) {
        if (!F[i])
            num_of_dl++;
    }

    if (num_of_dl == 0)
        fprintf(output, "No deadlock is detected");
    else if (num_of_dl == 1)
        fprintf(output, "%d process is deadlocked", num_of_dl);
    else
        fprintf(output, "%d processes are deadlocked", num_of_dl);

    return 0;
}
