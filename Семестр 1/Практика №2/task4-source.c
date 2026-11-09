#include <stdio.h>

int main(){
   int a,n;
   printf("Введите число: \n>");
   scanf("%d", &a);
   for (n = 2; n<a && a%n != 0; n++);
   if (n == a) printf("Число %d является простым\n", a);
   else printf("Число %d не является простым\n", a);
}

