//Faça um programa em C que converta um valor qualquer em Gigabytes para um valor em bytes (1GB = 1024³Bytes).
// 

#include <stdio.h>

int main()
{
float GB;

printf("\n digite o valor em Gigabytes: ");
  scanf("%f",&GB);

  GB = GB*1024.0;
  
  printf("O valor em bytes é  %1.f",GB);
  
  
  


  return 0;
  
}