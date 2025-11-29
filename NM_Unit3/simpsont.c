//simpson3/8
#include<stdio.h>
#include<math.h>

float f(float x) {
    return (x*x*x + 1);
     
}

int main(){
    float a,b,h,sum=0;
    int n,i;

    printf("Enter lower limit : ");
    scanf("%f",&a);
    printf("Enter upper limit : ");
    scanf("%f",&b);
    printf("Enter number of sub-intervals : ");
    scanf("%d",&n);
    if(n%3 != 0){
        printf("Number of sub-intervals must be a multiple of 3.\n");
        return 1;
    }

    h = (b-a)/n;
    sum = f(a) + f(b);

    for(i = 1;i<n;i++){
        if (i%3 == 0){
            sum += 2*f(a + i*h);
        }
        else{
            sum += 3*f(a + i*h);
        }
    }

    float result = (3*h/8)*sum;
    printf("Approximate integral value = %.6f\n",result);
    return 0;
}