#include <stdio.h>
#include <string.h>

int main()
{
struct aluno_t {
int matricula;
  char email[61]; // esse 1 a mais e o /0
  
};

  struct aluno_t alunos [10];

  for (int i = 0; i < 10; i++){
    printf("Aluno %i\n",i+1);
    printf("Entre com a matricula do aluno %i: ",i+1);
    int ok = scanf("%i",&alunos[i].matricula);
    getchar();
    printf("Entre com o email do aluno %i: ",i+1);

    ok = scanf("%[^\n]s",alunos[i].email);
    getchar();

  }
  int matricula;
  printf("Entre com uma matricula para achar o email: ");
  int ok = scanf("%i",&matricula);
  int achei = -1;
  for (int i = 0; i<10; i++){
    if(matricula == alunos [i].matricula){
      achei = i;

      break;
    }
  }
if (achei <0){
  printf("Matricula não encontrada\n");
  
}else {
  printf("o e-mail é %s\n",alunos[achei].email);
}



  return 0;
  
}