
#include <stdio.h>

/* imprime a tabela de conversão Fahrenheit-Celsius
para fahr = 0, 20,..., 300 */

int main(void) {
 float fahr, celcius;
 int inicio, fim , incr;
 inicio = 0;
 fim = 300;
 incr = 20;
 fahr = inicio;
 
 while (fahr <= fim) {
 celcius = 5*(fahr - 32)/9;
 printf("%3.0f %6.1f\n", fahr, celcius);
 fahr = fahr + incr;
 }
 return 0;

}
