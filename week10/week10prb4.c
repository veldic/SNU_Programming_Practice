#include <stdio.h>

typedef struct{
    char name[8];
    int HP;
    int attack;
    int defence;
} Player;

void fight(Player* attacker, Player* defender);
int max(int a, int b);

int playerNum;

int main(){

    int attackNum;
    Player player[10];
    
    scanf("%d", &playerNum);

    for(int i = 0; i < playerNum; i++)
    {
        scanf("%s %d %d %d", player[i].name, &player[i].HP, &player[i].attack, &player[i].defence);
    }

    scanf("%d", &attackNum);

    for(int i = 0; i < attackNum; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(player[a].HP > 0) fight(&player[a], &player[b]);
    }

    for(int i = 0; i < playerNum; i++)
    {
        if(player[i].HP>0)
        {
            printf("%d. Player %s : %d\n", i+1, player[i].name, player[i].HP);
        }
        else
        {
            printf("%d. Player %s : %c\n", i+1, player[i].name,'X');
        }
        
    }


    return 0;
}

void fight(Player* attacker, Player* defender){

    defender->HP=defender->HP - max(1, attacker->attack - defender->defence);
}

int max(int a, int b){
    return a>b?a:b;
}