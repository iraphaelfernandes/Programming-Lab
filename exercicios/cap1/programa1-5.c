

#include <stdio.h>

/* imprime a tabela de conversão Fahrenheit-Celcius*/

int main(void) {
	
	for (int fahr=0; fahr <= 300; fahr = fahr +20) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr -32));
	}

 
 return 0;

}
