#include <stdio.h>

int array_cmp(int num, int *A, int *B)
{
    for(int i = 0; i < num; i++)
    {
        if(A[i] == B[i]) continue;
        else if(A[i]>B[i]) return 1;
        else return -1;
    }
    return 0;
}

int main(){

    int num;
    scanf("%d", &num);

    int arr1[num];
    int arr2[num];

    for(int i = 0 ; i < num; i++)
    {
        scanf("%d", arr1+i);
    }

    for(int i = 0 ; i < num; i++)
    {
        scanf("%d", arr2+i);
    }

    printf("%d\n", array_cmp(num, arr1, arr2));

    return 0;
}