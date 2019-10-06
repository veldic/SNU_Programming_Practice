#include <stdio.h>

int main(){

    char a;

    while(scanf("%c", &a) != EOF)
    {
        if(a >= 'a'&& a<='z')
        {
            printf("%c", a+'A'-'a');
        }
        else if(a >= 'A' && a<= 'a')
        {
            printf("%c", a+'a'-'A');
        }
        else
        {
            printf("%c", a);
        }
    }


    return 0;
}