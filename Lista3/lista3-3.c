// 3 - Escreva uma função inverte(s) que 
// inverta a ordem dos caracteres da string s. 
// Use-a para escrever um programa que inverta 
// sua entrada, linha a linha.
#include <stdio.h>
#include <string.h>

#define MAXLINHA 1000
//leLinha le as entradas, coloca em linha e retorna o tamanho
int leLinha(char linha[], int limit); 
//tamLinha retorna o tamanho de uma linha
int tamLinha(char linha[]);
//inverteLinha inverte linha
void inverteLinha(char linha[], int limit);
//linhaReversa sera retornada por inverte lina
char linhaReversa[MAXLINHA];

//______________________________________________


int	main(void) {
  
  int tam;
  char linha[MAXLINHA];
  
  while((tam = leLinha(linha, MAXLINHA)) > 0) {
    
    inverteLinha(linha, MAXLINHA);
    printf("\n%s", linhaReversa);
    
  }
  
  
  return 0;
}
//______________________________________________

int leLinha(char linha[], int limit) {
  
  int c, i;
  
  i = 0;
  
  while (i < limit -1 && (c = getchar()) != EOF && c != '\n'){
    
    linha[i] = c;
    
    ++i;
  }  
  if(c == '\n'){
    linha[i] = '\n';
    ++i;
  }
  linha[i] = '\0';
  return i;
}

int tamLinha(char linha[]) {
  
  int i;
  for(i = 0; linha[i] != '\0'; ++i);
  return i;
}

void inverteLinha(char linha[], int limit) {
  
   // i recebe o tamanho da linha
  int i = 0;
  
  int j = 0;
  
  while (strlen(linha) > strlen(linhaReversa)) {
    
      linhaReversa[i - (i-j)] = linha[strlen(linha) - j];
    ++i;
    ++j;
  }

  
}