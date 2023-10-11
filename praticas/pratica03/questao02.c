/* Faça um programa em C que calcule o valor do desconto sobre um valor bruto lido com base na escala: até de 100.00 aplica 1%; de 100.01 a 500.00 aplica 5%; acima de 500.00 aplica 10%?*/

#include <stdio.h>

int main ()
{
int leu_certo;
float num;
 printf(" Digite um numero qualquer positivo: ");
 leu_certo = scanf("%f",&num); // essa variável recebe o valor lido e verifica se ela pode virar um float. Ou seja, vai dar "else" com char e com string

  
 if(leu_certo > 0 && num > 0) // aqui ele cumpre ser uma variável float positiva 
 {
if (num<= 100.0)
{
num = num *0.01;

  printf ("O valor do desconto é: %.2f\n",num);
}

  if (num > 100.1  && num <= 500.) 
  {
    num = num * 0.05;
    printf ("O valor do desconto é: %.2f\n",num);
  }
  
if (num > 500.0)
{
num = num *0.1;

  printf ("O valor do desconto é: %.2f\n",num);
}
 }
 
 if (num < 0 )
 {
   printf("Em que mundo %.2f é maior que zero seu bagre?\n",num);
 } else {
   printf("Somente números criatura \n");
   
 }
  

  return 0;
  
}