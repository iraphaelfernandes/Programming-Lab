#include <stdio.h>

int main(void)
{

  int total = 0, ch;

  while ((ch = getchar()) != EOF)
  {
    if (ch != '\n' && ch != '\t')
    {
      ++total;
    }
  }

  printf("\n%d caracteres digitados\n", total);

  return 0;
}