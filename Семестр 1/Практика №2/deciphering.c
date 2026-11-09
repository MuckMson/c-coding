#include <stdio.h>
#include <math.h>

int dividers[1024];
int lai = 0; 

int p,q;
int Factorize(int n){
   for (int i = 0; i < n; i++){
      if (n%i == 0){
         dividers[lai] = i;
         lai++;
         if(lai >= 1024) return -1;
      }
   } // здесь искали все делители числа n
   
   for (int i = 0; i<lai+1; i++){
      for(int j = 0; j<lai+1; j++){
          if(dividers[i]*dividers[j] == n){
             p = dividers[i];
	     q = dividers[j];
	  }
      }
   }
   return 0;
}



int main(){
   int mods[5] = {35026003, 45222511, 55293143, 62832893, 25273609};
   int e[5] = {17,17,17,17,19};
   int cipher[5] = {4670998,3357214,49786238,43592627,8387449};

   for (int iter = 0; iter < 5; iter++){
   Factorize(mods[iter]);
   int fi = (p-1) * (q-1);
   int d;
   for (int _d = 1; _d<255656; _d++){
      if ((_d * e[iter])%fi == 1) d = _d;
   }

   long long symbPart = pow(cipher[iter],d);
   char symb = symbPart % mods[iter];
   printf("%d\n", symb);
}
   return 0;
}

