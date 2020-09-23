#include <stdio.h>

// 1 - Escreva um programa que conte espaços,
// caracteres de tabulação e de nova-linha.(exerc 1.8)

int main(void)
{
  int c;

  long nl = 0, tab = 0, space = 0;

  while ((c = getchar()) != EOF)
  {

    if (c == '\n')
    {
      ++nl;
    }

    if (c == '\t')
    {
      ++tab;
    }
    if (c == ' ')
    {
      ++space;
    }
  }

  printf("Numero de novas linhas: %ld.\nNumero de tabulacao: %ld.\nNumero de espacos: %ld.\n ", nl, tab, space);

  return 0;
}