#include <stdio.h>

#define MAXLINE 1000 //tamnaho máximo da linha

int max;             //tamnho visto até agora
char linha[MAXLINE]; //linha de entrada
char maior[MAXLINE]; //linha mais longa

int lelinha(void);
void copia(void);

int main(void)
{
  int tam;
  extern int max;
  extern char maior[];
  max = 0;

  while ((tam = lelinha()) > 0)
  {
    if (tam > max)
    {
      max = tam;
      copia();
    }
  }

  if (max > 0)
  {
    printf("%s", maior);
  }

  return 0;
}

int lelinha(void) //--------------------
{
  int c, i = 0;
  extern char linha[];

  for (; i < MAXLINE - 1 && (c = getchar() != '\n') && c != EOF; ++i)
  {
    linha[i] = c;
  }
  if (c == '\n')
  {
    linha[i] = c;
    ++i;
  }
  linha[i] = '\0';
  ++i;
}

void copia(void) //-------------------
{
  int i = 0;
  extern char linha[], maior[];

  while ((maior[i]) = linha[i] != '\0')
  {
    ++i;
  }
}
