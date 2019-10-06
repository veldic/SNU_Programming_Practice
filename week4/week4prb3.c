#include <stdio.h>

int main(){

    int n;
    char a[11];
    int x = 1;

    scanf("%d", &n);

    scanf("%s", a);

    for(int i = 0; i < n/2; i++)
    {
        if(a[i] != a[n-i-1])
        {
            x = 0;
            break;
        }
    }
    
    printf("%d", x);


    return 0;
}