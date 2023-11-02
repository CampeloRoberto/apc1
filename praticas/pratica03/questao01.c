/* faça um programa que determnine se um numero inteiro lido e par ou impar*/

#include <stdio.h>


int main ()
{
int num;
int num_par;
int num_impar;
  

printf("\ndigite o um número inteiro: ");
scanf("%i",&num);

  
num_par = num % 2 == 0;
num_impar = num %2 != 0; 
  
if (num_par){
printf("O número %i é par.\n",num);  
} 
else {
printf("O número %i é impar.\n",num);
}
  
/*if (num_impar){
printf("O número %i é impar.\n",num);  
} */
  


  return 0;
}