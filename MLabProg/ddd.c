#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void gera_frase(char s1[]);
void compara_string(char s1[], char s2[]);

int main()
{
	char frase[25];
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	gera_frase(frase);
	compara_string(frase,meta);
	return 0;
}

void gera_frase(char s1[]){
	int j, i, cont, aux = 0;
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char frase[25];
	for (i=0; i< 26; i++){
		aux = rand () %27;
		frase[i] = letras[aux];
	}
	for (j=0; j< 26; j++){
			if (meta[j] == frase[j])
			cont++;
		}
	printf("A frase gerada e:\n%s\n", frase);	
	printf("o numero de pontos foi:\n%d\n", cont);	
}
	
