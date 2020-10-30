#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 100

int getln(char line[], int lim);
int htoi(char hex[]);

//---------------------------------
int main(void){
  
  char hex[MAXLINE];
  
  getln(hex, MAXLINE);
  
  printf("%d\n", htoi(hex));

    return 0;
}

//---------------------------------

int getln(char line[], int lim) {
  
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
    
    if (insdigt(temp)) {
      tempo -= 48;
    }
    
    
  }
  
  
}