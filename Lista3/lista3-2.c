// 2 - Escreva um programa que remova espaços em branco
// e caracteres de tabulação 
// finais de cada linha de entrada e que delete as 
// linhas inteiramente em branco.

#include <stdio.h>

#define MAXLINHA 1000

int lelinha(char linha[], int limit); //le a linha e retorna o tamanho
void removeCaracteres(char linha[], int tam);

//------------------------
int main(void) {
  
  int tam;
  char linha[MAXLINHA];
  
  while ((tam = lelinha(linha, MAXLINHA)) > 0) {
    
    removeCaracteres(linha, tam);
    
    printf("%s", linha);
    
  }
  
  return 0;
}
//------------------------


int lelinha(char linha[], int limit) {
  
  int c, i; //c é o carac de leitura e i é um contador
  
  for(i=0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    
    linha[i] = c;
  }
  
  if (c == '\n') {
    linha[i] = c;
    ++i;
  }
  
  linha[i] = '\0';
  
  return i;
}


void removeCaracteres(char linha[], int tam) {
  
  int i; //o tamanho do array
  
  
  //o laço apenas diminui o tamanho de i, que eh o tamanho do array, na verdade
  for(i = tam - 2; linha[i] == ' ' || linha[i] == '\t'; --i);
  
  //essas setagens sao para fechar as strings
  linha[i + 1] = '\n';
  linha[i + 2] = '\0';
  
}