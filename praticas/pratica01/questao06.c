#include <stdio.h>
#include <math.h>

int main ()
{
float a;
float b;
float c;

float valor1;
float valor2;
  
printf("\ndigite o valor de  a: " );
scanf("%f",&a);

printf("\ndigite o valor de  b: " );
scanf("%f",&b);
  
printf("\ndigite o valor de  c: " );
scanf("%f",&c);
  
valor1 =  (-b + pow((pow(b,2) - 4*a*c),1/2))/2*a;
valor2 =  (-b - pow((pow(b,2) - 4*a*c),1/2))/2*a;

printf("os resultados da sua equação são %.2f e %.2f ",valor1,valor1);

  return 0;
  
}