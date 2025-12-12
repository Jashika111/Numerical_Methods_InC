#include <stdio.h>
#include <math.h>

#define MAX_ITER 10000
#define TOL 1e-6

int main() {
    double T1 = 0, T2 = 0, T3 = 0, T4 = 0;
    double error;

    printf("Solving Laplace Equation for 4 interior temperatures...\n");

    for (int iter = 1; iter <= MAX_ITER; iter++) {

        double old1 = T1, old2 = T2, old3 = T3, old4 = T4;

        // Using boundary values from the problem figure
        T1 = (100 + 100 + T2 + T3) / 4.0;   // top, left, right=T2, bottom=T3
        T2 = (100 + 0   + T1 + T4) / 4.0;   // top, left=T1, right=0, bottom=T4
        T3 = (T1 + 100 + 0 + T4) / 4.0;     // top=T1, left, right=0, bottom
        T4 = (T2 + T3 + 0 + 0) / 4.0;       // top=T2, left=T3, right/bottom=0

        error = fabs(T1-old1) + fabs(T2-old2) + fabs(T3-old3) + fabs(T4-old4);

        if (error < TOL) {
            printf("\nConverged in %d iterations.\n", iter);
            break;
        }
    }

    printf("\nFinal Temperature Values:\n");
    printf("T1 = %.6f\n", T1);
    printf("T2 = %.6f\n", T2);
    printf("T3 = %.6f\n", T3);
    printf("T4 = %.6f\n", T4);

    return 0;
}