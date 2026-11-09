#include <stdio.h>

int main(){

   int a,b, n;
   printf("Введите числа для нахождения НОК::\n>");
   scanf("%d %d", &a, &b);
   printf("\n");
   for (n = a; n%a != 0 || n%b!=0; n++){}
   printf("НОК(%d; %d) = %d\n", a,b,n);
}

