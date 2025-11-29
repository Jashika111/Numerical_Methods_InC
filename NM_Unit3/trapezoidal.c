#include<stdio.h>
#include<math.h>
float f(float x) {
    return exp(-(x*x)); 
}

int main(){
    float a,b,h,sum=0;
    int n;

    printf("ENter lower limit : ");
    scanf("%f",&a);
    printf("Enter upper limit : ");
    scanf("%f",&b);
    printf("Enter number of sub-intervals : ");
    scanf("%d",&n);

    h = (b-a)/n;

    sum = f(a) + f(b);

    for(int i = 1;i<n;i++){
        float x = a + i *h;
        sum += 2*f(x);
    }

    float result = (h/2)*sum;

    printf("Value of integral = %.6f\n",result);
    return 0;
}