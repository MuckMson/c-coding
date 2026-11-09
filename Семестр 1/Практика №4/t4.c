#include <stdio.h>

int new_bit(int i, int a, int k){
    return i < k ? (a>>(i-k))&1 : 1;
}

int main(){
    int k = 0;
    printf("Введите k: \n");
    scanf("%d", &k);
    printf("\n");
    int a = 0;
    printf("Введите a: \n");
    scanf("%d", &a);
    printf("\n");

    int result[8*sizeof(a)] = {};
    for (int i = 8*sizeof(a)-1; i >= 0; i--){
        result[i] = new_bit(i, a, k);
    }
    for (int i = 0; i < sizeof(a)*8; i++){
        printf("%d", result[i]);
    }
}