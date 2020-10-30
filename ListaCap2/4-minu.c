#include <stdio.h>

#define MAX 1000

char minu(char b[]);
char carrega(char a[]);
char lower(char c);
char frase[MAX];


//-----------------------------------------------------------
int	main() {
  
  printf("Digite uma frase para ser lower case: \n");
  
  printf("\nA frase lower case é: %s",  minu(carrega(frase)));

  
  return 0;
}
//------------------------------------------------------------

char carrega(char a[]) {
  
  
  int i = 0;
  int c;
    while (c = getchar() != EOF) {
    
    frase[i++] = c;
  }
    
  frase[i] = '\0';
  
  return frase;
}

char minu(char b[]) {
  
  int c;
  int i = 0;
  
  while((b[i] != '\0')) {
    
    b[i] = lower(b[i]);
  }
  
  
}

char lower(char c) {
  
  return (c >= 'A' && c <= 'Z') ? c += 'a' - 'A' : c;
}
