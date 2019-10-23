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

    char a[3010], b[3010];
    int lenA, lenB, count = 0;
    int pos[3010];
    
    readline(a, 3010);
    readline(b, 3010);
    

    lenA = strlen(a);
    lenB = strlen(b);


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
    
    printf("%s : %d\n", b, count);
    for(int i = 0; i < count; i++)
    {
        printf("%d ", pos[i]);
    }


    return 0;
}