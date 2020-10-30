#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// 2- Escreva uma versão alternativa de comprime (s1, s2) 
// que remova cada caractere de s1 que se case a algum 
// caractere presente na string s2. 

#define MAX 1000

void comprime(char str1[], char str2[]);


//------------------------------------
int main(void) {
  
  char str1[MAX] = "123456";
  char str2[MAX] = "123";
  
  comprime( str1, str2);
  
  printf("\nO retorno eh: %s\n", str1);

  return 0;
}
//------------------------------------

void comprime(char str1[], char str2[]) {
  
  int i, j, k;
  
  for(k = 0; str2[k] != '\0'; ++k) {
    
    for (i = j = 0; str1[i] != '\0'; ++i) {
      
      if(str1[i] != str2[k]) {
        
        str1[j++] = str1[i];
      }
    }
    
    str1[j] = '\0';
  } 
}