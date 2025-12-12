#include <stdio.h>

#define N 3  // Number of variables

int main() {
    int i, j, k;
    float A[N][N], aug[N][2*N], b[N], x[N];

    // Input matrix A
    printf("Enter %d x %d matrix A:\n", N, N);
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%f",&A[i][j]);

    // Input vector b
    printf("Enter vector b:\n");
    for(i=0;i<N;i++)
        scanf("%f",&b[i]);

    // Form augmented matrix [A | I]
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            aug[i][j] = A[i][j];
        for(j=N;j<2*N;j++)
            aug[i][j] = (i == j-N) ? 1 : 0;
            
    }

    // Gauss-Jordan elimination to get [I | A^-1]
    for(i=0;i<N;i++){
        float pivot = aug[i][i];
        for(j=0;j<2*N;j++)
            aug[i][j] /= pivot;

        for(k=0;k<N;k++){
            if(k!=i){
                float factor = aug[k][i];
                for(j=0;j<2*N;j++)
                    aug[k][j] -= factor * aug[i][j];
            }
        }
    }

    // Multiply A^-1 * b to get solution x
    for(i=0;i<N;i++){
        x[i] = 0;
        for(j=0;j<N;j++)
            x[i] += aug[i][j+N] * b[j];
    }

    // Print solution
    printf("\nSolution vector x:\n");
    for(i=0;i<N;i++)
        printf("x%d = %.3f\n", i+1, x[i]);

    return 0;
}