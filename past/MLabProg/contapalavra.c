#include <stdio.h>

#define DENTRO 1 /* dentro de uma palavra */
#define FORA 0 /* fora de uma palavra */

/* conta palavras e imprime 5 por linha na saida */
int main ()
{
	int c, np, estado;

	estado = FORA;
	np=0;
	while ((c = getchar()) != EOF) {
		if(c==' ' || c=='\n' || c=='\t'){
			if (estado == FORA){ 
				++np;
				if (np == 5){
				putchar('\n');
			}
		}
		estado = DENTRO;
				
			}
			else {
			estado = FORA;
			putchar(c);
			}
		}
	printf ("%d \n", np);
  return 0;
  }
