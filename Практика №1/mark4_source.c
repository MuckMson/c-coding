#include <stdio.h>

int main(){
   float inp_temp = 0;
   char inp_unit = 0;
   printf("Input temperature: ");
   scanf("%f%c", &inp_temp, &inp_unit);
   printf("\n");
   float out_temp = 0;
   char out_unit = 0;

   switch(inp_unit){
      case 'c':
      case 'C':
         out_unit = 'f';
         out_temp = (inp_temp * 1.8) + 32;
         break;
      case 'f':
      case 'F':
         out_unit = 'c';
         out_temp = (inp_temp - 32) / 1.8;
         break;
      default:
         printf("Output error💥\n");
	 return 1;
         break;
   }
   printf("Output temperature: %.1f%c\n", out_temp, out_unit);
   return 0;
}
