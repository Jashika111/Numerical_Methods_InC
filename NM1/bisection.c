#include<stdio.h>
#include<math.h>
#define ET 0.001
double f(double x){
    return x*x*x - x- 2;
}

int main(){
    float a, b, c;
    printf("Enter the interval [a,b]");
    scanf("%f%f",&a,&b);

    if(f(a)*f(b) >= 0){
        printf("Invalid interval! both must have negative signs! ");
            return 1;
    }
    printf("\nIter\t a\t\t b\t\t c\t\t f(c)\n");
    printf("-------------------\n");
//Apply bisection method
int iter=1;
while((b-a)  >= ET){
    c=(a+b)/2;
    printf("%d\t%f\t%f\t%f\t%f\n", iter, a, b, c, f(c));
    if(f(c) == 0)
    break;

    else if(f(a)*f(c)<0)
    b=c;
    else
    a=c;
    iter ++;
}
printf("The approximate root of the euation id %f\n",c);
return 0;
}//12