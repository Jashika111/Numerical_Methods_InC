#include <stdio.h>

int main() {
    int i, j, k, n;
    float a[10][11], ratio;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (Row by Row):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for(i = 0; i < n; i++) {

        // Make diagonal element 1
        float pivot = a[i][i];
        for(j = 0; j <= n; j++) {
            a[i][j] = a[i][j] / pivot;
        }

        // Make other elements in column zero
        for(k = 0; k < n; k++) {
            if(k != i) {
                ratio = a[k][i];
                for(j = 0; j <= n; j++) {
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    // Print solution
    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i+1, a[i][n]);
    }

    return 0;
}