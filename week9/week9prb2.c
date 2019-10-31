#include <stdio.h>

/*void move(char from, int to, int left, int n)
{
    if(n != 1)
    {
        if(n%2 == 1)
        {
            move(from, left, to, n-1);
            move(from, to, left, 1);
            move(left, to, from, n-1)
        }
        else
        {
            move(from, left, to, n-1);
            move(from, to, left, 1);
            move(left, to, from, n-1);
        }
        
    }
    else
    {
        printf("Move from %c to %c\n", from, to);
    }
    
}*/

void move(char from, int to, int left, int n)
{
    if(n != 1)
    {
        move(from, left, to, n-1);
        move(from, to, left, 1);
        move(left, to, from, n-1);
    }
    else
    {
        printf("Move from %c to %c\n", from, to);
    }
    
    
}

int main(){

    int n;
    scanf("%d", &n);

    move('A', 'C', 'B', n);

    return 0;

}