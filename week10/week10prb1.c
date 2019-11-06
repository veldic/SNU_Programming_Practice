#include <stdio.h>

int main(){

    int a, b, A[1010], B[1010], C[2010];
    
    scanf("%d %d", &a, &b);

    for(int i = 0; i < a; i++)
    {
        scanf("%d", &A[i]);
    }

    
    for(int i = 0; i < b; i++)
    {
        scanf("%d", &B[i]);
    }

    int x=0, y=0;

    for(int i = 0; i < a+b; i++)
    {
        
        if(A[x] > B[y])
        {
            if(y != b)
            {
                C[i] = B[y];
                y++;
                printf("1");
            }
            else
            {
                C[i] = A[x];
                x++;
                printf("0");
            }
        }
        else
        {
            if(x != a)
            {
                C[i] = A[x];
                x++;
                printf("0");
            }
            else
            {
                C[i] = B[y];
                y++;
                printf("1");
            }
        }
    }
    printf("\n");
    for(int i = 0; i < a+b; i++)
    {
        printf("%d ", C[i]);
    }


    return 0;
}