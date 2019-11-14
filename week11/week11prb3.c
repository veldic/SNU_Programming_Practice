#include <stdio.h>

#define MAX 16

int main(){

    int a[MAX];

    for(int i = 0; i < MAX; i++){
        scanf("%d", &a[i]);
    }

    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", a[0], a[1], a[2], a[3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", a[4], a[5], a[6], a[7]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", a[8], a[9], a[10], a[11]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", a[12], a[13], a[14], a[15]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");

}