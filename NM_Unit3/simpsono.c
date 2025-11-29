//simpson1/3
#include<stdio.h>
#include<math.h>
float f(float x){
    return 1/(1 + x*x);
}

int main(){
    int n,i;
    float a,b,h,sum=0;
    printf("Enter lower limit : ");
    scanf("%f",&a);
    printf("Enter upper limit : ");
    scanf("%f",&b);
    printf("Enter number of sub-intervals (even number) : ");
    scanf("%d",&n);
    if(n%2 != 0){
        printf("Number of sub-intervals must be even.\n");
        return 1;
    }

    h = (b - a) / n;
    sum = f(a) + f(b);

    for(i = 1;i<n;i++){
        if(i%2 ==0){
            sum += 2*f(a + i*h);
        }
        else{
            sum += 4*f(a + i*h);
        }
    }

    float result = (h/3)*sum;
    printf("The approximate integral value for the given function is : %.6f\n",result);
    return 0;
    
}