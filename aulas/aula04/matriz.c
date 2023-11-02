#include <stdio.h>

int main ()
{
float notas [10][3];
int i, j;  
 notas [0][0] = 6.0f; notas [0][1] = 4.0f; notas [0][2] = 2.0f;
  notas [1][0] = 5.0f; notas [1][1] = 3.0f; notas [1][2] = 5.0f;
  notas [2][0] = 6.0f; notas [2][1] = 4.0f; notas [2][2] = 2.0f;
  notas [3][0] = 6.0f; notas [3][1] = 4.0f; notas [3][2] = 2.0f;
  notas [4][0] = 6.0f; notas [4][1] = 4.0f; notas [4][2] = 2.0f;
  notas [5][0] = 6.0f; notas [5][1] = 4.0f; notas [5][2] = 2.0f;
  notas [6][0] = 6.0f; notas [6][1] = 4.0f; notas [6][2] = 2.0f;
  notas [7][0] = 6.0f; notas [7][1] = 4.0f; notas [7][2] = 2.0f;
  notas [8][0] = 6.0f; notas [8][1] = 4.0f; notas [8][2] = 2.0f;
  notas [9][0] = 5.0f; notas [9][1] = 5.0f; notas [9][2] = 5.0f;
 



  
  for (int i = 0; i < 10; i++){

    for (int j = 0; j<3; j++){
  printf("%1.f,",notas[i][j]);
    }
printf ("\n");
  }
   


  return 0;
}