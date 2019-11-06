#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char a[25010];
    char str[510][51] = {0,};
    int len, word = 0, index[510]={0,};
    char *b[510];

    scanf("%[^\n]%*c", a);

    len = strlen(a);

    for(int i = 0; i < len; i++)
    {
        char x[51];
        int j = 0;
        for(j = 0; a[i]!=' ' && a[i]!='\0'; i++)
        {
            x[j] = a[i];
            j++;
        }
        x[j] = '\0';

        int ex = 0;
        int k;

        for(k = 0; k < word; k++)
        {
            if(!strcmp(str[k], x))
            {
                ex = 1;
                index[k]++;
                break;
            }
        }
        if(ex == 0)
        {
            strcpy(str[k], x);
            index[k]++;
            word++;
        }
    }

   for(int i = 0; i < word; i++)
   {
       b[i]=&str[i][0];
   }

   for(int i = 0; i < word; i++)
   {
       for(int j = 0; j < word-i-1; j++)
       {
           if(strcmp(b[j], b[j+1]) > 0)
           {
               char *temp;
               int tmp;
               
               temp = b[j];
               b[j] = b[j+1];
               b[j+1] = temp;

               tmp = index[j];
               index[j] = index[j+1];
               index[j+1] = tmp;
           }
       }
   }


    for(int i = 0; i < word; i++)
    {
        printf("%s %d\n", b[i], index[i]);
    }

    return 0;
}