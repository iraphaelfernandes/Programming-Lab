#include <stdio.h>

#define DENTRO 1
#define FORA 0

// Conta linhas (nl), palavras (np) e caracteres (nc) de entrada
// c assume o valor de getchar()

int main(void)
{
  int c, nl, np, nc;
  nl = np = nc = 0;
  int estado = FORA;

  while ((c = getchar()) != EOF)
  {

    ++nc;

    if (c == '\n')
    {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t')
    {
      estado = FORA;
    }

    else if (estado == FORA) {
      estado = DENTRO;
      ++np;   
      }
  }

  return 0;
}