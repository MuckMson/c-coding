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

void init_matrix(){
    srand((unsigned)time(NULL));
    A = malloc(N*sizeof(*A));
    B = malloc(N*sizeof(*B));
    BT = malloc(N*sizeof(*B));
    if (A == NULL || B == NULL) {STATUS(1); return 1;}
    for (int i = 0; i < N; i++){
        A[i] = malloc(N*sizeof(**A));
        B[i] = malloc(N*sizeof(**B));
        BT[i] = malloc(N*sizeof(**BT));
        for (int j = 0; j < N; j++){
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }
    return 0;
}

void transpose(double **trg, double **new){
    for(int i = 0; i < N; i++){
        for (int j = 0; j< N; j++){
            BT[j][i] = B[i][j];
        }
    }
}

int main(){
    init_matrix();
    transpose(B, BT);

    free(A);
    free(B);
    free(BT);
}