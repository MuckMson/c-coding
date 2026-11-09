#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 8

double FindDeterminant(double trg[N][N], int subN){

    double det = 0;
    if (subN == 1){
        return trg[0][0];
    }
    for (int col = 0; col < subN; col++){
        double submatrix[N][N] = {0};

        for (int i = 1; i < subN; i++){
            int cy = 0; // carry Y
            for(int j = 0; j < subN; j++){
                if (j == col){
                    cy -= 1;
                    continue;
                }
                submatrix[i-1][j+cy] = trg[i][j];
            }
        }
        det += trg[0][col] * (col%2 == 0 ? 1 : -1)*FindDeterminant(submatrix, subN-1);
    }
    return det;
}

int main(){

    double A[N][N] = {
        { 2,  6, -2,  3,  3,  6,  1,  6},
        { 1,  4,  4,  2,  4,  7, -2,  3},
        { 3,  6,  7, -1,  0,  5,  3,  1},
        { 7,  3,  6,  0,  7,  4,  2,  4},
        { 1,  0, -1,  2,  3,  6,  0, -2},
        {-1,  0,  2,  6, -2,  0,  5, -1},
        { 4,  5, -2,  7,  4,  4,  5, -2},
        { 3,  3,  4,  6, -2,  6, -2,  2}
    };

    double Y[N] = {22, 39, 34, 23, 3, 26, 17, 37};
    double X[N] = {0};
    double det = FindDeterminant(A,N);


    for (int i = 0; i < N; i++){
        double tmp[N][N] = {0};
        memcpy(tmp, A, sizeof(tmp));
        for (int row = 0; row < N; row++){
            tmp[row][i] = Y[row];
        }
        double tmpDet = FindDeterminant(tmp, N);

        X[i] = tmpDet/det;
        printf("x%d = %.2lf\n", i+1, X[i]);
    }

    return 0;
}