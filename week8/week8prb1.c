#include <stdio.h>


int main(){

    int len = 0;
    char str[1010];

    scanf("%s", str);
    
    while(str[len]!='\0')
    {
        len++;
    }
    len--;
    for(int i = 0; i < (len+1)/2; i++)
    {
        char tmp = str[i];
        str[i]=str[len-i];
        str[len-i] = tmp;
    }
    len++;
    printf("%d\n%s", len, str);

    return 0;
}