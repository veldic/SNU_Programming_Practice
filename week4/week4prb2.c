#include <stdio.h>

int main(){

    int n, b[26] = {0,};
    char a;

    scanf("%d", &n);

    for(int i = 0; i <= n; i++)
    {
        scanf("%c", &a);
        if(a-'a' >= 0 && a-'z' <= 0)
        {
            b[a-'a']++;
        }
        else if(a-'A' >= 0 && a-'Z' <= 0)
        {
            b[a-'A']++;
        }
    }
    scanf("%c", &a);

    for(int i = 0; i < 26; i++)
    {
        if(b[i]) printf("%c %d\n", i+'a', b[i]);
    }


    return 0;
}