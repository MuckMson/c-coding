#include<stdio.h>

int max = 2147483647;
unsigned int umax = 0;
char min = -128;

int main(){ 
   max++;
   umax--;
   min--;
   printf("%d\n", max);
   printf("%u\n",umax);
   printf("%hhd\n", min);
   return 0;
}

