#include <stdio.h>

#define f(x, y)  ( (y*y - x*x) / (y*y + x*x) )  // define your f(x,y) here

int main() {
    float x0, y0, xn, h;
    int n, i;
    
    printf("Enter initial condition:\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);

    printf("Enter x_n (point to compute y): ");
    scanf("%f", &xn);
    printf("Enter number of steps n: ");
    scanf("%d", &n);

    h = (xn - x0) / n;
    float x = x0;
    float y = y0;

    printf(" x\t y (Heun)\n");
    printf("%0.4f\t%0.4f\n", x, y);

    for (i = 0; i < n; i++) {
        float k1 = f(x, y);
        float y_euler = y + h * k1;               // Euler predictor
        float k2 = f(x + h, y_euler);             // slope at end of interval
        y = y + (h / 2.0) * (k1 + k2);            // Heun’s corrector formula
        x = x + h;
        printf("%0.4f\t%0.4f\n", x, y);
    }

    printf("Approximate value at x = %0.4f is y = %0.6f\n", x, y);

    return 0;
}