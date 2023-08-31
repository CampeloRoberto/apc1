
// calcule a area e um triangulo a= (b*h) /2; Atente-se para variáveis d0o tipo float caso a divisão seja numero impar/2

#include<stdio.h>

int main()

{
float base, altura;


  printf("digite o valor da base\n");
  scanf("%f",&base);

  printf("digite o valor da altura\n");
  scanf("%f",&altura);

  float area = (base * altura)/2; // ou divide por 2.0f;;


  printf("Sua nota= %.2f\n",area);
  
  return 0;
}