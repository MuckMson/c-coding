#include <stdio.h>
#include <math.h>

int main(){
   /* Мой вариант - 12. Я попытаюсь проверить попадание точки в треугольник
      с помощью трех линейных функций, коэффициенты которых я вычислю в
      отдельном файле mark5_solution.png */
   double x = 0;
   double y = 0;

   printf("📝 Please enter point position (e.g: 1.4 -2.0):\n> ");
   scanf("%lf %lf", &x, &y);
   printf("\nGot X: %f, Y: %f\n  ⏳Processing...\n",x,y);
   
   if ((y < (-2*x) -1) && (y > -1) && (y < x + 2)) printf("✅ YES\n");
   else printf("❌ NO\n");
   return 0;
}
