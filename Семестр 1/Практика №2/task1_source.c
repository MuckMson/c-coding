#include <stdio.h>

int main(){
   int n1,n2;
   int i;
   printf("Введите значения для поиска НОД: \n>");
   scanf("%d %d", &n1, &n2);
   for(i = n1; !(n1%i == 0 && n2%i == 0); i--){}
   printf("НОД(%d %d) = %d\n", n1, n2,i);
}
