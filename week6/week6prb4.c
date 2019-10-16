#include <stdio.h>

int nth_largest(int _size, int _N, int* _arr)
{
    for(int i = _size; i > 0; i--)
    {
        for(int j = 0; j < i-1; j++)
        {
            if(_arr[j]>_arr[j+1])
            {
                int temp = _arr[j+1];
                _arr[j+1] = _arr[j];
                _arr[j] = temp;
            }
        }
    }
    return _arr[_size-_N];
}

int main(){

    int size = 0;
    int N = 0;
    int arr[200];

    scanf("%d", &size);
    scanf("%d", &N);
    if(N>size)
        printf("Wroooong Input");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", nth_largest(size, N, arr));
    return 0;



}