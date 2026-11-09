#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(){
    double re[N];
    double im[N];
    for (int i = 0 ; i<N; i++){
        printf("Число %d действ. часть:", i+1);
        scanf("%lf", &re[i]);
        printf("\n");
        printf("Число %d минмая часть:", i+1);
        scanf("%lf", &im[i]);
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i<N; i++){
        printf("s[%d] = %.1lf + i * (%.1lf)", i, re[i], im[i]);
        printf("\n");
    }

    double E = 0;
    for (int k = 0; k<=N; k++){
        E += (re[k]*re[k]) - (im[k]*im[k]);
    }
    printf("E = %.2lf", E);
    int maxID=0; 
    for (int i= 0; i<N; i++){
        maxID = re[i] > re[maxID] ? i : maxID;
    }
    
    printf("\n");
    printf("Макс. элемент ID: %d\nМакс. элемент: s[%d] = %.1lf + i * (%.1lf)", maxID, maxID, re[maxID], im[maxID]);
    printf("\n");
    return 0;
}