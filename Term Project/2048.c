#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./lib-cross.h"


//declations of variations
int map[4][4], score, size;
char op;


//declation of functions
void game_start();
void game_end();
void rotate();
void move();
void move_rotate(int op);
void print();
int get_input();
void ingame();
void game_over();



//main function
int main(){

    change_text_color(11);

    map[0][0] = 2;

    srand(time(NULL));

    game_start();

    return 0;
}


//definition of functions
void game_start(){

    int menu = 0;

    const int min = 0;
    const int max = 1;


    screen_clear();

    gotoxy(0, 0);

    printf("----------------------------------------\n");
    printf("|           Welcome to 2048!           |\n");
    printf("----------------------------------------\n");
    printf("\n\n\n");
    printf("    @ Game Start\n\n");
    printf("    @ End Game\n\n");
    printf("    Move with \'wasd\' and choose with Enter!\n\n");

    gotoxy(4, 6 + menu * 2);

    while(1){
        int input;

        input = get_input();
        if(input == 'w'){
            if(menu != min){
                menu--;
                gotoxy(4, 6 + menu * 2);
            }
        }
        else if(input == 's'){
            if(menu != max){
                menu++;
                gotoxy(4, 6 + menu * 2);
            }
        }
        else if(input == 0x1B){             //input ESC
            menu = max;
            gotoxy(4, 6 + menu * 2);
        }
        else if(input == 0x0A || input == 0x0D){    //input ENTER
            if(menu == 0){
                ingame();
            }
            else if(menu == 1){
                game_end();
            }
        }
    }
}

void game_end(){

    screen_clear();
    gotoxy(0, 0);
    printf("\n    Thank you for Playing!\n");
    exit(EXIT_SUCCESS);

}

void put_2(){

    int a, b;
    
    while(1){
        a = rand()%4;
        b = rand()%4;

        if(map[a][b] == 0){
            map[a][b] = 2;
            break;
        }

    }

}

void rotate(){
    int temp[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp[3-j][i] = map[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            map[i][j] = temp[i][j];
        }
    }
}

void move(){
 
    //merge sequence
    for(int i = 0; i < 4; i++){
        int check = 0;
        for(int j = 1; j < 4; j++){
            if(map[i][j] == 0) continue;
            else{
                for(int k = j-1; k >= check; k--){
                    if(map[i][k] == map[i][j]){
                        map[i][j] *= 2;
                        map[i][k] = 0;
                        check = j+1;
                        score += map[i][j];
                    }
                    else if(k == check){
                        check = j;
                    }
                }
            }
        }
    }

    //move sequence
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 4; j++){
            int many0 = 0;
            for(int k = j-1; k >= 0; k--){
                if(map[i][k] == 0) many0++;
                else break;
            }
            if(many0 > 0){
                map[i][j-many0] = map[i][j];
                map[i][j] = 0;
            }
      
        }
            
    }

}

void move_rotate(int op){

    switch(op){
        case 'a':
            move();
            break;
        case 's':
            rotate();
            rotate();
            rotate();
            move();
            rotate();
            break;
        case 'd':
            rotate();
            rotate();
            move();
            rotate();
            rotate();
            break;
        case 'w':
            rotate();
            move();
            rotate();
            rotate();
            rotate();
            break;
    }

    put_2();
    
}

void print(){
    
    screen_clear();

    gotoxy(0, 0);

    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", map[0][0], map[0][1], map[0][2], map[0][3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", map[1][0], map[1][1], map[1][2], map[1][3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", map[2][0], map[2][1], map[2][2], map[2][3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("|     |     |     |     |\n");
    printf("|%5d|%5d|%5d|%5d|\n", map[3][0], map[3][1], map[3][2], map[3][3]);
    printf("|     |     |     |     |\n");
    printf("-------------------------\n");
    printf("Score: %d\n", score);



}

int get_input(){

    int ch = getch();

    if(ch == 0xE0){
        ch = getch();
        
        switch(ch){
            case 72:
                return 'w';
                break;
            case 75:
                return 'a';
                break;
            case 77:
                return 'd';
                break;
            case 80:
                return 's';
                break;
            default:
                return 0;
                break;
        }
    }
    else return ch;


}

void ingame(){

    while(1){

        print();

        int ch = get_input();
        
        if(ch == 'w' || ch == 'a' || ch == 's' || ch == 'd'){
            move_rotate(ch);
        }
    }
}

void game_over(){

    int temp[4][4], notend = 0;

    for(int i = 0; i < 4; i++){                 
        for(int j = 0; j < 4; j++){
            temp[i][j] = map[i][j];
        }
    }

    for(int l = 0; l < 4; l++){                 //i is not related in size, related in 4 direction "wasd"
        for(int i = 0; i < 4; i++){             //same as merge sequence
            int check = 0;
            for(int j = 1; j < 4; j++){
                if(map[i][j] == 0) continue;
                else{
                    for(int k = j-1; k >= check; k--){
                        if(map[i][k] == map[i][j]){
                            map[i][j] *= 2;
                            map[i][k] = 0;
                            check = j+1;
                            score += map[i][j];
                        }
                        else if(k == check){
                            check = j;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(temp[i][j] == 0) notend++;
            }
        }

    }

    if(!notend) game_end();

    
}