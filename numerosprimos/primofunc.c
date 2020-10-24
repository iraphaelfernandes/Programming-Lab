#include <stdio.h>
//foi: 50000

#define NESIMO 10 // n ésimo número a ser achado

int checa_primo(int);

int main() {
  
  int n = 1, result;
  int numero = 2, j;
  
  for(j = 0; j != NESIMO;) {
    
    result = checa_primo(n);
    
    if (result == 1) {
      
      j++;
      numero = n;
      
    }
    n++;
    
  }

  printf("O %d° número primo é: %d\n", NESIMO, numero);


  // result = checa_primo(n);

  // if (result == 1)
  //     printf("%d é primo.\n", n);
  // else
  //     printf("%d não é primo.\n", n);
  
  
  return 0;
}

int checa_primo(int a) {
  int c;
  
  for (c = 2; c <= (a - 1); c++) {
      if (a%c == 0)
    return 0;
  }
  
  if (c == a) {
      return 1;
    }
}

