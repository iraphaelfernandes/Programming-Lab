// 1 - Revise a rotina lelinha do programa que 
// imprime a maior linha para que imprima corretamente
// o tamanho de linhas de entrada arbitrariamente longas, 
// e a maior quantidade de texto possível da mesma.

#include <stdio.h>

#define MAXLINE 1000 //tamanha max da linha de entrada

int lelinha(char linha[], int maxlinha); // Le a linha e em s e retorna o tamanho
void copia(char para[], char de[]);      // copia 'de'=>'para'; presume que 'para' é grande o suficiente
//-----------------------------------------------
int main(void){
  
  int tam;             //tamanho atual da linha
  int max = 0;         //tamanho máximo visto até agora
  
  int tamMax = 0; //essa variavel grardara os tamanhos
  
  char linha[MAXLINE]; //linha atual
  char maior[MAXLINE]; //maior linha guardada

  while ((tam = lelinha(linha, MAXLINE)) > 0) { //maior que 0 para não verificar linhas vazias

    if(tam > tamMax) { //Se o tamanho atual da linha for maior que o tamanho maximo
      
        tamMax = tam;
        copia(linha, maior);
    }
  
  printf("Comprimento da Linha: %d\n\n", tam);
  }
  
  if(tamMax > 0){
    printf("A maior linha eh: %s\n", maior);
  }
  
  
  return 0;
}
//-----------------------------------------------

// Le a linha e em s e retorna o tamanho

int lelinha(char s[], int tamMax){ //substituir int lim por MAXLINE. s é um vetor que recebe o vetor linha

  int c, i;

  for (i = 0; i < tamMax - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
    
    s[i] = c;
    
  }

  if (c == '\n'){
    
    s[i] = c;
    
    ++i;
  }

  s[i] = '\0';

  return i; // i é o tamanho, pois o último carac é o tamanho da linha
}

// copia 'de' => 'para';
// presume que 'para' é grande o suficiente
void copia(char para[], char de[]){

  int i = 0;

  while ((para[i] = de[i]) != '\0'){
    ++i;
  }
}
