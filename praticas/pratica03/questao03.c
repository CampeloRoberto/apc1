//Faça um programa em C que imprima um qualitativo associado a uma nota lida conforme a tabela: 1 = Ruim; 2 = Insuficiente; 3 = Suficiente, 4 = Bom, 5 = Ótimo, e imprima Nota inválida nos demais casos.

#include <stdio.h>

int main ()
{
int nota;
int leu_certo;

  printf("Avalie o serviço de 1 a 5, sendo 1 o ruim e 5 o ótimo\n");
  leu_certo = scanf ("%i",&nota);
 
  
  if (leu_certo > 0 && nota > 0 && nota < 6)
  {
  printf("Obrigado por avaliar o serviço\n");

    if (nota == 1)
    {
      printf("Ruim\n");
    }else if (nota == 2){
      printf("Insuficiente\n");
    }else if (nota == 3){
      printf("Suficiente\n");
    }else if (nota == 4) {
      printf("Bom\n");
    }else if ( nota == 5){
      printf("Ótimo\n");
    }
  }else {
    printf("Nota inválida, digite 1, 2 ,3 ,4 ou 5");
    
  }
  



  return 0 ;
}