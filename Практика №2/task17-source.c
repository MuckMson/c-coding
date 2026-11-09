#include <stdio.h>

int main(){
   int b = 0, n = 2, flag = 0;
   printf("Введи число: \n>");
   scanf("%d", &b);

   while (b%n != 0){
      n++;
      if(n==b) {
         flag = 1;
         break;
      }
   }
   if (flag == 1) printf("Число %d является простым\n",b);
   else printf("Число %d не является простым\n", b);
}
