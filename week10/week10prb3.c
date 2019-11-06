#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[31];
    char id[11];
    int score;
}stud;

void sortN(stud *c);
void sortI(stud *c);
void sortS(stud *c);

int n;

int main(){

    char input;
    scanf("%d", &n);

    stud a[30];

    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %d", a[i].name, a[i].id, &a[i].score);
    }    

    scanf("%c", &input);
    scanf("%c", &input);

    switch(input){
        case 'N':
            sortN(a);
            break;
        case 'I':
            sortI(a);
            break;
        case 'S':
            sortS(a);
            break;
        default:
            break;
    }

    return 0;
}

void sortN(stud *c){
    stud* b[n];

    for(int i = 0; i < n; i++)
    {
        b[i]=&c[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(strcmp((b[j])->name, (b[j+1])->name) > 0)
            {
                stud *temp;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%s %s %d\n", (b[i])->name, (b[i])->id, (b[i])->score);
    }

}

void sortI(stud *c){
    stud* b[n];
    
    for(int i = 0; i < n; i++)
    {
        b[i]=&c[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(strcmp((b[j])->id, (b[j+1])->id) > 0)
            {
                stud *temp;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%s %s %d\n", (b[i])->name, (b[i])->id, (b[i])->score);
    }

}

void sortS(stud *c){
     stud* b[n];
    
    for(int i = 0; i < n; i++)
    {
        b[i]=&c[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if((b[j]->score<b[j+1]->score))
            {
                stud *temp;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%s %s %d\n", (b[i])->name, (b[i])->id, (b[i])->score);
    }

}