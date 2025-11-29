#include<stdio.h>
#include<math.h>

float f(float x){
    return exp(-x);
}

double gaussian_integral(double a,double b){
    double x1 = -sqrt(3.0/5.0);
    double x2 = 0.0;
    double x3 = sqrt(3.0/5.0);

    double w1 = 5.0/9.0;
    double w2 = 8.0/9.0;
    double w3 = 5.0/9.0;

    double new_x1 = (b - a) / 2 * x1 + (a + b) / 2;
    double new_x2 = (b - a) / 2 * x2 + (a + b) / 2;
    double new_x3 = (b - a) / 2 * x3 + (a + b) / 2;

    double integral = (b - a) / 2 * (w1 * f(new_x1) + w2 * f(new_x2) + w3 * f(new_x3));
    return integral;
}

int main(){
    float a,b;
    printf("Enter the limits of integration (a b): ");
    scanf("%f %f", &a, &b);

double result = gaussian_integral(a,b);
    printf("The approximate integral value : %lf\n", result);
    return 0;
}