#include<stdio.h>
#include<math.h>

float fun(float x) {
    return (x*x + 2*x - 2);
}

float dfun(float x) {
    return (2*x + 2);   // correct derivative
}

int main() {
    int i = 0;
    float x1, x2;

    printf("Enter any initial guess: ");
    scanf("%f", &x1);

    do {
        x2 = x1 - fun(x1) / dfun(x1);

        printf("Iteration %d: x = %f\n", i + 1, x2);

        if (fabs(x2 - x1) < 0.0001)
            break;

        x1 = x2;
        i++;
    } while (i < 20);

    printf("\nApproximate root = %f\n", x2);
    return 0;
}

