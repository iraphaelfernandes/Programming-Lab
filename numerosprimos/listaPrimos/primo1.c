#include <stdio.h>
int main()
{
  int n, i = 3, count, c;

  printf("Quantos numeros primos?\n");
  scanf("%d", &n);

  if (n >= 1) {
    printf("Os primeiros %d° numeros primos:\n",n);
    printf("2\n");
  }

  for (count = 2; count <= n;)
  {
    for (c = 2; c <= i - 1; c++)
    {
      if (i%c == 0)
        break;
    }
    if (c == i)
    {
      printf("%d\n", i);
      count++;
    }
    i++;
  }

  return 0;
}