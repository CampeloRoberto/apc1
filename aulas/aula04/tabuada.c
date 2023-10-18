/*programa que faz uma tabuada*/


#include <stdio.h>

int main ()
{
  int num;
  int i;
  int n;
  printf ("Digite um numero de 1 a 10: \n");
   int leu_certo = scanf("%i",&num);
  printf("digite o tamaho da tabuada: \n");
 int leu_certao =  scanf("%i",&n);

  

  printf( " a tabuada de %i\n",num);

  for (i=0; i < n; i ++)
    {
      printf("%i x %i = %i \n",num,i+1,num*(i+1));

    }

  return 0;
}