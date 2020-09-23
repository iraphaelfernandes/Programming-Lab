// 3 - Escreva um programa para copiar sua entrada na saída,
// trocando cada tabulação
// por \t, cada retrocesso por \b e cada contrabarra por \\.
// Isso torna as marcas de tabulação e
// retrocessos visíveis de forma não ambígua.

#include <stdio.h>

int main(void)
{
  char c;
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      putchar('\\');
      putchar('t');
    }
    else if (c == '\b')
    {
      putchar('\\');
      putchar('b');
    }
    else if (c == '\\')
    {
      putchar('\\');
      putchar('\\');
    }
    else
    {
      putchar(c);
    }
  }

  return 0;
}
