#include <math.h>
#include <stdio.h>

double muck_abs(double target){
   if(target < 0) return target*-1;
   return target;
}

int main(){
   
   double H = 600000; // m
   double v_sat = 7560; // m per second
   double f_0 = 2.18 * pow(10, 9); // hz
   double R_e = 6371000; // m 
   
   double alpha_degrees = 0; // [0, 90] degrees;
   
   printf("Enter elevation angle alpha (0..90 degrees): ");
   scanf("%lf", &alpha_degrees); printf("\n");
   if (alpha_degrees > 90 || alpha_degrees < 0){
      printf("ERROR: Angle must be between 0 and 90 degrees.\n");
      return 1;  
   } 

   double alpha = (acos(-1)/180)*alpha_degrees; // arccos(-1) = pi

   double c = 299792458; // m per second

   double d = sqrt( pow(R_e, 2) * pow(sin(alpha) ,2) + 2*R_e*H + pow(H,2)) - R_e * sin(alpha);
   double v_radial = v_sat * ((R_e * cos(alpha))/(R_e * sin(alpha) + d));
   double delta_time = (v_radial / c) * pow(10,9);
   
   double B = v_radial / c;
   double f_d = (f_0 * sqrt((1+B)/(1-B)) - f_0)/1000;

   // Calculated depending data show:
   printf("Distance: %.2lf km\n", d/1000);
   printf("Radial velocity (vr): %.2lf m/s\n", v_radial);
   printf("Time drift (dT): %.4lf ns/s\n", delta_time);
   printf("Doppler shift (fd): %.4lf kHz\n", f_d);
   // Profiles swapper logic:
   
   if ((f_d > 42 || delta_time > 18) && (d/1000) > 1000) printf("PROFILE: CRITICAL ERROR\n");
   else if (f_d > 25 && delta_time > 10) printf("PROFILE: HIGH DYNAMIC MODE\n");
   else if ( f_d > 3 || muck_abs(delta_time) > 1) printf("PROFILE: NORMAL ACCELERATION\n");
   else printf("PROFILE: ZENITH MODE\n");
   return 0;
}
