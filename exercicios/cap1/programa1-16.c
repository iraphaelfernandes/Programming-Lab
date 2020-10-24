#include <stdio.h>

#define MAXLINE 1000 //tamanha max da linha de entrada

int lelinha(char linha[], int maxlinha); // Le a linha e em s e retorna o tamanho
void copia(char para[], char de[]);      // copia 'de'=>'para'; presume que 'para' é grande o suficiente

int main(void){
  
  int tam;             //tamanho atual da linha
  int max = 0;         //tamanho máximo visto até agora
  
  char linha[MAXLINE]; //linha atual
  char maior[MAXLINE]; //maior linha guardada

  while ((tam = lelinha(linha, MAXLINE)) > 0) //maior que 0 para não verificar linhas vazias
  {
    if (tam > max) //Se o tam for maior que max, max recebe o valor de tam
    {
      max = tam;
      //chama copia nessa condição
      copia(maior, linha); //maior e linha são arrays
    }
  }

  if (max > 0) //Funciona sem esse if. Imprime a linha após verificar qual é a maior
  {
    printf("%s", maior);
  }

  return 0;
}

// Le a linha e em s e retorna o tamanho

int lelinha(char s[], int lim){ //substituir int lim por MAXLINE. s é um vetor que recebe o vetor linha

  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i){
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
