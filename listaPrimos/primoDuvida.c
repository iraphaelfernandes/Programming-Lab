#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Nesse arquivo, dúvida na função checa_primo

//foi: 50000

// #define NESIMO 50000 //n ésimo número primo a  ser achado

int checa_primo(int);


int main() {
  
  
  
  
  long int n = 1, result, alvo;
  long int numero = 2, j;
  
  printf("Digite o n-esimo numero primo a ser achado: \n");
  scanf("%ld", &alvo);
  
  
  
  for(j = 0; j != alvo;) {
    
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

  printf("O %ld° número primo é: %ld\n", alvo, numero);


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
  
  for (c = 2; c*c <= a; c++) {
    
    if (a%c == 0) {
      return 0;
    }
    
  }
  
  if (c == a) {
    var = var * c;
      return 1;
    }
}

