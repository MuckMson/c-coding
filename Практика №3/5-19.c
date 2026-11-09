#include <stdio.h>




int main(){
   char lets[] = {'A','B','C','D','E','F','G'};
   for (int cycle = 0; cycle < 2; cycle++){
      for (int i = 3; i >= 0; i--){
         int space = ((7-(2*i+1))/2); 
         for (int l = 0 ; l < 7; l++){
	     if (l < space || l >= 7 - space) printf(" ");
             else {
	        printf("%c", lets[l]);
	     }
         }
         printf("\n");
      }
   }
}
