#include <stdio.h>

int main()
{
    
char c  = 127;
int i = c; //conversao implicita
float f  = i; // conversao implicita com ressalva nas casas decimais
double d = f; //convversão implicita , double tem mais bites do que float


printf("\n O caracter %d convertido em inteiro é %d", c, i);
printf("\n O inteiro %d convertido em flutuante é %f", i, f);
printf("\n O flutuante %f convertido em duplo é %f", f, d);

d = 270.1234567890;
f = (float) d; //conversao explicita
i = (int) f;
c = (char) i;

printf("\n o duplo %f convertido em flutuante %f", d, f);
printf("\n o flutuante %f convertido em inteiro %d", f, i);
printf("\n o inteiro %d convertido em caracter %d", i, c);
  
  

  

    
    return 0;
}
