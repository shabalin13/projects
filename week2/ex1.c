#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(int argc, char *argv[]) {
    int int_variable;
    float float_variable;
    double double_variable;
    int_variable = INT_MAX;
    float_variable = FLT_MAX;
    double_variable = DBL_MAX;

    printf("Size of integer: %d\n", sizeof(int_variable));
    printf("Value of integer %d\n", int_variable);
    printf("Size of float: %d\n", sizeof(float_variable));
    printf("Value of float %f\n", float_variable);
    printf("Size of double: %d\n", sizeof(double_variable));
    printf("Value of double %lf\n", double_variable);
    return 0;
}