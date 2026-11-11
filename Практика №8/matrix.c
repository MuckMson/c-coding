#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int N = 1024;

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
        A[i] = malloc(N*sizeof(double));
        B[i] = malloc(N*sizeof(double));
        BT[i] = malloc(N*sizeof(double));
        result[i] = malloc(N*sizeof(double));
        for (int j = 0; j < N; j++){
            A[i][j] = rand()%1000;
            B[i][j] = rand()%1000;
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
    double res=0;
    for(int i = 0; i<N; i++){
        res += A[i]*B[i];
    }
    return res;
}

void smart_multiply(double **A, double **B){
    for(int r = 0; r < N; r++){
        for(int c = 0; c<N; c++){
            result[r][c] = scalar(A[r], B[c]);
        }
    }
}
void foolish_multiply(double **A, double **B){
    for(int i = 0; i < N; i++){
        for(int j = 0;j<N; j++){
            for(int k=0; k<N; k++){
                result[i][j] += A[i][j]*B[i][j];
            }
        }
    }
}

double elapsed_ms(struct timespec a, struct timespec b){
    return (b.tv_sec - a.tv_sec)*1000.0 + (b.tv_nsec - a.tv_nsec)/1e6; // i have no idea wtf is this 
}

int main(){
    init_matrix();
    transpose();

    struct timespec foolish_start, foolish_end;
    clock_gettime(CLOCK_MONOTONIC, &foolish_start);
    foolish_multiply(A,B);
    clock_gettime(CLOCK_MONOTONIC, &foolish_end);
    double foolish = elapsed_ms(foolish_start, foolish_end);

    struct timespec smart_start, smart_end;
    clock_gettime(CLOCK_MONOTONIC, &smart_start);
    smart_multiply(A,BT);
    clock_gettime(CLOCK_MONOTONIC, &smart_end);
    double smart = elapsed_ms(foolish_start, foolish_end);


    printf("FOOL: %lf\nSMART: %lf", foolish, smart);

    free(A);
    free(B);
    free(BT);
    free(result);
}