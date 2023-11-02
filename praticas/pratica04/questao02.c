/* Faça um programa em C que leia as notas de 10 alunos, calcule a média da turma e contabilize quantos alunos estão com a nota acima da média.*/

#include <stdio.h>

int main()
{
float notas [10];
int i;
float soma  = 0;
  int qtde_acima_da_media = 0;
  
  for (i = 0; i <10 ; i++){
   
     printf( "\nDigite a nota %i dos alunos: ",i+1);
     int deu_certo = scanf("%f", &notas[i]);
      
  }
  for (i = 0; i <10 ;i++){
   
     soma = notas [i] + soma;
    
  }
    float media;
    media = soma/10;
  
   
  
  for (i = 0; i <10; i++)
    {
      printf ("%.1f ",notas [i]);
      if (notas[i]> media){
        qtde_acima_da_media ++;
        
      }
    }
    printf("\n");
     printf ("\no valor da media da turma é: %.1f e %i alunos ficaram acima dela\n",media, qtde_acima_da_media);
  
  return 0;
}