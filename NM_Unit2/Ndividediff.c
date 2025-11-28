#include <stdio.h>

int main() {
    int n, i, j;
    double x[10], y[10], table[10][10], value, result, product;

    // Input number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    // Input x and y values
    printf("Enter x values:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);    }

    printf("Enter y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
        table[i][0] = y[i];  // first column = y values
    }

    // Construct divided difference table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            table[i][j] = (table[i+1][j-1] - table[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    // Display divided difference table with x values
    printf("\nDivided Difference Table:\n");
    printf("   x        ");
    for (j = 0; j < n; j++) {
        printf("f[]%-8d", j);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%8.4lf ", x[i]);  // print x value
        for (j = 0; j < n - i; j++) {
            printf("%10.4lf ", table[i][j]);
        }
        printf("\n");
    }

    // Input interpolation point
    printf("\nEnter value to interpolate: ");
    scanf("%lf", &value);

    // Newton’s interpolation
    result = table[0][0];
    product = 1.0;
    for (i = 1; i < n; i++) {
        product *= (value - x[i-1]);
        result += table[0][i] * product;
    }

    printf("\nInterpolated value at x = %.2lf is %.4lf\n", value, result);

    return 0;
}