#include <stdio.h>

int main(){

    double a, sum = 0, n = 0;

    while(scanf("%lf", &a) != EOF)
    {
        n++;
        sum+=a;
    }

    printf("%.6lf", sum/n);


    return 0;
}