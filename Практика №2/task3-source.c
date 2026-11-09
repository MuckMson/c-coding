#include <stdio.h>

int main(){
   printf("Введите число:\n>");
   int a,n;
   scanf("%d", &a);
   for (n=2; n<a; n++){
      if (a%n == 0) break;
  }
   if (n==a) printf("Число %d является простым\n", a);
   else printf("Число %d не является простым\n",a);
}
