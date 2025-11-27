#include<stdio.h>
#include<math.h>

float fun(float x){    //g(x) function
     return ((sin(x) + 2) / 5.0);
}

int main(){
    int i = 1;
    float a, x2;

    printf("Enter the initial guess: ");
    scanf("%f", &a);

    do {
        x2 = fun(a);

        printf("\nIteration %d: x = %.4f", i, x2);

        if (fabs(a - x2) < 0.0001)     //comparision
            break;

        a = x2;
        i++;

    } while (i < 20);

    printf("\nRoot ~ %.4f\n", x2);
    

    return 0;
}
