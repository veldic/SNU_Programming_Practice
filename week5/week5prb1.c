#include <stdio.h>

long fact(int n)
{
    if(n == 1||n == 0) return 1;
    else return n*fact(n-1);
}

int main(){

    int n;

    scanf("%d", &n);

    printf("%ld\n", fact(n));

    return 0;
}