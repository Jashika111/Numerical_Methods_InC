#include <stdio.h>
#include <math.h>

float function(float x) {
    return 1 / (1 + x);
}

int main() {
    int k, i, j, n=3;
    float a, b, h;
    
    printf("Enter the lower and upper limit:\n");
    scanf("%f%f", &a, &b);
    
    // Romberg table
    float R[n][n];
    
    // R[0][0] = Trapezoidal rule with one interval
    R[0][0] = (b - a) / 2 * (function(a) + function(b));
    
    // Compute the first column of Romberg table
    for (i = 1; i < n; i++) {
        h = (b - a) / pow(2, i);  // step size
        float sum = 0.0;
        
        // sum f(a + (2k - 1)h) for k = 1 to 2^(i-1)
        for (k = 1; k <= pow(2, i - 1); k++) {
            sum += function(a + (2 * k - 1) * h);
        }
        
        // Trapezoidal approximation for this level
        R[i][0] = 0.5 * R[i - 1][0] + h * sum;
    }
    
    // Romberg extrapolation
    for (j = 1; j < n; j++) {
        for (i = j; i < n; i++) {
            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }
    }
    
    printf("\nRomberg Integration Result (R[%d][%d]) = %.6f\n", n-1, n-1, R[n-1][n-1]);
    
    return 0;
}