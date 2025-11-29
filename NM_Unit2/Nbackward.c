#include <stdio.h>

int main() {
    int n, i, j;
    float x[10], y[10][10], value, h, s, result, p;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter f(x) values:\n");
    for (i = 0; i < n; i++) 
        scanf("%f", &y[i][0]);

    
    for (j = 1; j < n; j++) { 
        for (i = n-1; i >= j; i--) {
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    printf("Enter the value of x to interpolate: ");
    scanf("%f", &value);

    h = x[1] - x[0];                 
    s = (value - x[n-1]) / h;        

    result = y[n-1][0];              

    p = 1;   

    for (j = 1; j < n; j++) {
        p = p * (s + (j - 1));       
        result += (p * y[n-1][j]) / j; 
    }

    printf("\nInterpolated value at x = %.3f is %.5f\n", value, result);

    return 0;
}