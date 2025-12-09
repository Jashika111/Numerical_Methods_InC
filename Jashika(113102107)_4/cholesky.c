#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float A[10][10], L[10][10] = {0}, b[10], y[10], x[10];

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter matrix A (symmetric & positive definite):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter vector b:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &b[i]);

    // Cholesky Decomposition
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            float sum = 0;
            for(k = 0; k < j; k++)
                sum += L[i][k] * L[j][k];

            if(i == j)
                L[i][j] = sqrt(A[i][i] - sum);
            else
                L[i][j] = (A[i][j] - sum) / L[j][j];
        }
    }

    // Forward substitution Ly = b
    for(i = 0; i < n; i++) {
        float sum = 0;
        for(j = 0; j < i; j++)
            sum += L[i][j] * y[j];
        y[i] = (b[i] - sum) / L[i][i];
    }

    // Back substitution L^T x = y
    for(i = n-1; i >= 0; i--) {
        float sum = 0;
        for(j = i+1; j < n; j++)
            sum += L[j][i] * x[j];
        x[i] = (y[i] - sum) / L[i][i];
    }

    // Print solution
    printf("\nSolution:\n");
    for(i = 0; i < n; i++)
        printf("x%d = %.3f\n", i+1, x[i]);

    return 0;
}