#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int N = 128;

void STATUS(int id){
    int panic = 0;
    switch(id){
        case 0:
            printf("Program finished execution.");
        break;
        case 1:
            printf("ERR: Unable to allocate memory, returned NULL pointer."); panic = 1;
            break;
    }
    if(panic) printf("PANIC: We're hanging here...");
}

double **A, **B;
double **BT;

double **result;

int init_matrix(){
    srand((unsigned)time(NULL));
    A = malloc(N*sizeof(*A));
    B = malloc(N*sizeof(*B));
    BT = malloc(N*sizeof(*B));
    result = malloc(N*sizeof(*result));
    if (A == NULL || B == NULL || BT == NULL || result == NULL) {STATUS(1); return 1;}
    for (int i = 0; i < N; i++){
        A[i] = malloc(N*sizeof(**A));
        B[i] = malloc(N*sizeof(**B));
        BT[i] = malloc(N*sizeof(**BT));
        result[i] = malloc(N*sizeof(N));
        for (int j = 0; j < N; j++){
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
        }
    }
    return 0;
}

void transpose(){
    for(int i = 0; i < N; i++){
        for (int j = 0; j< N; j++){
            BT[j][i] = B[i][j];
        }
    }
}

double scalar(double *A, double *B){
    double res;
    for(int i = 0; i<N; i++){
        res += A[i]*B[i];
    }
    return res;
}

void multiply(double **A, double **B){
    for(int r = 0; r < N; r++){
        for(int c = 0; c<N; c++){
            result[r][c] = scalar(A[r], B[c]);
        }
    }
}



int main(){
    init_matrix();
    transpose();

    int foolish_start, foolish_end, foolish;
    clock_gettime(CLOCK_MONOTONIC, &foolish_start);
    multiply(A,B);
    clock_gettime(CLOCK_MONOTONIC, &foolish_end);
    foolish = foolish_end-foolish_start;

    int smart_start, smart_end, smart;
    clock_gettime(CLOCK_MONOTONIC, &smart_start);
    multiply(A,B);
    clock_gettime(CLOCK_MONOTONIC, &smart_end);
    smart = smart_end-smart_start;

    printf("FOOL: %d\nSMART: %d", foolish, smart);

    free(A);
    free(B);
    free(BT);
}