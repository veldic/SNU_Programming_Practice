#include <stdio.h>
#include <math.h>

int main(){

    int a, b;
    
    scanf("%d %d", &a, &b);

    for(int i = a; i <=b; i++)
    {
        if(i == 1) continue;

        int notprime = 0;

        for(int j = 2; j <= sqrt(i); j++)
        {
            if(i%j == 0)
            {
                notprime = 1;
                break;
            }
        }
        if(!notprime) printf("%d ", i);
    }



    return 0;
}