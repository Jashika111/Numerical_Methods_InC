#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float x[50], y[50];
    float X[50], Y[50];
    float sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
    float A, b, a;

    printf("Enter number of data points: ");
    scanf("%d", &n);

   
    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
        X[i] = x[i];
        Y[i] = log(y[i]);

        sumX += X[i];
        sumY += Y[i];
        sumXY += X[i] * Y[i];
        sumXX += X[i] * X[i];
    }

    b = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    A = (sumY - b * sumX) / n;

    a = exp(A);
    b = exp(b);

    printf("\nThe required exponential curve is:\n");
    printf("y = %.4f * e^(%.4f x)\n", a, b);

    return 0;
}