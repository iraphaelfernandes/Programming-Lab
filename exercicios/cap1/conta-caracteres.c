#include <stdio.h>

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

    getchar();
  }

  printf("Numero de novas linhas: %ld.\nNumero de tabulacao: %ld.\nNumero de espacos: %ld.\n ", nl, tab, space);

  return 0;
}