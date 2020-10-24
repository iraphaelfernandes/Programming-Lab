#include <stdio.h>

int string_length(char [], int);

int main() {
  
  char s[100];
  int l = 0;
  gets(s);
  
  printf("Length = %d\n", string_legth(s, l));
  
  
  return 0;
}

int string_length(char s[], int l) {
  
  if (s[l] == '\0') {
    return l;
  }
  
  l++;
  return (string_legth(s, l));
  
}