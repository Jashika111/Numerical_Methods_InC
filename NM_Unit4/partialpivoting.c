#include <stdio.h>
#include <math.h>

#define MAX 20

int main() {
    int n;
    double A[MAX][MAX+1]; // Augmented matrix
    double x[MAX];

    // Step 1: Read number of unknowns
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    // Step 2: Read augmented matrix
    printf("Enter augmented matrix (A|b):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Step 3-5: Forward elimination with partial pivoting
    for (int k = 0; k < n; k++) {
        // Find the row with largest absolute value in column k
        int maxRow = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > fabs(A[maxRow][k])) {
                maxRow = i;
            }
        }

        // Swap rows if needed
        if (maxRow != k) {
            for (int j = 0; j <= n; j++) {
                double temp = A[k][j];
                A[k][j] = A[maxRow][j];
                A[maxRow][j] = temp;
            }
        }

        // Check for zero pivot
        if (A[k][k] == 0) {
            printf("Zero pivot found. No unique solution.\n");
            return 0;
        }

        // Normalize pivot row (make pivot = 1)
        double pivot = A[k][k];
        for (int j = k; j <= n; j++) {
            A[k][j] /= pivot;
        }

        // Eliminate column k in other rows
        for (int i = 0; i < n; i++) {
            if (i != k) {
                double factor = A[i][k];
                for (int j = k; j <= n; j++) {
                    A[i][j] -= factor * A[k][j];
                }
            }
        }
    }

    // Step 6: Extract solution
    for (int i = 0; i < n; i++) {
        x[i] = A[i][n]; // Last column is the solution
    }

    // Step 7: Display solution
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, x[i]);
    }

    return 0;
}