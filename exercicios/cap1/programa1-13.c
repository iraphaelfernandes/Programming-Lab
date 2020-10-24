#include <stdio.h>

int pot(int m, int nl);

int main(void)
{
  for (int i = 0; i < 10; ++i)
  {
    printf("%d\t%d %d\n", i, pot(2, i), pot(3, i));
  }

  return 0;
}

int pot(int base, int n)
{
  int p = 1;

  for (int i = 1; i <= n; ++i)
  {
    p = p * base;
  }

  return p;
}