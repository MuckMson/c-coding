#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    // int X[7] = {0,0,0,0,0,0,0};
    // X[0] = 1;
    // for (int k = 1; k<6; k++){
    //     X[k] = 2 * X[k-1];
    //     printf("%d\n", X[k]);
    // }

int *p = malloc(100);
free(p);
p = NULL;
free(p);

}