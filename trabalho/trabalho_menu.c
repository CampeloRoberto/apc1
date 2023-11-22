/*   PENDENCIAS
- ambições = menu/ score/ nao abrir o jogo na hora q da enter/ mudar dificuldade
- selecionar dificuldade no menu (alterar tamanho da arena), mas como mudar se sao constantes ??
- printf ("\e[?25l"); --- ?
-canonical mode? disable echo? tcgetattr ?
- /a ?

*/

#include <stdio.h>
#include <stdlib.h> // para usar o system(), (clear), FD_SET, fd_set e o TDIN_FILENO
#include <unistd.h> // para usar a  STDIN_FILENO e usleep
#include <termios.h> // oldt, newt, tcgetattr, tcsetattr, ICANON, ECHO , TCANOW

#define colunas 50 //esses valores determinam o tamanho da arena, reduzi-los aumentará a dificuldade.
#define linhas 30

int main() {
  // PRIMEIRO PASSO: TIRAR O CURSOR ( se nao nao teremos como apertar os controles dos jogos)
  printf("\e[?25l");

char opcao  = 0;

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
      printf( "Aperte apenas p número da opção desejada => ");

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
            printf(" ---------BEM VINDO AO JOGO DA COBRINHA!!!----\n"); //adicionar modo dificil!! (ganha 3 pontos por coração)
            printf("\n");
            printf("\n");
            printf("    Para Mover a                             \n");
            printf("    Cobrinha!!                               \n");
            printf("                       'W'                    \n");
            printf("                'A'    'S'   'D'              \n");
             printf("\n");
            printf("  Para sair do jogo aperte a tecla      Esc   \n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("           APERTE ENTER PARA COMEÇAR!!!       \n"); //como fazer um 3... 2... 1... já!! trabalho demais?
            getchar();
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

    printf("└"); // quina inferior esquerda
    for (int i = 0; i < colunas; i++)
      printf("─"); // linhas horizontais da base
      printf("┘\n"); // quina inferior direita

    // essa função faz o cursor (que é a cobrinha), voltar para o topo da arena, sem ela a cobra come as linhas horizontais
    printf("\e[%iA", linhas + 2);

    int cabeca = 0, cauda = 0; // declarando variaveis da cobra;
    x[cabeca] = colunas / 2; // vetor de posição  da cobra horizontal
    y[cabeca] = linhas / 2; // vetor de posição da cobra vertical
    int game_over = 0;
    int xdir = 1, ydir = 0;
    int applex = -1, appley;
    int score = 0;

    while (!quit && !game_over) {
      if (applex < 0) {
        // definindo posição aleatória da comida
        applex = rand() % colunas;
        appley = rand() % linhas;

        for (int i = cauda; i != cabeca; i = (i + 1) % 1000)
          if (x[i] == applex && y[i] == appley)
            applex = -1;

        if (applex >= 0) {
          // printando a comida
          printf("\e[%iB\e[%iC\e[0;31m▓\e[0m", appley + 1, applex + 1); //mudando para vermelho e o simbolo para quadrado!!
          printf("\e[%iF", appley + 1);
          score = score + 1; // aqui definimos quantas comidas a cobra comeu!   ❤
        }
      }

      // limpando a cauda da cobra
      printf("\e[%iB\e[%iC ", y[cauda] + 1, x[cauda] + 1);
      printf("\e[%iF", y[cauda] + 1);

      if (x[cabeca] == applex && y[cabeca] == appley) {
        applex = -1;
        printf("\a"); // Bell
      } else
        cauda = (cauda + 1) % 1000;

      int nova_cabeca = (cabeca + 1) % 1000;
      x[nova_cabeca] = (x[cabeca] + xdir + colunas) % colunas;
      y[nova_cabeca] = (y[cabeca] + ydir + linhas) % linhas;
      cabeca = nova_cabeca;

      for (int i = cauda; i != cabeca; i = (i + 1) % 1000)
        if (x[i] == x[cabeca] && y[i] == y[cabeca])
          game_over = 1;

      // printando a cabeça da cobra
      printf("\e[%iB\e[%iC\e[0;32m▓\e[0m", y[cabeca] + 1, x[cabeca] + 1); // mudei para verde ▓
      printf("\e[%iF", y[cabeca] + 1);
      fflush(stdout);

      usleep(5 * 1000000 / 60); // aqui definimos a velocidade da cobra!! ela tem um formato de escrita, nao aceita so um valor


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
        if (ch == 27 ) { // 27 = Esc
          quit = 1;
        } else if (ch == 'a' && xdir != 1) {
          xdir = -1;
          ydir = 0;
        } else if (ch == 'd' && xdir != -1) {
          xdir = 1;
          ydir = 0;
        } else if (ch == 's' && ydir != -1) {
          xdir = 0;
          ydir = 1;
        } else if (ch == 'w' && ydir != 1) {
          xdir = 0;
          ydir = -1;
        }
      }
    }

    if (!quit) {
      // Show game over
      printf("\e[%iB\e[%iC Game Over!  ", linhas / 2, colunas/ 2 - 5);
      printf("\e[%iB\e[%iC SCORE = %i ",linhas/2, colunas/2 - 6, score);
      printf("\e[%iF", linhas / 2);
      fflush(stdout);
      getchar();

    }
  }

  // REaparecer com o cursor
  printf("\e[?25h");

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

            break;


          }


    }


  return 0;
}
