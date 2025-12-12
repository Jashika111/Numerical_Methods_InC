#include <stdio.h>
#include <math.h>

#define N 3    // Matrix size

int main() {
    float A[N][N];
    float X[N], Y[N], Xold[N];
    float k, EPS;
    int MAXIT, i, j, iter = 0;

    // -------- INPUT SECTION --------
    printf("Enter 3x3 Matrix A:\n");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            scanf("%f", &A[i][j]);

    printf("Enter initial vector X (size 3):\n");
    for(i = 0; i < N; i++)
        scanf("%f", &X[i]);

    printf("Enter error tolerance (EPS): ");
    scanf("%f", &EPS);

    printf("Enter maximum iterations (MAXIT): ");
    scanf("%d", &MAXIT);

    // -------- POWER METHOD ALGORITHM --------
    while (1) {
        iter++;

        // Save old X for convergence check
        for(i = 0; i < N; i++)
            Xold[i] = X[i];

        // Step 2: Y = A * X
        for(i = 0; i < N; i++) {
            Y[i] = 0;
            for(j = 0; j < N; j++) {
                Y[i] += A[i][j] * X[j];
            }
        }

        // Step 3: Find k = largest magnitude element of Y
        k = fabs(Y[0]);
        for(i = 1; i < N; i++)
            if(fabs(Y[i]) > k)
                k = fabs(Y[i]);

        // Step 4: X = Y / k
        for(i = 0; i < N; i++)
            X[i] = Y[i] / k;

        // Step 5: Check convergence |X - Xold|
        float diff = 0;
        for(i = 0; i < N; i++)
            diff += fabs(X[i] - Xold[i]);

        if (diff < EPS || iter > MAXIT)
            break;
    }

    // -------- OUTPUT --------
    printf("\nLargest Eigenvalue (approx) = %.6f\n", k);
    printf("Corresponding Eigenvector:\n");
    for(i = 0; i < N; i++)
        printf("%.6f ", X[i]);

    printf("\nIterations used = %d\n", iter);

    return 0;
}