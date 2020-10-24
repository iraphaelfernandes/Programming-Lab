
#include <stdio.h>

/* imprime a tabela de conversão Clsius-Fahrenheit
para fahr = 0, 20,..., 300 */

int main(void) {
 float fahr, celcius;
 int inicio, fim , incr;
 inicio = -17;
 fim = 150;
 incr = 20;
 fahr = inicio;
 
 while (celcius <= fim) {
 fahr = 32 + (9*celcius)/5;
 printf("%3.0f %6.1f\n", celcius, fahr);
 celcius = celcius + incr;
 }
 return 0;

}
