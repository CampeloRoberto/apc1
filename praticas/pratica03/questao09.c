/*Faça um programa em C que leia dez números e imprima o maior e o menor entre eles.*/

#include <stdio.h>

int main ()
{
  int i;
  int num;
  printf ("Digite um numero inteiro. \n");
  int leucerto = scanf("%i",&num);

  int maior = num;
  int menor = num;
  

  for (i = 0; i < 9; i++)
    {
     
      printf ("Digite outro numero inteiro. \n");
      int leucerto = scanf("%i",&num);
    if (num > maior){
      maior = num;
    }
     if (num<menor){
       menor = num;
     } 
    }
  printf("o maior é %i e o menor é %i \n",maior,menor);
  

  return 0;
}