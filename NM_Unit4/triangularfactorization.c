#include <stdio.h>

int main() {
    float A[10][10], L[10][10] = {0}, U[10][10] = {0};
    float b[10], y[10], x[10];
    int n, i, j, k;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter matrix A (row-wise):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter vector b:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &b[i]);

    // Compute L and U using Doolittle's method
    for (i = 0; i < n; i++) {

        // Upper Triangular: U[i][j]
        for (j = i; j < n; j++) {
            float sum = 0;
            for (k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];
            U[i][j] = A[i][j] - sum;
        }

        // Lower Triangular: L[j][i]
        for (j = i; j < n; j++) {
            if (i == j)
                L[i][j] = 1;  // Diagonal of L is 1
            else {
                float sum = 0;
                for (k = 0; k < i; k++)
                    sum += L[j][k] * U[k][i];
                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }

    // Solve Ly = b (Forward substitution)
    for (i = 0; i < n; i++) {
        float sum = 0;
        for (j = 0; j < i; j++)
            sum += L[i][j] * y[j];
        y[i] = b[i] - sum;
    }

    // Solve Ux = y (Back substitution)
    for (i = n - 1; i >= 0; i--) {
        float sum = 0;
        for (j = i + 1; j < n; j++)
            sum += U[i][j] * x[j];
        x[i] = (y[i] - sum) / U[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.3f\n", i + 1, x[i]);

    return 0;
}