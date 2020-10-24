#include <stdio.h>

void reverse(char*, int, int);

int main(){
  
  char a[100];
  gets(a);
  
  reverse(a, 0, strlen(a) - 1);
  
  printf("%s\n", a);
  
  return 0;
}

void reverse(char *x, int begin, int end){
  
  char c;
  
  if(begin >= end){
    return;
  }
  
}
