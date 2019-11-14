#include <stdio.h>

void mergeSort(int *arr, int l, int r){
    if(l != r){
        int m = (l+r)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
    
}

void merge(int *arr, int l, int m, int r){
    int left = m-l+1, right = r-m;
    int x[left], y[right];
    for(int i = 0; i < left; i++){
        x[i] = arr[l+i];
    }
    for(int i = 0; i < right; i++){
        y[i] = arr[m+1+i];
    }

    int a = 0, b = 0;
    for(int i = 0; i < r-l+1; i++){
        if(x[a]>y[b]){
            if(b < right){
                arr[i+l] = y[b];
                b++;
            }
            else{
                arr[i+l] = x[a];
                a++;
            }
        }
        else{
            if(a < left){
                arr[i+l] = x[a];
                a++;
            }
            else{
                arr[i+l] = y[b];
                b++;
            }
        }
    }
}

int main(){

    int n, a[100010] = {0,};
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}