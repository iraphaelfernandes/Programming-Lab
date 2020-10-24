#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//foi: 50000

// #define NESIMO 50000 //n ésimo número primo a  ser achado

int checa_primo(int);


int main() {
  
  
  
  
  long int n = 1, result, alvo;
  long int numero = 2, j;
  
  printf("Digite o n-esimo numero primo a ser achado: \n");
  scanf("%d", &alvo);
  
  
  
  for(j = 1; j != alvo;) {
    
    // if (n%var == 0) {
    //   result = 0;
    // }
    
    // else {
    //   result = checa_primo(n);
    // }
    result = checa_primo(n);
    
    
    if (result == 1) {
      
      j++;
      numero = n;
      
    }
    n++;
    
  }

  printf("O %d° número primo é: %d\n", alvo, numero);


  // result = checa_primo(n);

  // if (result == 1)
  //     printf("%d é primo.\n", n);
  // else
  //     printf("%d não é primo.\n", n);
  
  
  return 0;
}

int checa_primo(int a) {
  int c;
  int var = 1;
  
  for (c = 3; c <= (a -1) && a%var == 0 ; c+=2) {
    
    if (a%c == 0) {
      return 0;
    }
    
  }
  
  if (c == a) {
    var = var * c;
      return 1;
    }
}

