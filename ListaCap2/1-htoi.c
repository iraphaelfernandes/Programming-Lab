#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// 1- Escreva a função htoi (s), que converte 
// uma string de dígitos hexadecimais (incluindo um 0x ou 0X opcional)
// no seu valor inteiro equivalente. 
// Os dígitos permitidos são de 0 a 9, de a a f, e de A a F.

#define MAXLINE 100

int lelinha(char line[], int lim);
int htoi(char hex[]);


//------------------------------------
int main(void) {
  
  char hex[MAXLINE];

  lelinha(hex, MAXLINE);

  printf("\nO corespondente valor e: %d\n", htoi(hex));

  return 0;
}
//------------------------------------

int lelinha(char line[], int lim) {
  char c;
  int i = 0;
  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
    
    line[i++] = c;
  }

  line[i] = '\0';

  return i;
}

int htoi(char hex[]) {
  int result = 0;

  int i = 0, len = strlen(hex);

  while (i < len) {
  
    if (hex[i] == '0' && (hex[i + 1] == 'x' || hex[i + 1] == 'X')) {
  
      i += 2;
    }

    int temp = tolower(hex[i]);

    if (isdigit(temp)) {
      
      temp -= 48;
    }

    if (isalpha(temp) && temp <= 'f') {
      
      temp = temp - 'a' + 10;
    }

    if ((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'a' && hex[i] <= 'f') || (hex[i] >= 'A' && hex[i] <= 'F')) {
  
      result += temp * (int)pow(16, len - i - 1);
    }
    
    else {
      printf("Esse não é um número decimal.\n");
    }

    ++i;
  }

  return result;
}



