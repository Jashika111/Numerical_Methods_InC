#include <stdio.h>

int main() {
    int n, i;
    float x[20], y[20], h[20], a[20], l[20], u[20], z[20], c[20], b[20], d[20];
    float xp, result;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &y[i]);

    // Step 1: Compute h[i]
    for(i = 0; i < n-1; i++)
        h[i] = x[i+1] - x[i];

    // Step 2: Compute alpha
    for(i = 1; i < n-1; i++)
        a[i] = (3/h[i]) * (y[i+1] - y[i]) - (3/h[i-1]) * (y[i] - y[i-1]);

    // Step 3: Solve tridiagonal system for c[i]
    l[0] = 1;
    u[0] = 0;
    z[0] = 0;

    for(i = 1; i < n-1; i++) {
        l[i] = 2*(x[i+1] - x[i-1]) - h[i-1]*u[i-1];
        u[i] = h[i] / l[i];
        z[i] = (a[i] - h[i-1]*z[i-1]) / l[i];
    }

    l[n-1] = 1;
    z[n-1] = 0;
    c[n-1] = 0;

    for(i = n-2; i >= 0; i--) {
        c[i] = z[i] - u[i]*c[i+1];
        b[i] = (y[i+1] - y[i]) / h[i] - h[i] * (c[i+1] + 2*c[i]) / 3;
        d[i] = (c[i+1] - c[i]) / (3*h[i]);
        a[i] = y[i];
    }

    printf("\nEnter x for interpolation: ");
    scanf("%f", &xp);

    // Step 4: Find interval
    int j;
    for(j = 0; j < n-1; j++) {
        if(xp >= x[j] && xp <= x[j+1])
            break;
    }

    float diff = xp - x[j];
    result = a[j] + b[j]*diff + c[j]*diff*diff + d[j]*diff*diff*diff;

    printf("\nInterpolated value at x = %.3f is %.4f\n", xp, result);

    return 0;
}