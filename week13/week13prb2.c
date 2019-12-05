#include <stdio.h>

int main(){

    int n, cube[100][6];
    int ans[6];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d %d %d", &cube[i][0], &cube[i][1], &cube[i][2], &cube[i][3], &cube[i][4], &cube[i][5]);
    }

    for(int i = 0; i < 6; i++){
        ans[i] = cube[0][i];
    }

    // for(int i = 1; i < n; i++){
    //     int temp1 = 0, temp2 = 0, temp3 = 0;

    //     if(cube[i][0] >= ans[0] && cube[i][0] <= ans[3]) temp1 = 1;
    //     if(cube[i][1] >= ans[1] && cube[i][1] <= ans[4]) temp2 = 1;
    //     if(cube[i][2] >= ans[2] && cube[i][2] <= ans[5]) temp3 = 1;

    //     if(temp1&&temp2&&temp3){
    //         ans[0] = cube[i][0];
    //         ans[1] = cube[i][1];
    //         ans[2] = cube[i][2];
    //     }

    //     temp1 = 0;
    //     temp2 = 0;
    //     temp3 = 0;

    //     if(cube[i][3] <= ans[3] && cube[i][3] >= ans[0]) temp1 = 1;
    //     if(cube[i][4] <= ans[4] && cube[i][4] >= ans[1]) temp2 = 1;
    //     if(cube[i][5] <= ans[5] && cube[i][5] >= ans[2]) temp3 = 1;

    //     if(temp1&&temp2&&temp3){
    //         ans[3] = cube[i][3];
    //         ans[4] = cube[i][4];
    //         ans[5] = cube[i][5];
    //     }

    // }
    
    for(int i = 1; i < n; i++){

        if(cube[i][0] >= ans[0] && cube[i][0] <= ans[3]) ans[0] = cube[i][0];
        if(cube[i][1] >= ans[1] && cube[i][1] <= ans[4]) ans[1] = cube[i][1];
        if(cube[i][2] >= ans[2] && cube[i][2] <= ans[5]) ans[2] = cube[i][2];
        if(cube[i][3] <= ans[3] && cube[i][3] >= ans[0]) ans[3] = cube[i][3];
        if(cube[i][4] <= ans[4] && cube[i][4] >= ans[1]) ans[4] = cube[i][4];
        if(cube[i][5] <= ans[5] && cube[i][5] >= ans[2]) ans[5] = cube[i][5];

    }


    
    if(n == 0) printf("0");
    else printf("%d", (ans[3]-ans[0])*(ans[4]-ans[1])*(ans[5]-ans[2]));


    return 0;
}