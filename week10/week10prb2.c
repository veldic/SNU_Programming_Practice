#include <stdio.h>

int max(int *a, int n){
    int end = 0, far = 0;

    for(int i = 0; i < n; i++){

        if(end + a[i] > 0) end += a[i];
        else end = 0;

        if(far < end) far = end;

    }
    return far;
}


int main(){

    int n, a[1010];
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("%d", max(a, n)>=0?max(a, n):0);

    return 0;
}