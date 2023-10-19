/* programa que vese o numero é primo ou não*/
// apenas dividido pro ele e ele mesmo, possui apenas doisdivisores.

#include <stdio.h>

int main ()
{
  int num;
  int i;
  
  printf("digite um número inteiro: ");
  int leu_certo  = scanf("%i",&num);

  int qtde_divisores;

  for (i = 0; i < num; i++){

      if (num % (i+1) == 0){
        qtde_divisores++; // qtde_divisores = qtde_divisores + 1;
      }
  }

  if (qtde_divisores > 2){
     printf("o número nao %i é primo.\n",num);
    
  }else {
    printf("o número  %i é primo.\n",num);
  }

  return 0;
}