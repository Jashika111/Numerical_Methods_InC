#include <stdio.h>
#include <math.h>

#define N 3                     // Domain 0 to 3 → 4 grid points (0,1,2,3)
#define MAX_ITER 10000
#define TOL 1e-6

// Right-hand side: f(x,y) = 2x^2 y^2
double rhs(double x, double y) {
    return 2 * x * x * y * y;
}

int main() {
    double u[N+1][N+1] = {0};   // Solution grid (4×4 points)
    double h = 1.0;
    double error;

    printf("Solving Poisson Equation ...on boundary\n");//∇²f = 2x²y² on 0≤x≤3, 0≤y≤3 with f=0

    for (int iter = 1; iter <= MAX_ITER; iter++) {
        error = 0.0;

        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {

                double x = i * h;
                double y = j * h;

                double old = u[i][j];

                u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] +
                                  u[i][j+1] + u[i][j-1] -
                                  h*h * rhs(x, y));

                error += fabs(u[i][j] - old);
            }
        }

        if (error < TOL) {
            printf("\nConverged in %d iterations.\n", iter);
            break;
        }
    }

    printf("\nFinal Computed Values (4x4 grid):\n");
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%10.6f ", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}