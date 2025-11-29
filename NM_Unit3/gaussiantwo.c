//gaussian two point
#include<stdio.h>
#include<math.h>

float f(float x){
    return exp(-x*x);
}

double gaussian_integral(double a,double b){
    double x1 = (b-a)/2 * (-1.0/sqrt(3)) + (a+b)/2;
    double x2 = (b-a)/2 * (1.0/sqrt(3)) + (a+b)/2;

    double w1= (b-a)/2;
    double w2= (b-a)/2;

    return w1*f(x1) + w2*f(x2);
}

int main(){
    float a,b;
    printf("Enter the limits of integration (a b): ");
    scanf("%f %f", &a, &b);
    double result = gaussian_integral(a,b);
    printf("The approximate integral value : %lf\n", result);
    return 0;
}