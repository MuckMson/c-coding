#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int back_field[N][N]; // 9 – бомба, 7 – открыто, 5 – флаг бомба, 6 – флаг пусто
char field[N][N]; // lkz gj
int bombs_cnt = 0;
int flags_cnt = 0;

void draw(char target[N][N]){
    printf("      ");
    for (int help = 0; help < N; help++){
        printf("%d ", help+1);
    }
    printf("\n     ");
    for (int i = 0; i < N; i++) printf("＿");
    printf("\n");
    for (int i = 0; i < N; i++){
        printf("%2.d  | ", i+1);
        for (int j = 0; j<N; j++){
            printf("%c ", target[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void new_field(double temperature){ // temperature – сложность игры от 0 до 1, где 0 – нет мин 1 – все мины
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            back_field[i][j] = (double)rand()/RAND_MAX < temperature ? 9 : 0;
            if (back_field[i][j] == 9) bombs_cnt++;
        }
    }
}

int check_border(int i, int j){
    int cnt = 0;
    for (int k = -1; k<2; k++){
        for(int m = -1; m<2; m++){
            if (i+k > N-1 || i+k < 0 || j+m > N-1 || j+m < 0) continue;
            cnt += (back_field[i+k][j+m] == 9 || back_field[i+k][j+m] == 6)? 1 : 0;
            
        }
    }
    return cnt;
}

void render_field(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j<N; j++){
            switch(back_field[i][j]){
                case 7:
                    int bcnt = check_border(i,j);
                    field[i][j] = bcnt > 0 ? '0' + bcnt : ' ';
                    break;
                case 5:
                case 6:
                    field[i][j] = '?';
                    break;
                default:
                    field[i][j] = '.';
                    break;
            }
        }
    }
    draw(field);
}


int check_cell(int i, int j, int open){
    if (back_field[i][j] == 7 || back_field[i][j] == 5 || back_field[i][j] == 6) return 0;
    if (back_field[i][j] == 9 && open == 1) {return -1; printf("\nDEBUG: Game over.\n");}
    else if(back_field[i][j] == 9) return 0;
    int bmbs = check_border(i,j);
    if (bmbs == 0){
        field[i][j] = ' ';
    }
    back_field[i][j] = 7; // openned field;
    for (int k = -1; k<2; k++){
        for(int m = -1; m<2; m++){
            if (i+k > N || i+k < 0 || j+m > N || j+m < 0) continue;
            if(bmbs == 0) check_cell(i+k, j+m, 0);
        }
    }
    return 0;
}

int is_win(){
    int openned_cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;j++){
            if(back_field[i][j] == 7){
                openned_cnt++;
            }
        }   
    }
    return ((N*N)-openned_cnt)==bombs_cnt;
}

int main(){
    new_field(0.13);
    int ingame = 1; // -1 = lose, >0 = in game, 1 = ok, 2 = ERR: Out of Bounds, 3 = ERR: Openned FLAG; 67 = WIN
    while(ingame > 0){
        printf("\033[H\033[J");
        render_field();
        printf("mines: %d, flags: %d\n", bombs_cnt, flags_cnt); 
        switch(ingame){ // ERROR messages output
            case 2:
                printf("\nERR: Cell coords is Out of Bounds! Try again.\n");
            break;
            case 3:
                printf("\nERR: Can't flag openned cell! Try again.\n");
            break;
        }
        ingame = 1;
        printf("\nEnter target cell and action (i.e. 7 2 f): ");
        char action;
        int i,j;
        scanf("%d %d %c", &i,&j,&action);
        i--; j--;
        if (i-1 >= N || j-1 >= N || i < 0 || j < 0){ // Out of Bounds check
            ingame = 2;
        }
        switch(action){
            case 'f':
                int val = back_field[i][j];
                if (val == 5 || val == 6){
                    back_field[i][j] = val == 6 ? 9 : 0; // if BOMB FLAG set BOMB else set EMPTY
                    flags_cnt--;
                }
                else{
                    back_field[i][j] = val == 9 ? 6 : 5; // if BOMB then set BOMB FLAG else EMPTY FLAG
                    flags_cnt++;
                }
                break;
            default:
                if (check_cell(i,j,1) == -1){
                    ingame = -1;
                }
                break;
        }
        if (is_win()) ingame = -67;
        switch (ingame){
            case -1:
                printf("GAME OVER! You were blown up to smithereens!\n");
            break;
            case -67:
                printf("You successfully didn't blew yourself! Congratulations!!!");
                break;

            case 0:
            printf("The game was shut down due to unknown reason.\n");
            default:
                printf("\033[H\033[J");
                break;
        }
    }
}
