//https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
// aqui tem todas as cores
// \e[0;31m ------ \e[0m  - inicia vermelho --- termina vermelho - isso dentro do print
//ascii generator muda a fonte do texto - meio chato, tem q meter //printf em tudo

#include <stdio.h>
#include <stdlib.h>

int main ()
{


  char opcao = 0;
  float saldo = 0.0f;

  while (opcao != '0')
    {
    int deu_certo = system ("clear"); /* system vem do stdlib.h, e executa a função automaticamente, no caso a clear, que limpa a twela toda vez que o programa for executado.*/
      printf("MENU PRINCIPAL\n");
      printf("1 - Consultar Saldo\n");
      printf("2 - Fazer Recarga\n");
      printf("3 - Listar Recados\n");
      printf("0 - Sair\n");
      printf("Escolha a opçao => \n");

      deu_certo = scanf("%c",&opcao);
      while (getchar ()!= '\n');
      
      
      switch (opcao)
        {
          case '1':
            deu_certo = system ("clear");
            printf("CONSULTAR SALDO\n");
            printf( "O saldo é R$%5.2f\n", saldo);
            printf("Pressione ENTER para continuar\n"); /* Deixa a experiencuia do usuário mais fluida*/
            getchar(); /* comando vai ler um unico caracter que o usuario escrever, incluindio o enter*/
            
            break;
          case '2': {
            char valor = 0;
            while (valor != '0'){
            deu_certo = system ("clear");
            printf("FAZER RECARGA\n");
            printf( "1 - R$ 10,00\n");
            printf( "2 - R$ 20,00\n");
            printf( "3 - R$ 50,00\n");
            //printf( "0 - Retornar\n");
            printf("Escolha o valor da recarga ou digite 0 para retornar: ");
            deu_certo = scanf("%c",&valor);
              while (getchar()!= '\n');
              switch (valor) {
                case '1' : saldo = saldo + 10.0f; break;
                case '2' : saldo = saldo + 20.0f; break;
                case '3' : saldo = saldo + 50.0f; break;
                case '0':  break;
                default: printf("\e[0;31mValor inválida\e[0m\n");
                break;
              
              }
            if (valor == '1'|| valor == '2'|| valor == '3')
            {
              printf("\e[0;32mRecarga realizada com sucesso\e[0m\n");
              printf("pressione ENTER para continuar...");
              getchar();
            }
              }
            break;
            
          }
           
          case '3':
            deu_certo = system ("clear");
            printf("LISTAR RECADOS\n");
            printf( "NAO HÁ RECADOS\n");
            printf("Pressione ENTER para continuar\n");
            getchar();
            break;
          case '0':
            break;
          default: printf("\e[0;31mOpção inválida!\e[0m\n");
            printf("Pressione ENTER para continuar\n");
            getchar();
            break;
     
        }

     
      
    }

  return 0;
}