#include <stdio.h>

#define MAX 20

int main() {
    int n;
    double A[MAX][MAX+1], x[MAX];

  
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    
    printf("Enter augmented matrix (A|b):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    
    for (int k = 0; k < n - 1; k++) {

        if (A[k][k] == 0) {
            printf("Zero pivot found. No unique solution.\n");
            return 0;
        }

        for (int i = k + 1; i < n; i++) {
            double m = A[i][k] / A[k][k];

            for (int j = k; j <= n; j++) {
                A[i][j] = A[i][j] - m * A[k][j];
            }
        }
    }

    
    for (int i = n - 1; i >= 0; i--) {
        double sum = A[i][n];

        for (int j = i + 1; j < n; j++) {
            sum -= A[i][j] * x[j];
        }

        x[i] = sum / A[i][i];
    }

    
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, x[i]);
    }

    
    return 0;
}