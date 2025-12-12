#include <stdio.h>

#define f(x, y) (x + y)   // Change this for different f(x, y)

int main() {
    float x0, y0, xn, h;
    int n, iter, i;

    printf("Enter initial condition:\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);

    printf("Enter the point at which you want y(x): ");
    scanf("%f", &xn);

    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter number of Picard iterations: ");
    scanf("%d", &n);

    float x[100], y[100], y_prev[100];

    int steps = (xn - x0) / h;

    x[0] = x0;
    y[0] = y0;

    for (i = 1; i <= steps; i++)
        x[i] = x[i - 1] + h;

    // First approximation: y = y0 (constant)
    for (i = 0; i <= steps; i++)
        y_prev[i] = y0;

    // Perform Picard iterations
    for (iter = 1; iter <= n; iter++) {
        y[0] = y0;
        for (i = 1; i <= steps; i++) {
            // Numerical integration using rectangular rule
            y[i] = y0 + h * f(x[i - 1], y_prev[i - 1]) + 
                          h * f(x[i - 1], y_prev[i - 1]);
        }

        // Copy y -> y_prev for next iteration
        for (i = 0; i <= steps; i++)
            y_prev[i] = y[i];

        printf("After iteration %d: y(%0.4f) = %0.6f\n", iter, xn, y[steps]);
    }

    printf("\nFinal approximate value: y(%0.4f) = %0.6f\n", xn, y[steps]);

    return 0;
}