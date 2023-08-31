
// calcule o perimetro de uma pizza p=2 x PI x raio), considere Pi = 3.1416

#include<stdio.h>

int main()

{
float raio;

  printf("digite o valor do raaio\n");
  scanf("%f",&raio);

  float perimetro = 2.0000*3.1416*raio;


  printf("Seu perimetro= %.4f\n",perimetro);
  
  return 0;
}