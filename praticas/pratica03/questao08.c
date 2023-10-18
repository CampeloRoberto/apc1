/* Faça um programa em C que calcule o fatorial de um número inteiro.*/

#include <stdio.h>

int main ()
{
  int num;
  int i;
  int fatorial = 1;
  

  printf("digite um número inteiro: ");
int certo = scanf ("%i",&num);

  printf(" o valor de %i!\n",num);
  
for (i = 0; i < num ; i++)
{
  fatorial = fatorial* (num - i);
  
 
    
}
   printf("O valor de %i ! = %i",num,fatorial);



  return 0;
  
}