#include <stdio.h>

#define f(x,y)   (x*x*y - 1)                    // dy/dx = x^2*y - 1
#define fx(x,y)  (2*x*y)                        // ∂f/∂x = 2xy
#define fy(x,y)  (x*x)                          // ∂f/∂y = x^2

int main() {
    float x = 0.0, y = 1.0;   // y(0) = 1
    float h = 0.1;
    float t1, t2;

    printf("Using Taylor Series Method for dy/dx = x^2*y - 1\n");
    printf("Initial value: y(0) = 1\n\n");

    printf("x\t\t y\n");
    printf("%.1f\t %.5f\n", x, y);

    // -------- y at x = 0.1 --------
    t1 = f(x, y);
    t2 = fx(x, y) + fy(x, y) * t1;
    y = y + h * t1 + (h*h/2.0) * t2;
    x = x + h;

    printf("%.1f\t %.5f\n", x, y);
    float y01 = y;

    // -------- y at x = 0.2 --------
    t1 = f(x, y);
    t2 = fx(x, y) + fy(x, y) * t1;
    y = y + h * t1 + (h*h/2.0) * t2;
    x = x + h;

    printf("%.1f\t %.5f\n", x, y);
    float y02 = y;

    printf("\nFinal Results:\n");
    printf("y(0.1) = %.5f\n", y01);
    printf("y(0.2) = %.5f\n", y02);

    return 0;
}