#include <stdio.h>

int abs(int a){return a>=0 ? a : -1*a;}

int main(){
   for (int i = -7; i < 8; i+=2){
      if (i == -1) continue;
      for (int o = 0; o < abs(i); o++ ) printf("O");
   printf("\n");
   }
}
