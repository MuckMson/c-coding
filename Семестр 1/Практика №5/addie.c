#include <stdio.h>
#define N 4



int main(){
    int canvas[N][N] = {0};
    int dx[] = {1, 0, -1, 0};   // вправо, вниз, влево, вверх
    int dy[] = {0, 1, 0, -1};
    int x = 0, y = 0, d = 0;


    for (int n = 1; n <= N*N; n++){
        canvas[x][y] = n;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || canvas[nx][ny] != 0){
            d = (d + 1) % 4;        // поворот
            nx = x + dx[d];
            ny = y + dy[d];
        }
        x = nx;
        y = ny;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%5d", canvas[j][i]);
        }
        printf("\n");
    }
    return 0;
}