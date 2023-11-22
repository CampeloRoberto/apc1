#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{

enum meses_e {jan = 1,fev,mar,abr,mai,jun,jul,ago,set,out,nov,dez};
  char nomes [12][10] = {"janeiro", "fevereiro"," marco"," abril", "maio", "junho", "julho", "agosto"," setembro", "outubro"," novembro", "dezembro"};//meses/numero de letra
printf("Digite com um mes de 1 a 12: ");
 int mes;
int limpeza = system ("clear");
int ok = scanf("%i",&mes);
  
  switch (mes){
    case jan:
    case fev:
    case mar:
    case abr:
    case mai:
    case jun:
    case jul:
    case ago:
    case set:
    case out:
    case nov:
    case dez: printf("o mes escolhido foi o %s\n", nomes[mes-1]); 
    break;
    default: printf("mes invalido\n"); //se o camarada n digitar nad cm nad
    break;

    
  }
    
  







  
    return 0;

}