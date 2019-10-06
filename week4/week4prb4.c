#include <stdio.h>

int main(){

    int i = 0;
    char a[1010] = {0,};
    long long b = 0;
    scanf("%s", a);

    while(a[i] != '\0')
    {
       b *= 2;
       b += a[i]-'0';
        i++;
    }

    i--;

    if(i % 4 != 3) printf("Error");
    else
    {
        i = 0;
        b = 0;
        while(a[i] != '\0')
        {
            b *= 2;
            b += a[i]-'0';
            if(i % 4 == 3)
            {
                printf("%X", b);
                b = 0;
            }
            i++;
        }
    }
    
    


    return 0;
}