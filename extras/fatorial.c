#include <stdio.h>


int	main() {
  
  
  int c, n, f = 1;
  n = 70;
  
  for(c= 1; c <= n; c++) {
    
    f = f * c;
    
  }
  
  printf("Fatorial de %d = %d\n", n ,f);
  
  return 0;
}
