#include <stdio.h>
#include <string.h>

char* readline(char* str, int max_len) {

    char* result = fgets(str, max_len, stdin);

    if (!result) { // failed

        return result;

    }

    str[strlen(str) - 1] = '\0'; // because fgets() reads with new line, remove it.
    return result;
}

int main(){

    char a[1010], b[1010], c[1010];
    int lenA, lenB, lenC, count = 0;
    int pos[1010];
    pos[0] = -1;

    scanf("%[^\n]%*c", a);
    scanf("%[^\n]%*c", b);
    scanf("%[^\n]%*c", c);

    lenA = strlen(a);
    lenB = strlen(b);
    lenC = strlen(c);

    for(int i = 0; i <= lenA-lenB; i++)
    {
        if(a[i] == b[0])
        {
            int j = 0;
            while(j < lenB && a[i+j]==b[j])
            {
                j++;
               
            }

            if(j==lenB)
            {
                pos[count] = i;
                count++; 
            }
        }
    }


    int j = 0;
    for(int i = 0; i < lenA; i++)
    {
        if(i == pos[j] && pos[0] != -1)
        {
            printf("%s", c);
            i+=lenB-1;
            while(i >= pos[j] && j < count) {
                j++;
            }
        }
        else
        {
            printf("%c", a[i]);
        }
    }


    return 0;
}