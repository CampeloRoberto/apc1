
// talvez o programe nao rode, depois eu tento arrumar, mas a ideia e entender que a variavel dentro das {} vai ter as atribuições lá dentro, se n tiver nada falando é fora;


#include <stdio.h>


int flobal = 10; // variavel compartilhada, não recomendado pq da muita memoria para o programa;

int main ()
{
int local = 10 ; // variável temporária, mais útil;
printf ("global = %d,local = %d \n"), global, local);
  
  {

    int local = 20;
    int global = 10;
printf ("global = %d,local = %d \n"), global, local);
    

    
  }

printf ("global = %d,local = %d \n"), global, local);
  
  
  return 0;

}