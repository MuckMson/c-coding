#include <stdio.h>
#include <math.h>

int result[11] = {};
void OCT(int a){
    int len = (8*sizeof(a)+2)/3; 
    for (int i = len-1; i>=0; i--){
        result[i] = (a>>(i*3))&7;
    }
}

int main(){

    int a = 8;
    OCT(a);
    for (int i = 10; i >= 0; i--){
        printf("%d", result[i] );
    }

}