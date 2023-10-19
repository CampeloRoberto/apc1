/* Faça um progrma que liste todfos os multipros de 3 de 1 a 100 */
#include <stdio.h>

int main ()
{

int i;
printf ("este programa lista todos os mulitplos de 3 de 1 a  100\n");

/*  printf ("usando if e for:\n");
  for (i = 1; i < 101; i++)
    {
    if (i % 3 ==0){
      printf("%i, ",i);
    }
    }
  printf("\n");     */

  printf ("usando apenas for:\n");
  for (i = 3; i < 100; i= i+3){
    printf("%i, ",i);
  }
  printf("\n"); 
  return 0;
}