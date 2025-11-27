
#include<stdio.h>
#include<math.h>

//dividing the lagrange formula into different terms
float first_term(float x, float x0, float x1, float x2, float x3, float f0){
    return f0*(((x-x1)*(x-x2)*(x-x3))/((x0-x1)*(x0-x1)*(x0-x3)));
}

float second_term(float x, float x0, float x1, float x2, float x3, float f1){
    return f1*(((x-x0)*(x-x2)*(x-x3))/((x1-x0)*(x1-x2)*(x1-x3)));
}

float third_term(float x, float x0, float x1, float x2, float x3, float f2){
    return f2*(((x-x0)*(x-x1)*(x-x3))/((x2-x0)*(x2-x1)*(x2-x3)));
}

float fourth_term(float x, float x0, float x1, float x2, float x3, float f3){
    return f3*(((x-x0)*(x-x1)*(x-x2))/((x3-x0)*(x3-x1)*(x3-x2)));
}

int main(){
    int i, n;
    float li, value;
    printf("Enter the no of points::");
    scanf("%d",&n);
    
    float x[n],f[n];
    printf("Find the function value of::");
    scanf("%f",&li);

    //inputs for functions and the value of x
    for ( i = 0; i < n; i++)
    {
       printf("\nEnter x%d:",i);
       scanf("%f",&x[i]);
       printf("\nEnter f%d:",i);
       scanf("%f",&f[i]);
    }

    //function call
    value = first_term(li,x[0],x[1],x[2],x[3],f[0])
            + second_term(li,x[0],x[1],x[2],x[3],f[1])
            + third_term(li,x[0],x[1],x[2],x[3],f[2])
            + fourth_term(li,x[0],x[1],x[2],x[3],f[3]);
    
    printf("\nThe value of f(%f) is %.4f",li,value);
    return 0; 
}
