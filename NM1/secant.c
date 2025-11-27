#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x*x - x - 2;  // 
}

int main() {
    float x0, x1, x2, tol;
    int max_iter, i;

    printf("Enter first initial guess x0: ");
    scanf("%f", &x0);
    printf("Enter second initial guess x1: ");
    scanf("%f", &x1);
    printf("Enter tolerance: ");
    scanf("%f", &tol);
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);

    printf("\nIter\t   x0\t\t   x1\t\t   f(x0)\t   f(x1)\t   x2\n");
    printf("----------------------------------------------------------------------------\n");
      for(i = 1; i <= max_iter; i++) {
        double f0 = f(x0);
        double f1 = f(x1);

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);  

        printf("%2d\t%10.6f\t%10.6f\t%10.6lf\t%10.6lf\t%10.6f\n", i, x0, x1, f0, f1, x2);

        if(fabs(x2 - x1) < tol) {
            printf("\nConverged to root: %f after %d iterations\n", x2, i);
            break;
        }

        x0 = x1;
        x1 = x2;
    }

    if(i > max_iter) {
        printf("\nDid not converge after %d iterations.\n", max_iter);
    }
    return 0;
}
