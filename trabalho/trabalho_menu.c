/*   PENDENCIAS
- ambições = menu/ mudar dificuldade
- selecionar dificuldade no menu (alterar tamanho da arena), mas como mudar se sao constantes ??
- strutc timeval, tv, STDIN_FILENO
-canonical mode? disable echo? tcgetattr ?


- usar comando default pro usuario nao avacalhar!!!

*/

#include <stdio.h>
#include <stdlib.h> // para usar o system(), (clear), FD_SET, fd_set e o TDIN_FILENO
#include <unistd.h> // para usar a  STDIN_FILENO e usleep/sleep
#include <termios.h> // oldt, newt, tcgetattr, tcsetattr, ICANON, ECHO , TCANOW

#define colunas 50 //esses valores determinam o tamanho da arena, reduzi-los aumentará a dificuldade.
#define linhas 20

int main() {
  // PRIMEIRO PASSO: TIRAR O CURSOR ( se nao nao teremos como apertar os controles dos jogos)
  printf("\e[?25l");

char opcao  = 0; // por isso que o enter vai;

  while (opcao != '0')
    {
        int deu_certo = system ("clear");
      printf("\n");
      printf("                      MENU DE JOGOS\n                     "); //MELHORAR A ESTETICA.
      printf("\n");
      printf("\n");
      printf("\n");
      printf("                    1 - JOGO DA VELHA                      \n");
      printf("                   2 - JOGO DA COBRINHA                       \n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("                                                 0 - SAIR\n " );
      printf("\n");
      printf( "Aperte apenas o número da opção desejada => ");

      deu_certo =scanf(" %c", &opcao);
      while (getchar ()!= '\n');

        switch (opcao)
          {
            case '1':
            deu_certo = system("clear");
            printf(" BEM VINDO AO JOGO DA VELHA\n");
            printf("APERTE ENTER PARA CONTINUAR\n");
            getchar();
            break;

            case '2':
            deu_certo = system("clear");
            printf(" ---------BEM VINDO AO JOGO DA COBRINHA!!!----\n\n"); //adicionar modo dificil!! (ganha 3 pontos por coração)
            printf (" -----AUMENTE BASTANTE O TAMANHO DO CONSOLE!! -----");
            printf("\n");
            printf("\n");
            printf("    Para Mover a                             \n");
            printf("    Cobrinha!!                               \n");
            printf("                       'W'                    \n");
            printf("                'A'    'S'   'D'              \n");
             printf("\n");
            printf("  Para sair do jogo aperte a tecla      '0'   \n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("           APERTE ENTER PARA COMEÇAR!!!       \n"); 

            getchar();
            deu_certo = system("clear");
           printf("\n");
            printf("\n");

            printf("                  .-=**#####*+-.                   \n");
            printf("                .+@@@@@@@@@@@@@@@@+.                \n");
            printf("               *@@@@@@@@@@@@@@@@@@@@*               \n");
            printf("             .@@@@@@@*-.    .-#@@@@@@@              \n");
            printf("             .@@@@@*.          *@@@@@@-             \n");
            printf("               .:-=.           =@@@@@@-             \n");
            printf("                              .@@@@@@@              \n");
            printf("                      :::::-+#@@@@@@#.              \n");
            printf("                     -@@@@@@@@@@@@*:                \n");
            printf("                     -@@@@@@@@@@@@*=                \n");
            printf("                     .=+=+++*#@@@@@@@+              \n");
            printf("                              .*@@@@@@#             \n");
            printf("                                #@@@@@@:            \n");
            printf("            =+*#@@#             +@@@@@@-            \n");
            printf("            +@@@@@@#.          -@@@@@@@.            \n");
            printf("             =@@@@@@@#+-::::-+#@@@@@@@-             \n");
            printf("              .*@@@@@@@@@@@@@@@@@@@@*.              \n");
            printf("                .=*@@@@@@@@@@@@@@#=.                \n");
            sleep (1.4);
            int deu_certo = system("clear");
            usleep(500000);
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("                     .+@@@@@@@@#-                  \n");
            printf("                    -@@@@@#*#@@@@@.                \n");
            printf("                    @@@@+    .#@@@#                \n");
            printf("                   :@@@@      *@@@@                \n");
            printf("                             :@@@@#                \n");
            printf("                           -#@@@@*                 \n");
            printf("                        :+@@@@@*:                  \n");
            printf("                      -#@@@@#=                     \n");
            printf("                    .@@@@@=.                       \n");
            printf("                    @@@@@@#########                \n");
            printf("                   #@@@@@@@@@@@@@@@                \n");

            sleep (1.4);
            deu_certo = system("clear"); //pq nao ta limpando criatura?
            usleep(500000);
            deu_certo = system("clear");

            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("                        +@@@+                         \n");
            printf("                   .:-+@@@@@=                         \n");
            printf("                   #@@@@@@@@=                         \n");
            printf("                   =++*@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            printf("                      .@@@@@=                         \n");
            sleep (1.4);

            deu_certo = system("clear");







  // Mudando para modo canonico, desabilitar echo
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);


// definindo a área do jogo, se não a cobra some
  int x[1000], y[1000];
  int quit = 0;
  while (!quit) {
    printf("┌"); //quina superior esquerda
    for (int i = 0; i < colunas; i++)
      printf("─"); // linhas horizontais do topo
      printf("┐\n"); //quina superior direita

    for (int j = 0; j < linhas; j++) {
      printf("│"); //linhas verticais da borda esquerda
      for (int i = 0; i < colunas; i++)
      printf(" "); //preenchimento dos espaços da area
      printf("│\n"); // linhas verticais da borda direita
    }

  printf("\e[?25l");// ---------------------------------------------tirando o cursor de novo pq reapareceu sozinho
    printf("└"); // quina inferior esquerda
    for (int i = 0; i < colunas; i++)
      printf("─"); // linhas horizontais da base
      printf("┘\n"); // quina inferior direita

    // essa função faz o cursor (que é a cobrinha), voltar para o topo da arena, sem ela a cobra come as linhas horizontais
    printf("\e[%iA", linhas + 2);

    int cabeca = 0, cauda = 0; // declarando variaveis da cobra;
    x[cabeca] = colunas / 2; // vetor de posição  da cobra horizontal, dividio por 2 para a referencia ser o meio
    y[cabeca] = linhas / 2; // vetor de posição da cobra vertical
    int game_over = 0; //deve começar em zero, ja que em 1 o jogo acaba
    int xdir = 1, ydir = 0; // variaveis de direção, o xdir esta em 1 para a cobrinha começar a ir para a direita automaticamente
    int comidax = -1; /*tem que ser negatico para aparecer uma comida, a condição if só cria a
    comida caso o valor atribuido a comida seja negativo;*/
    int comiday; // nao precisa de valor inicial
    int score = 0; // boas praticas de programação, é o marcador de pontos

    while (!quit && !game_over) { //enquanto a pessoa nao perde ou nao aperta o botao de sair...
      if (comidax < 0) {
        // definindo posição aleatória da comida no eixo x e no eixo y;
        comidax = rand() % colunas;
        comiday = rand() % linhas;

        if (comidax >= 0) {
          // printando a comida
          printf("\e[%iB\e[%iC\e[0;31m▓\e[0m", comiday + 1 , comidax + 1); //mudando para vermelho e o simbolo para quadrado!! +1 pra n aparecer comida na borda
          printf("\e[%iF", comiday + 1); /*\e[%iB  e \e[%iC são prints posicionais, sendo C posição coluna, B posição da linha e
           \e[%iF retira as informações do console nao sai o local do arquivo no final*/
          score = score + 1; // aqui definimos quantas comidas a cobra comeu!   
        }
      }

      // limpando a cauda da cobra, sem isso vai ficando o rastro
      printf("\e[%iB\e[%iC ", y[cauda] + 1, x[cauda] + 1);
      printf("\e[%iF", y[cauda] + 1);

      if (x[cabeca] == comidax && y[cabeca] == comiday) { // aqui e quanto a cobra come a comida.
        comidax = -1; // -1, a comida some

      } else{
          cauda = (cauda + 1) % 1000; /*esse numero tem que ser alto, cada vez que a cauda amenta o valor deve se manter baixo,
           se nao a cauda nao limpa*/
      }


      int nova_cabeca = (cabeca + 1) % 1000; //na verdade a cabeça da cobra sempre vai indo pra cauda, 0 +1 e so pra n dividir 0/1000
      x[nova_cabeca] = (x[cabeca] + xdir + colunas) % colunas;
      y[nova_cabeca] = (y[cabeca] + ydir + linhas) % linhas;
      cabeca = nova_cabeca;

      for (int i = cauda; i != cabeca; i = (i + 1) % 1000){ //condições de derrota!, pode-se adicionar obstáculos ou colisao com parede
        if (x[i] == x[cabeca] && y[i] == y[cabeca])
        {
          game_over = 1;
        }

      }


      // printando a cabeça da cobra
      printf("\e[%iB\e[%iC\e[0;32m▓\e[0m", y[cabeca] + 1, x[cabeca] + 1); // foi para a cor para verde ▓
      printf("\e[%iF", y[cabeca] + 1);

      fflush(stdout); // ver o cursor frame a frame de acordo com a velocidade do usleep
      /*aqui definimos a velocidade da cobra!! está em microssegundos, ou seja, 0,84 segundos - quanto menor mais rapida ela se move*/
      usleep (84000);

      // para ler o teclado
      struct timeval tv;
      fd_set fds;
      tv.tv_sec = 0; // segundos
      tv.tv_usec = 0; // milissegundos

      FD_ZERO(&fds);
      FD_SET(STDIN_FILENO, &fds);
      select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv); // definir os controles do programa; (posso colocar como variável em menu);
      if (FD_ISSET(STDIN_FILENO, &fds)) {
        int ch = getchar();
        if (ch == '0' ) { // 27 = Esc
          quit = 1;
        } else if (ch == 'a'|| ch=='A' && xdir != 1) { // aqui definimos a tecla que vai mexer a cobrinha variando em x ou em y , mas esta invertido em x e y
          xdir = -1;
          ydir = 0;
        } else if (ch == 'd' || ch=='D' && xdir != -1) { //AQUI NAO TEMOS MAIS PROBLEMA COM CAPS LOCK
          xdir = 1;
          ydir = 0;
        } else if (ch == 's' || ch=='S' && ydir != -1) {
          xdir = 0;
          ydir = 1;
        } else if (ch == 'w' || ch=='W' && ydir != 1) {
          xdir = 0;
          ydir = -1;
        }
      }
    }

    if (!quit) {
      // Mostrar game over
      deu_certo = system("clear"); // colocar um outro switch
      printf("\n");
      //printf(" \n      Game Over!       ");
      printf("\n");
      printf("\n");
      printf("       ::=@@==========-      ::+@@==+@@=::      #@@@@-:.   ::+@@@@*   @@@@@=============-      \n");
      printf("    .::@@+=:              .:-@@+=-   ==+@@::.   #@@@@@@*:::*@@@@@@+   @@@@@                    \n");
      printf("    #@@@@.       .. ..    #@@@@        .@@@@+   #@@@@@@@@@@@@@@@@@*   @@@@@.. .. .. .          \n");
      printf("    #@@@@      ***@@@@#   #@@@@.       :@@@@+   #@@@@***@@#**#@@@@*   @@@@@**********=         \n");
      printf("    +*#@@.        @@@@#   #@@@@********#@@@@+   #@@@@   =*:  -@@@@*   @@@@@                    \n");
      printf("     b ##@@*      @@@@*   #@@@@        .@@@@+   #@@@@        -@@@@+   @@@@@                    \n");
      printf("         .############*   +##@@         @@@#=   *@@@*        :@@@@=   @@@@@#############+      \n");
      printf("\n");
      printf("\n");
      printf("       @@#########@#      #@@@@         @@@@+   #@@@@*************-   @@@@@#########@*         \n");
      printf("    #@@@@:        @@@@*   #@@@@         @@@@+   @@@@@                 @@@@@        =@@@@*      \n");
      printf("    #@@@@:        @@@@*   #@@@@         @@@@+   @@@@@                 @@@@@        =@@@@*      \n");
      printf("    #@@@@:        @@@@#   *@@@@@@+   +#@@@@+=   #@@@@#**********      @@@@@     .@@@@@@@*      \n");
      printf("    #@@@@:        @@@@#     .@@@@@###@@@@@      #@@@@                 @@@@@#####@@@            \n");
      printf("    #@@@@:        @@@@#        =@@@@@@@-        #@@@@                 @@@@@   @@@@@#*=         \n");
      printf("    ...*@#@@@@@@@@@*..          ..*@*..         #@@@@+++++++++++++-   @@@@@   ..:@@@@#++=      \n");
      printf("\n");
      printf("\n");

      printf(" \n                                         SCORE = %i         ",score);
      printf(" \n                                   Para sair aperte '0'      ");
      printf(" \n                       Para recomeçar tecle qualquer outra tecla       ");

      // colocar um comando switch (sair, remomeçar) como novas opções
      // colocar um ranking de melhor pontuaçao;


      printf("\e[%iF", linhas / 2);
      fflush(stdout);
      //estrutura que define os botoes da saida do jogo ou para recomeçar
    int ch = getchar(); // nao queria que fosse de dois fatores
       if ( ch == '0' ) { // 27 = Esc
          quit = 1;
          break;
          }else{
             //getchar();
      int deu_certo = system ("clear");

      printf("\n");
      printf("\n");
      printf ("\n\n---------- Para recomeçar tecle qualquer tecla!! --------");

          }
      getchar();
      int deu_certo = system ("clear");

    }
  }

  // Reaparecer com o cursor
  printf("\e[?25h");

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

            break;


          }


    }


  return 0;
}