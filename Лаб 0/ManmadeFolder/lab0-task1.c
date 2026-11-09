#include<stdio.h>

int cage_value = 555;

int words_amount = 59;
int letters_amount = 1004;
int digits_amount = 8;

float a = 0.1f;
float b = 0.2f;
float res = 0.0f;


int main(){
    res = a+b;

    printf("|%d|\n", cage_value);
    printf("|%10d|\n", cage_value);
    printf("|%-10d|\n\n", cage_value);

    printf("Words: %8d\n", words_amount);
    printf("Letters: %6d\n", letters_amount);
    printf("Digits: %7d\n\n", digits_amount);
	
    printf("a = %.6f; ", a);
    printf("b = %.6f\n", b);
    printf("a + b = %.16f\n", res);
    return 0;
}
