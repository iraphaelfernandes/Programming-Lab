
#include <stdio.h>

/* imprime a tabela de conversão Fahrenheit-Celcius*/

#define INICIO 0
#define FIM 300
#define INCR 20

int main(void) {
	
	for (int fahr=INICIO; fahr <= FIM; fahr = fahr + INCR) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr -32));
	}

 
 return 0;

}
