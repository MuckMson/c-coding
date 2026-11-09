#include <stdio.h>
#include <string.h>
#define SIZE 9

int sudoku[SIZE][SIZE] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 7, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

int check_rows(int trg[SIZE][SIZE], int subSIZE){
    if (subSIZE == 1) return 1;
    for (int r = 0; r<subSIZE; r++){
        int ptr[subSIZE];
        memset(ptr, 0, sizeof(ptr));
        for (int c = 0; c < subSIZE; c++){
            if (ptr[trg[r][c]-1] != 0){
                return 0;
            }
            else{
                ptr[trg[r][c]-1] = 1;
            }
        }
    }
    return 1;
}
int check_columns(){
    for (int c = 0; c<SIZE; c++){
        int ptr[SIZE] = {0};
        for (int r = 0; r < SIZE; r++){
            if (ptr[sudoku[r][c]-1] != 0){
                return 0;
            }
            else{
                ptr[sudoku[r][c]-1] = 1;
            }
        }
    }
    return 1;
}
int check_squares() {
    for (int sx = 0; sx < SIZE; sx += 3) {
        for (int sy = 0; sy < SIZE; sy += 3) {

            int seen[SIZE + 1] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int v = sudoku[sy + i][sx + j];
                    if (v == 0) continue;      // если пустые клетки допустимы
                    if (seen[v]) return 0;
                    seen[v] = 1;
                }
            }
        }
    }
    return 1;
}

int is_valid_sudoku(){
    return (check_columns() && check_rows(sudoku, SIZE) && check_squares());
}

int main(){
    if (is_valid_sudoku()){
        printf("Введёная матрица – решение судоку!\n");
    }
    else{
        printf("Введёная матрица не является решением судоку.\n");
    }
}