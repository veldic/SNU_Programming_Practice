#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./lib-cross.h"

//declations of variations
int map[8][8], score, size = 4;
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
int check_game_over();
int check_fullormove(int op);
void check_clear();
void game_clear();
void setting();
void game_exit();


//main function
int main(){

    change_text_color(WHITE);

    srand(time(NULL));

    game_start();

    return 0;
}


//definition of functions
void game_start(){

    int menu = 0;

    int min = 0;
    int max = 2;

    gotoxy(4, 6 + menu * 2);

    while(1){

        screen_clear();
        
        gotoxy(0, 0);

        printf("    ----------------------------------------\n");
        printf("    |           Welcome to 2048!           |\n");
        printf("    ----------------------------------------\n");
        printf("\n\n\n");
        printf("    @ Game Start\n\n");
        printf("    @ Setting\n\n");
        printf("    @ End Game\n\n");
        printf("    Move with \'wasd\' or arrow keys | Choose with Enter \n\n");

        gotoxy(4, 6 + menu * 2);

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
            if(menu == min){
                ingame();
            }
            else if(menu == 1){
                setting();
                
            }
            else if(menu == max){
                game_exit();
            }
        }
    }
}

void game_end(){

    screen_clear();

    for(int time = 10; time > 0; time--){
        
        gotoxy(0, 6);
        printf("Game will be closed in %d...", time);
        gotoxy(0, 0);
        printf(".-.-. .-.-. .-.-. .-.-.      .-.-. .-.-. .-.-. .-.-.  \n'. G )'. a )'. m )'. e ).-.-.'. O )'. v )'. e )'. r ) \n  ).'   ).'   ).'   ).' '._.'  ).'   ).'   ).'   ).'  \n                                                      \n");
        msleep(500);
        gotoxy(0, 0);
        printf(" .-.-. .-.-. .-.-. .-.-.      .-.-. .-.-. .-.-. .-.-. \n( G .'( a .'( m .'( e .'.-.-.( O .'( v .'( e .'( r .' \n `.(   `.(   `.(   `.(  '._.' `.(   `.(   `.(   `.(   \n                                                      \n");
        msleep(500);
    }
    
    exit(EXIT_SUCCESS);

}

void put_2(){

    int a, b;
    
    while(1){
        a = rand()%size;
        b = rand()%size;

        if(map[a][b] == 0){
            map[a][b] = 2;
            break;
        }

    }

}

void rotate(){
    int temp[8][8];

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[size-1-j][i] = map[i][j];
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            map[i][j] = temp[i][j];
        }
    }
}

void move(){
 
    //merge sequence
    for(int i = 0; i < size; i++){
        int check = 0;
        for(int j = 1; j < size; j++){
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
    for(int i = 0; i < size; i++){
        for(int j = 1; j < size; j++){
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

    
}

void print(){
    
    screen_clear();

    gotoxy(0, 0);

    printf("-");
    for(int i = 0; i < size; i++) printf("------");
    printf("\n");
    
    for(int i = 0; i < size; i++){              //row

        printf("|");
        for(int j = 0; j < size; j++) printf("     |");
        printf("\n");

        printf("|");
        for(int j = 0; j < size; j++){
            switch(map[i][j]){
                case 0:
                    change_text_color(WHITE);
                    break;
                case 2:
                    change_text_color(BLUE);
                    break;
                case 4:
                    change_text_color(RED);
                    break;
                case 8:
                    change_text_color(YELLOW);
                    break;
                case 16:
                    change_text_color(GREEN);
                    break;
                case 32:
                    change_text_color(DARK_SKY_BLUE);
                    break;
                case 64:
                    change_text_color(DARK_RED);
                    break;
                case 128:
                    change_text_color(SKY_BLUE);
                    break;
                case 256:
                    change_text_color(VIOLET);
                    break;
                case 512:
                    change_text_color(DARK_YELLOW);
                    break;
                case 1024:
                    change_text_color(DARK_GREEN);
                    break;
                case 2048:
                    change_text_color(DARK_BLUE);
                    break;
            }
            printf("%5d", map[i][j]);
            
            change_text_color(WHITE);
            printf("|");
            
        } 
        printf("\n");

        printf("|");
        for(int j = 0; j < size; j++) printf("     |");
        printf("\n");

        printf("-");
        for(int i = 0; i < size; i++) printf("------");
        printf("\n");

    }

    printf("Score : %d", score);



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

    map[0][0] = 2;

    hide_cursor();

    while(1){

        print();

        int ch = get_input();
        int move;
        
        if(ch == 'w' || ch == 'a' || ch == 's' || ch == 'd'){
            move = check_fullormove(ch);
            move_rotate(ch);
        }

        check_clear();

        if(!move) put_2();

        check_game_over();

    }
}

int check_game_over(){

    int temp[8][8], notend = 0;


    
    for(int l = 0; l < 4; l++){                 //l is not related in size, related in 4 direction "wasd"

        for(int i = 0; i < size; i++){                 
            for(int j = 0; j < size; j++){
                temp[i][j] = map[i][j];
            }
        }

        for(int i = 0; i < size; i++){             //same as merge sequence
            int check = 0;
            for(int j = 1; j < size; j++){
                if(temp[i][j] == 0) continue;
                else{
                    for(int k = j-1; k >= check; k--){
                        if(temp[i][k] == temp[i][j]){
                            temp[i][j] *= 2;
                            temp[i][k] = 0;
                            check = j+1;
                        }
                        else if(k == check){
                            check = j;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < size; i++){
            for(int j = 1; j < size; j++){

                int many0 = 0;

                for(int k = j-1; k >= 0; k--){
                    if(temp[i][k] == 0) many0++;
                    else break;
                }

                if(many0 > 0){
                    temp[i][j-many0] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(temp[i][j] == 0) notend++;
            }
        }

        rotate();

    }
    
    if(!notend) game_end();
}

int check_fullormove(int op){

    int temp[8][8], notend = 0, notfull = 0, notmove = 1;


    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(map[i][j] == 0) notfull = 1;
        }
    }
    
    for(int l = 0; l < 4; l++){                 //l is not related in size, related in 4 direction "wasd"

        for(int i = 0; i < size; i++){                 
            for(int j = 0; j < size; j++){
                temp[i][j] = map[i][j];
            }
        }

        for(int i = 0; i < size; i++){             //same as merge sequence
            int check = 0;
            for(int j = 1; j < size; j++){
                if(temp[i][j] == 0) continue;
                else{
                    for(int k = j-1; k >= check; k--){
                        if(temp[i][k] == temp[i][j]){
                            temp[i][j] *= 2;
                            temp[i][k] = 0;
                            check = j+1;
                        }
                        else if(k == check){
                            check = j;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < size; i++){
            for(int j = 1; j < size; j++){

                int many0 = 0;

                for(int k = j-1; k >= 0; k--){
                    if(temp[i][k] == 0) many0++;
                    else break;
                }

                if(many0 > 0){
                    temp[i][j-many0] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
        
        if(op == 'a' && l == 0){

            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(temp[i][j] != map[i][j]) notmove = 0;
                }
            }
        }
        else if(op == 'w' && l == 1){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(temp[i][j] != map[i][j]) notmove = 0;
                }
            }
        }
        else if(op == 'd' && l == 2){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(temp[i][j] != map[i][j]) notmove = 0;
                }
            }
        }
        else if(op == 's' && l == 3){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(temp[i][j] != map[i][j]) notmove = 0;
                }
            }
        }

        rotate();

    }
    
    if(!notfull || notmove) return 1;
    else return 0;
}

void check_clear(){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(map[i][j] == 2048){
                game_clear();
            }
        }
    }
}

void game_clear(){


    screen_clear();

    gotoxy(0, 8);

    printf("-");
    for(int i = 0; i < size; i++) printf("------");
    printf("\n");
    
    for(int i = 0; i < size; i++){              //row

        printf("|");
        for(int j = 0; j < size; j++) printf("     |");
        printf("\n");

        printf("|");
        for(int j = 0; j < size; j++){
            switch(map[i][j]){
                case 0:
                    change_text_color(WHITE);
                    break;
                case 2:
                    change_text_color(BLUE);
                    break;
                case 4:
                    change_text_color(RED);
                    break;
                case 8:
                    change_text_color(YELLOW);
                    break;
                case 16:
                    change_text_color(GREEN);
                    break;
                case 32:
                    change_text_color(DARK_SKY_BLUE);
                    break;
                case 64:
                    change_text_color(DARK_RED);
                    break;
                case 128:
                    change_text_color(SKY_BLUE);
                    break;
                case 256:
                    change_text_color(VIOLET);
                    break;
                case 512:
                    change_text_color(DARK_YELLOW);
                    break;
                case 1024:
                    change_text_color(DARK_GREEN);
                    break;
                case 2048:
                    change_text_color(DARK_BLUE);
                    break;
            }
            printf("%5d", map[i][j]);
            
            change_text_color(WHITE);
            printf("|");
            
        } 
        printf("\n");

        printf("|");
        for(int j = 0; j < size; j++) printf("     |");
        printf("\n");

        printf("-");
        for(int i = 0; i < size; i++) printf("------");
        printf("\n");

    }

    printf("Score : %d", score);

    for(int time = 10; time > 0; time--){
        
        gotoxy(0, 6);
        printf("Game will be closed in %d...", time);
        gotoxy(0, 0);
        printf(".-.-. .-.-. .-.-. .-.-.      .-.-. .-.-. .-.-. .-.-. .-.-. .-.-.  \n'. G )'. a )'. m )'. e ).-.-.'. C )'. l )'. e )'. a )'. r )'. ! ) \n  ).'   ).'   ).'   ).' '._.'  ).'   ).'   ).'   ).'   ).'   ).'  \n                                                                  \n");
        msleep(500);
        gotoxy(0, 0);
        printf(" .-.-. .-.-. .-.-. .-.-.      .-.-. .-.-. .-.-. .-.-. .-.-. .-.-. \n( G .'( a .'( m .'( e .'.-.-.( C .'( l .'( e .'( a .'( r .'( ! .' \n `.(   `.(   `.(   `.(  '._.' `.(   `.(   `.(   `.(   `.(   `.(   \n                                                                  \n");
        msleep(500);
    }

    exit(EXIT_SUCCESS);

}

void setting(){

    screen_clear();
    gotoxy(0, 0);

    int menu = 0;

    int min = 0;
    int max = 1;

    printf("    ----------------------------------------\n");
    printf("    |               Setting!               |\n");
    printf("    ----------------------------------------\n");
    printf("\n\n\n");
    printf("    @ Change Board Size (Now : %d )\n\n", size);
    printf("    @ Return to Main Menu\n\n");

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
            if(menu == min){
                hide_cursor();
                gotoxy(6, 6 + menu * 2);
                printf("Press Number between 4 ~ 8           ");
                while(1){
                    int size_input = get_input()-'0';
                    if(size_input >= 4 && size_input <= 8){
                        size = size_input;
                        gotoxy(6, 6 + menu * 2);
                        printf("Change Board Size (Now : %d )         ", size);
                        gotoxy(4, 6 + menu * 2);
                        show_cursor();
                        break;
                    }
                }
            }
            else if(menu == max){
                return;
            }
        }
    }

}

void game_exit(){
    screen_clear();
    gotoxy(0, 0);

    printf("    Thank you for playing!");
    msleep(3000);

    exit(EXIT_SUCCESS);
}