#include <stdio.h>

int main() {
    int n, i, j;
    float x[10], y[10][10], value, h, s, result;

    
    printf("Enter number of data points: ");
    scanf("%d", &n);

    
    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    
    printf("Enter f(x) values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

   
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    
    printf("Enter the value of x to find f(x): ");
    scanf("%f", &value);

    
    h = x[1] - x[0];
    s = (value - x[0]) / h;
 
    result = y[0][0];
    float s_term = 1;

    for (j = 1; j < n; j++) {
        s_term *= (s - (j - 1));
        result += (s_term * y[0][j]) / j;
    }   
    printf("\nInterpolated value at x = %.3f is %.5f\n", value, result);
    return 0;
}