#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f1(x,y) ((11-y)/3)
#define f2(x,y) ((16-2*x)/5)
#define E 0.001

int main(){
    float x0,y0,x1,y1,e1,e2;
    printf("ENter two initial guess : \n");
    scanf("%f%f",&x0,&y0);
    do{
        x1 = f1(x0,y0);
        e1 = fabs(x1-x0);
        x0=x1;
        y1 = f2(x0,y0);
        e2 = fabs(y1-y0);
        y0 = y1;
    }while(e1>E && e2 > E);
    printf("The root is %f and %f",x0,y0);
    return 0;
}