// Faça um programa em C que calcule a média final a partir da fórmula (0,4 x A1) + (0,6 x A2). Considere A1 e A2 números reais entre 0 a 10.


#include<stdio.h>

int main()

{
float nota1, nota2;


  printf("digite a primeira nota\n");
  scanf("%f",&nota1);

  printf("digite a segunda nota\n");
  scanf("%f",&nota2);

  float mediafinal = (nota1 * 0.4)+ (nota2 * 0.6);


  printf("Sua nota= %.2f\n",mediafinal);
  
  return 0;
}