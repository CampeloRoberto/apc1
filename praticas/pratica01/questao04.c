// QUESTAO 04 Faça um programa que C que calcule os impostos incluídos no preço de um produto (preço final = (1 + ICMS + COFINS + PIS/PASEP) x preço inicial). Considere ICMS igual a 17%, COFINS igual a 7,6% e PIS/PASEP igual a 1,65%.
// a ideia e eu comerciante vender o produto para saber quanto de imposto vai somar ao valor do produto;
// podemos fazer o programa mostrando o valor de cada imposto dentro do produto;

#include <stdio.h>





int main()
{

  
  
const float ICMS = 0.17;
const float COFINS = 0.076;
const float PIS_PASEP = 0.0165;

  float preco;
  float Valor_ICMS;
  float Valor_COFINS;
  float Valor_PIS_PASEP;
  
 printf ("digite o preço do produto:  ");
  scanf("%f",&preco);
  
Valor_ICMS = ICMS*preco;
  printf ("\n O valor do ICMS é  %.2f",Valor_ICMS);
  
Valor_COFINS = COFINS*preco;
  printf ("\n O valor do COFINS é  %.2f",Valor_COFINS);
  
Valor_PIS_PASEP = PIS_PASEP*preco;
  printf ("\n O valor do PIS/PASEP é  %.2f",Valor_PIS_PASEP);
  
  
  preco = 1 *preco + ICMS*preco + COFINS*preco + PIS_PASEP*preco;

  printf ("\n O valor do produto mais impostos é: %.2f ",preco);


  return 0;
}