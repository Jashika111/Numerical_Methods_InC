#include <stdio.h>

int main() {
    int n, i;
    float x[50], y[50];
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    float m, c, xp, yp;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    // Calculate summations
    for (i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculate slope (m) and intercept (c)
    m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    c = (sumY - m * sumX) / n;

    printf("\nRegression Line: y = %.4f x + %.4f\n", m, c);

   

    return 0;
}