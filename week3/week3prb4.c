#include <stdio.h>
/*
int main(){

    int n;
    char a;

    scanf("%d\n", &n);

    while(scanf("%c", &a) != EOF){

        if((a+n)>'Z'){
            printf("%c", a+n-26);
        }
        else if((a+n)<'A'){
            printf("%c", a+n+26);
        }
        else{
            printf("%c", a+n);
        }

    }


    return 0;
}
*/

int main(){

    int n;
    char a[1000] = {0,};
    scanf("%d", &n);
    scanf("%s", a);

    for(int i = 0; a[i] != '\0'; i++)
    {
        if((a[i]+n)>'Z'){
            a[i]=a[i]+n-26;
        }
        else if((a[i]+n)<'A'){
            a[i]=a[i]+n+26;
        }
        else{
            a[i]=a[i]+n;
        }
    }

    printf("%s", a);

    return 0;
}