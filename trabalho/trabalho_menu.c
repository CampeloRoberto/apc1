/* 

printf("%-10s \n",ranking[i].nome);
sleep (1.4);
deu_certo = system("clear");

do{
  printf(" \n                                   Para sair aperte '0'       ");
  int ch = getchar();
 if ( ch == '0' ) {
  printf("\e[?25h");
    quit = 1;
    break;

    }
} while (quit = 1);
*/

#include <stdio.h>
#include <stdlib.h> // para usar o system(), (clear), FD_SET, fd_set e o TDIN_FILENO
#include <unistd.h> // para usar a  STDIN_FILENO e usleep/sleep
#include <termios.h> // oldt, newt, tcgetattr, tcsetattr, ICANON, ECHO , TCANOW
#include <ctype.h>
#include <string.h>
#include <time.h>

#define colunas 50 //esses valores determinam o tamanho da arena, reduzi-los aumentará a dificuldade.
#define linhas 20
#define MAX_JOGADORES 5

// Estrutura que representa um jogador
typedef struct {
  char nome[6];  // Limitado a 5 caracteres + 1 para o caractere nulo '\0'
  int pontuacao;
} Jogador;

void exibirRanking(Jogador *ranking, int numJogadores) {
  printf("\e[46m\e[0;95m+-----------------------------------------------------------------------------------+\n");
  printf("|                                 RANKING                                      |\n");
  printf("+------------------------------------------------------------------------------------+\n");
  printf("|   Posição   |                    Nome               |           Pontuação          |\n");
  printf("-------------------------------------------------------------------------------------+\n");
  for (int i = 0; i < numJogadores; i++) {
    printf("|      %-4d   |                   %-8s            |             %-17d|\n", i + 1, ranking[i].nome,
           ranking[i].pontuacao);
  }
  printf("+------------------------------------------------------------------------------------+\n\e[0m");
}

// Adiciona um novo jogador ao ranking ou atualiza a pontuação se já existir
void adicionarAoRanking(Jogador *ranking, int *numJogadores, Jogador novoJogador) {
  for (int i = 0; i < *numJogadores; i++) {
    if (strcmp(ranking[i].nome, novoJogador.nome) == 0) {
      ranking[i].pontuacao += novoJogador.pontuacao;
      return;
    }
  }

  if (*numJogadores < MAX_JOGADORES) {
    // Adiciona um novo jogador se houver espaço no ranking
    strncpy(ranking[*numJogadores].nome, novoJogador.nome, 5);
    ranking[*numJogadores].nome[5] = '\0';  // Certifica-se de terminar a string
    ranking[*numJogadores].pontuacao = novoJogador.pontuacao;
    (*numJogadores)++;
  } else {
    // Encontra o jogador com a pior pontuação no ranking
    int piorPontuacao = ranking[0].pontuacao;
    int indicePiorJogador = 0;
    for (int i = 1; i < MAX_JOGADORES; i++) {
      if (ranking[i].pontuacao < piorPontuacao) {
        piorPontuacao = ranking[i].pontuacao;
        indicePiorJogador = i;
      }
    }

    // Substitui o pior jogador se a pontuação do novo jogador for melhor
    if (novoJogador.pontuacao > piorPontuacao) {
      strncpy(ranking[indicePiorJogador].nome, novoJogador.nome, 5);
      ranking[indicePiorJogador].nome[5] = '\0';  // Certifica-se de terminar a string
      ranking[indicePiorJogador].pontuacao = novoJogador.pontuacao;
    }
  }
}

int main() {
  // PRIMEIRO PASSO: TIRAR O CURSOR ( se nao nao teremos como apertar os controles do jogo da cobrinha)
  printf("\e[?25l");

char opcao  = 0; // por isso que o enter vai;
  Jogador ranking[MAX_JOGADORES];
  int numJogadores = 0;


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
      printf("                       3 - RANKING                       \n");
      printf("                        0 - SAIR                      \n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf( "Aperte apenas o número da opção desejada => ");

      deu_certo =scanf(" %c", &opcao);
      while (getchar ()!= '\n');

        switch (opcao)
          {
////////////////////////////////////////JOGO DA VELHA/////////////////////////////////////////////////////////////////
            case '1':
            deu_certo = system("clear");
              printf(" ---------BEM VINDO AO JOGO DA VELHA---------\n\n");
              printf ("           -----!!INSTRUÇÕES!!-----");
              printf("\n");
              printf("\n");
              printf("    -O numero das linhas fica ao lado direito.                             \n\n");
              printf("    -E o numero das colunas em cima.                               \n\n");
              printf("    -Digite o numero que deseja de 0 a 2 e de enter.                    \n\n");
              //printf("    -Para sair do jogo aperte a tecla  '9'   \n");
              printf("\n");
              printf("\n");
              printf("\n");
              printf("\n");
              printf("          APERTE ENTER PARA COMEÇAR!!!       \n");

            getchar();
           int deu_certo = system("clear");
    int l, c, linha, coluna, jogador, ganhou, jogadas, opcao2;
    char jogo[3][3];// estrutura de dados

    do{
        jogador = 1;
        ganhou = 0;
        jogadas = 0;// jogar novamente

        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                jogo[l][c] = ' ';
            }
        }// como inicializar estruturaa de dados

        do{
            int deu_certo = system("clear");
            printf("\n\n\t 0   1   2\n\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(c == 0)
                        printf("\t");
                    printf(" %c ", jogo[l][c]);
                    if(c < 2)
                        printf("|");
                    if(c == 2)
                        printf("  %d", l);
                }
                if(l < 2)
                    printf("\n\t-----------");
                printf("\n");
            }// repete até alguém ganhar ou atingir 9 jogadas, imprimir jogo

            // ler coordenadas
            do{
                printf("\n JOGADOR 1 = 0\nJOGADOR 2 = X\n");
                printf("\n JOGADOR %d: Digite a linha que deseja jogar + enter: ", jogador);
                int deu_certo3 = scanf("%d", &linha);
                printf("\n JOGADOR %d: Digite a coluna que deseja jogar + enter: ", jogador);
                int deu_certo4 = scanf("%d", &coluna);

            }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');


            // salvar coordenadas
            if(jogador == 1){
                jogo[linha][coluna] = '0';
                jogador++;
            }
            else{
                jogo[linha][coluna] = 'X';
                jogador = 1;
            }
            jogadas++;

            // alguém ganhou por linha
            if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
               jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
               jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu por linha!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
               jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
               jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu por linha!\n");
                ganhou = 1;
            }

            // alguém ganhou por coluna
            if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
               jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
               jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu por coluna!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
               jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
               jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu por coluna!\n");
                ganhou = 1;
            }

            // alguém ganhou na diagonal principal
            if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu na diag. principal!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu na diag. principal!\n");
                ganhou = 1;
            }

            // alguém ganhou na diagonal secundária
            if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
                printf("\nParabens! O jogador 1 venceu na diag. secindaria!\n");
                ganhou = 1;
            }

            if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
                printf("\nParabens! O jogador 2 venceu na diag. secundaria!\n");
                ganhou = 1;
            }
        }while(ganhou == 0 && jogadas < 9);

        // imprimir jogo

        printf("\n\n\t 1   2   3\n\n");
        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                if(c == 0)
                    printf("\t");
                printf(" %c ", jogo[l][c]);
                if(c < 2)
                    printf("|");
                if(c == 2)
                    printf("  %d", l);
            }
            if(l < 2)
                printf("\n\t-----------");
            printf("\n");
        }

        if(ganhou == 0)
            printf("\nO jogo finalizou sem gamhador!\n");

        printf("\nDigite 1 + enter para jogar novamente: \n");
        printf("\nDigite qualquer outra tecla + enter para voltar ao menu \n");
      int deu_certo5 = scanf("%d", &opcao2);
    }while(opcao2 == 1);

            printf("Pressione ENTER para continuar\n");
            getchar();
            break;
////////////////////////////JOGO DA COBRA//////////////////////////////////////////////////////////////////
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

            printf("                  .-=*#####+-.                   \n");
            printf("                .+@@@@@@@@@@@@@@@@+.                \n");
            printf("               @@@@@@@@@@@@@@@@@@@@               \n");
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
            printf("              .@@@@@@@@@@@@@@@@@@@@.              \n");
            printf("                .=*@@@@@@@@@@@@@@#=.                \n");
            sleep (1.4);
             deu_certo = system("clear");
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
  int x[1000], y[1000]; //de certa maneira e a memoria do joguinho!   ------------------------------ ué
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
        comidax = rand() % colunas; // gera uma posição de valor menor que o numero de colunas e linhas para sempre gerar dentro
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
          cauda = (cauda + 1) % 1000;
      }


      int nova_cabeca = (cabeca + 1) % 1000; //na verdade a cabeça da cobra sempre vai indo pra cauda/ resto da divisão garante inteiro.
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
      //aqui definimos a velocidade da cobra!! está em microssegundos, ou seja, 0,84 segundos - quanto menor mais rapida ela se move/
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
        if (ch == '0' ) {
          quit = 1;
        } else if (ch == 'a'|| ch=='A' && xdir != 1) { // aqui definimos a tecla que vai mexer a cobrinha variando em x ou em y , mas esta invertido em x e y
          xdir = -1;//para esquerda
          ydir = 0;
        } else if (ch == 'd' || ch=='D' && xdir != -1) { //AQUI NAO TEMOS MAIS PROBLEMA COM CAPS LOCK
          xdir = 1;//para direita
          ydir = 0;
        } else if (ch == 's' || ch=='S' && ydir != -1) {
          xdir = 0; //para baixo
          ydir = 1;
        } else if (ch == 'w' || ch=='W' && ydir != 1) {
          xdir = 0;//para cima
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
     
      printf(" \n                                   Para sair aperte '0'       ");
      printf(" \n                       Para recomeçar tecle qualquer outra tecla       ");

      // colocar um comando switch (sair, remomeçar) como novas opções
      // colocar um ranking de melhor pontuaçao;


      printf("\e[%iF", linhas / 2);
      fflush(stdout);
      //estrutura que define os botoes da saida do jogo ou para recomeçar
    int ch = getchar();
       if ( ch == '0' ) { // 27 = Esc
          quit = 1;
          break;

          }else{

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

            case '0':
            break;


            default: printf("\e[0;31mOpção inválida!\e[0m\n");
            printf("Pressione ENTER para continuar\n");
            getchar();
            break;
          //aqui se encerra o nosso switch do jogo da cobra
            ////////////////////////////RANKING//////////////////////////////////////////////////////////////////
            case '3':
            // Exibe o ranking
            do {
              deu_certo = system("clear");

              // Exibe o ranking de jogadores
              exibirRanking(ranking, numJogadores);

              printf("\e[46m\e[0;95m+------------------------------------------------------------------------------------+\n");
              printf("\e[46m\e[0;95m+------------------------------------------------------------------------------------+\n");
              printf("|                             0 - Voltar ao Menu                                     |\n");
              printf("+-----------------------------------------------------------------------------------+\n\e[0m");
              printf("\e[46m\e[0;95mEscolha uma opção: \e[0m");
              int ch = getchar();
               if ( ch == '0' ) { // 27 = Esc
                  quit = 1;
                  break;

                  }else{

              int deu_certo = system ("clear");
               }

              if (opcao == 4) {
                break; // Voltar ao Menu
              } else if (opcao == 5) {
                printf("\e[46m\e[0;95mSaindo do jogo.\n");
                return 0;
              } else {
                printf("\e[46m\e[0;95mOpção inválida. Tente novamente.\n");
              }
            } while (1);
            break;
          }


    }


return 0;
}