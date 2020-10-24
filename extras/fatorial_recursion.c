#include <stdio.h>

long fatorial(int);

int	main() {
  
  int n;
  long f;
  
  printf("\nEnter an integer to find its factorial\n");
  scanf("%d", &n);
  
  if(n<0) {
    printf("\nFactorial of negative integers isn't defined.\n");
  }
  
  else {
    
  f = fatorial(n);
  printf("%d! = %ld\n", n, f);
  }
  

  
  return 0;
}


long fatorial(int n) {
  
  if(n == 0) { //caso base
    return 1;
  }
  
  else {
    return(n*fatorial(n-1));
  }
}