#include <stdio.h>
// 3 - Modifique o programa de conversão de temperatura para
// imprimir a tabela em
// ordem inversa, isto é, de 300 graus até 0 grau. (exerc. 1.5)

int main(void)
{

  printf("Imprime tabela Fahrenheit-Celcius m ordem inversa\n");

  for (int fahr = 300; fahr >= 0; fahr = fahr - 20)
  {

    printf("%3d %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }

  return 0;
}