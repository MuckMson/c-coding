#include <stdio.h>
#include <math.h>

#define PI 3.14159


int main(){
   for (double t = 0; ; t+=0.005){
   for (int y = 20; y > -20; y--){
      for (int x = -150; x < 159; x++){
         if (x == 0) printf("|");
	      if (y == 0) printf("-");
         double localX = (x*(3.14159/180)+t)*PI;
         double fx = round(5*sin(localX));
         //double gx = round(8*sin(localX)*pow(2.71828, -0.03*localX));
         if (y == fx && x != 0 && y != 0) printf("[\033[31m#");
         else if (x != 0 && y != 0) printf(" ");
         //if (y == gx && x != 0 && y != 0) printf("[\033[34m#");
         //else if (x != 0 && y != 0) printf(" ");
      }
      printf("\n");
   }
   printf("\033[H");
   //printf("\033[2J\033[1;1H");
  }
}

