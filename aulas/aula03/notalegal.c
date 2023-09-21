#include <stdio.h> // stdio.h possui printf, scanf

int main()
{
char i1[61]; 
int q1; 
float p1 ;
  
char i2 [61] = "0";
int q2 = 0;
float p2 = 0.0f;
  
char i3[61] = "borracha";
int q3 = 2;
float p3 = 6.0f;



// %-12.12s == jeitos de como a sda vai ser, - = completa apos, 12 - numero de caracteres, .12 = numero maximo de caracteres a ser exibido, 012 - completa tudo q nao foi escrito com 0. 

printf ("\nentre com o nome do item1: ");
scanf("%s",i1);  
printf("\nentre com a quantidade do item1: ");
scanf("%i",&q1);
printf ("\nentre com o valor do item1: ");
scanf("%f",&p1);

printf ("\nentre com o nome do item2: ");
scanf("%s",i2);  
printf("\nentre com a quantidade do item2: ");
scanf("%i",&q2);
printf ("\nentre com o valor do item2: ");
scanf("%f",&p2);

printf ("\nentre com o nome do item3: ");
scanf("%s",i3);  
printf("\nentre com a quantidade do item3: ");
scanf("%i",&q3);
printf ("\nentre com o valor do item3: ");
scanf("%f",&p3);
  
  
float total; 
total = q1 * p1;
total = total + q2*p2;
total = total + q3*p3;

  
printf("------------------------------\n");
printf("     N O T A  L E G A L      \n");
printf("Item        qtd      Valor   \n");
printf ("%-12.12s %03i %10.2f \n",i1,q1,p1); 
printf ("%-12.12s %03i %10.2f \n",i2,q2,p2);//pq deu errado??
printf ("%-12.12s %03i %10.2f \n",i3,q3,p3);
printf ("------------------------------\n");
printf ("Total        R$ %11.2f\n",total);
printf ("------------------------------\n");
  
  return 0;
}