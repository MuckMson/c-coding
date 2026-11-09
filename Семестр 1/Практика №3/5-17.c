#include <stdio.h>

#define X 10
int main(){
   for (int dummy=0; dummy<=1;dummy++){
      for (int i = 0; i<X; i+=1){
         for (int j = 0; j<X-i; j++) printf(" ");
         for (int j = 0; j<2*i+1; j++) printf("*");
         printf("\n");
      }
   }
}
