#include <stdio.h>
#include <string.h>


#define DENTRO 1 /* dentro de uma palavra */
#define FORA 0 /* fora de uma palavra */

void inverte(char s[]);

int main ()
{
	int c, i, np, estado;
	char palavra [1000];

	estado = FORA;
	np=0;
	fgets(palavra,1000,stdin);
	for (i=0; palavra[i] != '\0'; i++) {
		c = palavra[i];
		if(c==' ' || c=='\n' || c=='\t'){
			if (estado == FORA){ 
				++np;
				if (c == ' '){
					putchar(' ');
				}
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
	printf ("\n %d \n", np);
  return 0;
  }


void inverte(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
