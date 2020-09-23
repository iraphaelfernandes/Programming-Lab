// 2 - Escreva um programa que copie sua entrada na saída,
// trocando cada cadeia de
// dois ou mais espaços por um único espaço.

#include <stdio.h>

int main(void)
{
  char c;
  char last_c;
  while ((c = getchar()) != EOF)
  {

    if (c != ' ' || last_c != ' ')
    {
      putchar(c);
    }

    last_c = c;
  }

  return 0;
}
