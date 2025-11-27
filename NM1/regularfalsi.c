#include <stdio.h>
#include <math.h>

float f(float x) {
    return cos(x) - x;    //cosx-x
}

int main() {
    float a, b, c, fa, fb, fc, tol;
    int max_iter, i;

    printf("Enter first guess a: ");
    scanf("%f", &a);
    printf("Enter second guess b: ");
    scanf("%f", &b);
    printf("Enter tolerance: ");
    scanf("%f", &tol);
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);

    fa = f(a);
    fb = f(b);

    if(fa * fb >= 0) {
        printf("The guesses do not bracket a root.\n");
        return 1;
    }

    printf("\nIter\t     a\t\t     b\t\t    c\t\t   f(c)\n");
    printf("---------------------------------------------------------------\n");

    for(i = 1; i <= max_iter; i++) {
        
        c = b - fb * (b - a) / (fb - fa);
        fc = f(c);

        printf("%2d\t%10.6f\t%10.6f\t%10.6f\t%10.6f\n", i, a, b, c, fc);

        if(fabs(fc) < tol) {
            printf("\nConverged to root: %f after %d iterations\n", c, i);
            break;
        }

        
        if(fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    if(i > max_iter) {
        printf("\nDid not converge after %d iterations.\n", max_iter);
    }

    return 0;
}