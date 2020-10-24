#include <stdio.h>


int main(void){

  int ndigit [10];

  int c, nbranco, noutro;
  nbranco = noutro = 0;

  for(int i = 0; i < 10; ++i) {
    ndigit [i] = 0;
  }

  while((c = getchar()) != EOF) {

    if(c >= '0' && c <= '9'){
      ++ndigit[c - '0'];
    } else if(c == ' ' || c == '\n' || c == '\t') {
      ++nbranco;
    } else {
      ++noutro;
    } 

  }
  printf("\nDigitos = ");

    for(int i = 0; i < 10; ++i){
      printf("%d", ndigit[i]);
    }
    printf(", espaço branco= %d, outros= %d\n", nbranco, noutro);



  return 0;
}