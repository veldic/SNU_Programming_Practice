#include <stdio.h>

int binary_search(int *list, int l, int r, int to_find) {
    
    int pos = (l+r)/2;
    
    if(l == r && list[pos] == to_find) return pos;
    else if(l == r && list[pos] != to_find) return -1;

    if(list[pos] == to_find)
    {
        return pos;
    }
    else if(list[pos] > to_find)
    {
        return binary_search(list, l, pos-1, to_find);
    }
    else
    {
        return binary_search(list, pos+1, r, to_find);
    }
}

int sorted[100000000];

int main(){

    int i, N, to_find, result;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &sorted[i]);
    }
    scanf("%d", &to_find);

    result = binary_search(sorted, 0, N, to_find);

    printf("%d\n", result);


    return 0;
}