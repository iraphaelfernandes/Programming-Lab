#include <stdio.h>

//2- Escreva um programa para imprimir a tabela
//correspondente de Celsius a Fahre-nheit. (exerc. 1.4)

int main(void)
{

  printf("Imprime tabela Celcius-Fahrenheit\n");

  for (int cel = 0; cel <= 100; cel = cel + 10)
  {
    printf("%3d %6.1f\n", cel, ((9.0 / 5.0) * cel + 32));
  }

  return 0;
}