#include <stdio.h>

int main(){

    int n, a[110], y = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++)
    {
        int e = 0;
        for(int j = 0; j < n-i-1; j++)
        {
            int l=0;
            if(a[j+1] < a[j])
            {   
                e++;
                l++;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

            if(l)
            {
                y++;
                for(int o = 0; o < n; o++)
                {
                    printf("%d ", a[o]);
                }
                printf("\n");
            }
            
            
        }
        if(!e) break;
    }

    if(!y)
    {
        for(int o = 0; o < n; o++)
            {
                printf("%d ", a[o]);
            }
            printf("\n");
    }

    return 0;
}