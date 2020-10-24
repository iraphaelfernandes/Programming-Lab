#include <stdio.h>
#define NUMEROMAX 10

  int var, numero;
  int p = 1; //boleano
  
  int temporario[NUMEROMAX];
  int primos[NUMEROMAX];
  
  int numero = 10; 
  void carrega(int alvo[]);
  void imprime(int alvo[]);
  void verifica(int para[] ,int de[]);
  
  
//-------------------------
int main(void) {
  
  carrega(temporario);
  verifica(primos, temporario);
  imprime(primos);
  
    return 0;
}
//-------------------------

void carrega(int alvo[]){
  
  int n = 3;
  for(int i = 0; i <= (NUMEROMAX -1) && n <= NUMEROMAX; ++i) {
    
    alvo[i] = n;
    ++n;
  }
}

void verifica(int para[],int de[]) {
  
  int i, j, k;
  k=0;
  j = 2;
  
  for (i = 0; i < (NUMEROMAX - 1); i++) {
    
    while (j < de[i]) {
      
      if((de[i]%j)!=0) {
        p = 1;
      }
      
      else {
        p = 0;
      }
      ++j;
    }
    
    if(p=1){
      para[k] = de [i];
    }
    
    ++k;
  }
}

void imprime(int alvo[]) {
  printf("\n");
  
  for(int i = 0; i <= NUMEROMAX; ++i){
    
    printf("%d-", alvo[i]);
    
  }
  printf("\n");
  
}
