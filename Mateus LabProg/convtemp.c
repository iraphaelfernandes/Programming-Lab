#include <stdio.h>

int main ()
{
	float fahr, celsius;
	int inicio, fim, incr;
	
	inicio = 0; /* limite inferior da tabela */
	fim = 149; /* limite superior */
	incr = 20; /* incremento */

	celsius = inicio;

	while (celsius <= fim) {
		fahr = (celsius * ( 9.0 / 5.0) + 32);
		printf ("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius  + incr;
}
   return 0;
}
