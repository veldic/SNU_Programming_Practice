#include <stdio.h>


int a[4][4], score;
char op;

void rotate();
void move_left_without_merge();
void move_without_merge(char op);
void print();



int main(){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &a[i][j]);
        }
    }

    print();

    scanf("%c", &op);
    while(scanf("%c", &op)!=EOF){
        if(op != 'a' && op != 's' && op != 'd' && op != 'w') continue;
        move_without_merge(op);
        print();
    }

    

    return 0;
}

void rotate(){
    int temp[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp[3-j][i] = a[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = temp[i][j];
        }
    }
}

void move_left_without_merge(){
 
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 4; j++){
            for(int k = 1; k < 4; k++){
                if(a[i][k-1] == 0){
                    a[i][k-1] = a[i][k];
                    a[i][k] = 0;
                }
            }
        }
    }


}
void move_without_merge(char op){


    switch(op){
        case 'a':
            move_left_without_merge();
            break;
        case 's':
            rotate();
            rotate();
            rotate();
            move_left_without_merge();
            rotate();
            break;
        case 'd':
            rotate();
            rotate();
            move_left_without_merge();
            rotate();
            rotate();
            break;
        case 'w':
            rotate();
            move_left_without_merge();
            rotate();
            rotate();
            rotate();
            break;
    }
    
}

void print(){
    
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", a[0][0], a[0][1], a[0][2], a[0][3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", a[1][0], a[1][1], a[1][2], a[1][3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", a[2][0], a[2][1], a[2][2], a[2][3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", a[3][0], a[3][1], a[3][2], a[3][3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("Score: %d\n", score);

}