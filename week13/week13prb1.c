#include <stdio.h>

int checkOut(int low, int high){
    return low < high ?1:0;
}

int main(){

    int x11, y11, x12, y12;
    int x21, y21, x22, y22;

    int result = 0;

    scanf("%d %d %d %d", &x11, &y11, &x12, &y12);
    scanf("%d %d %d %d", &x21, &y21, &x22, &y22);
    

    result = checkOut(x22, x11)||checkOut(x12, x21)||checkOut(y22, y11)||checkOut(y12, y21);

    if(result) printf("No");
    else printf("Yes");

    return 0;

}