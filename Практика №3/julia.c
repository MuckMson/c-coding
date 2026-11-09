#include <stdio.h>
#include <complex.h>
#define WIDTH 300
#define HEIGHT 80

#define ITERATIONS 200

int JuliaIter(double complex z, double complex c){
    int takenIters = -1;
    double complex r = z;
    for (int i = 0; i < ITERATIONS && takenIters == -1; i++){
        r = r*r + c;
        if (cabs(r) > 2) {
            takenIters = i; break;
        }
    }
    return takenIters;
}


int main(){

    for (double ca = -0.8, ci = -0.8; ; ){
        ca+= 0.00004; ci += 0.00015;
        double complex c = ca + ci*I;
        for (double cy = HEIGHT; cy > -1*HEIGHT; cy--){
            for (double cx = -1*WIDTH; cx<WIDTH; cx++){
                double x = cx/170;
                double y = cy/90;
                double complex z = x + y*I;
                int takenIters = JuliaIter(z, c);

                char stp;
                if (takenIters == -1){stp = ' ';}
                else if (takenIters < 30)       {stp = ' ';}
                else if (takenIters <= 50) stp = '.';
                else if (takenIters < 80)  stp = ';';
                else if (takenIters < 110) stp = 'o';
                else if (takenIters < 140) stp = '*';
                else if (takenIters < 170) stp = '#';
                else if (takenIters < 200) stp = '@';
                else                       {stp = ' ';}

                printf("%c", stp);
            }
            printf("\n");
        }

        printf("\033[H");
        
    }
}