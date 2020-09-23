#include <stdio.h>

int main(void)
{
  printf("Imprime tabela Fahrenheit-Celcius\n");

  for (int fahr = 0; fahr <= 300; fahr = fahr + 20)
  {

    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }

  return 0;
}