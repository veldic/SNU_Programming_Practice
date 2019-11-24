#include <stdio.h>
#include <limits.h>

char unpack(int p, int k){
    int n = k * CHAR_BIT;
    unsigned mask = 255;

    mask <<= n;
    return ((p&mask) >> n);
}

int pack(char a, char b, char c, char d){
    int p = a;
    p = (p << CHAR_BIT) | b;
    p = (p << CHAR_BIT) | c;
    p = (p << CHAR_BIT) | d;
    
    printf("%d ", p);

    return p;
}

int main(){

    char input;
    scanf("%c", &input);

    if(input == 'P'){
        int n;
        scanf("%d", &n);

        char ch, w[110];
        for(int i = 0; i < n; i++){
            scanf("%c", &ch);
            if(ch == ' ') i--;
            else w[i] = ch;
        }
        
        switch(n%4){
            case 1:
                pack(0, 0, 0, w[0]);
                for(int i = 0; i < n/4; i++){
                    pack(w[4*i+1], w[4*i+2], w[4*i+3], w[4*i+4]);
                }
                break;
            case 2:
                pack(0, 0, w[0], w[1]);
                for(int i = 0; i < n/4; i++){
                    pack(w[4*i+2], w[4*i+3], w[4*i+4], w[4*i+5]);
                }
                break;
            case 3:
                pack(0, w[0], w[1], w[2]);
                for(int i = 0; i < n/4; i++){
                    pack(w[4*i+3], w[4*i+4], w[4*i+5], w[4*i+6]);
                }
                break;    
            default:
                for(int i = 0; i < n/4; i++){
                    pack(w[4*i], w[4*i+1], w[4*i+2], w[4*i+3]);
                }
                break;
        }
    }
    else{
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            unsigned a;
            scanf("%d", &a);
            for(int j = 3; j >= 0; j--){
                int cha = unpack(a, j);
                if(cha != 0) printf("%c ", cha);
            }
        }
    }

    return 0;

}