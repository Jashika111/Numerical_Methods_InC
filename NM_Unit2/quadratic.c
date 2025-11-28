#include <stdio.h>

int main() {
    int n, i;
    float x[20], y[20];
    float sx = 0, sy = 0, sxx = 0, sxy = 0, sxxx = 0, sxxy = 0, sxxxx = 0;
    float a, b, c;
    float A[3][4], t;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &y[i]);

    // Compute required summations
    for(i = 0; i < n; i++) {
        sx += x[i];
        sy += y[i];
        sxx += x[i] * x[i];
        sxy += x[i] * y[i];
        sxxx += x[i] * x[i] * x[i];
        sxxy += x[i] * x[i] * y[i];
        sxxxx += x[i] * x[i] * x[i] * x[i];
    }

    // Normal equations in augmented matrix form
    A[0][0] = n;     A[0][1] = sx;    A[0][2] = sxx;   A[0][3] = sy;
    A[1][0] = sx;    A[1][1] = sxx;   A[1][2] = sxxx;  A[1][3] = sxy;
    A[2][0] = sxx;   A[2][1] = sxxx;  A[2][2] = sxxxx; A[2][3] = sxxy;

    // Gaussian elimination
    for(i = 0; i < 3; i++) {
        int j, k;
        for(j = i + 1; j < 3; j++) {
            t = A[j][i] / A[i][i];
            for(k = 0; k < 4; k++)
                A[j][k] -= t * A[i][k];
        }
    }

    // Back substitution
    c = A[2][3] / A[2][2];
    b = (A[1][3] - A[1][2] * c) / A[1][1];
    a = (A[0][3] - A[0][2] * c - A[0][1] * b) / A[0][0];

    printf("\nFitted quadratic polynomial:\n");
    printf("y = %.4f + %.4fx + %.4fx^2\n", a, b, c);

    return 0;
}