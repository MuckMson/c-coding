#include <stdio.h>

int main(){
   int inp = 0;
   printf("Введите номер года: ");
   scanf("%d", &inp);
   printf("\n");
   
   if (inp % 400 == 0) printf("YES\n");
   else if (inp % 100 != 0 && inp % 4 == 0) printf("YES\n");
   else printf("NO\n");

  return 0;
}
