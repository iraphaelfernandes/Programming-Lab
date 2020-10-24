#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void gera_frase(char s1[]);
void compara_string(char s1[], char s2[]);
void gera_filho(char s1[]);

int main()
{
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	char frase[25];
	char filho[25];
	gera_frase(frase);
	compara_string(frase,meta);
	gera_filho(frase);
	strcpy(filho,frase);
	compara_string(filho, meta);
	return 0;
}

void gera_frase(char frase[]){
	int i = 0;
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	for (i=0; i< 26; i++){
		frase[i] = letras[ rand() % strlen(letras)];
	}
	printf("A frase gerada e:\n%s\n", frase);	
}
	
void compara_string(char s1[], char s2[]){
	int cont, i = 0;
    for (i=0; i< 26; i++){
			if (s1[i] == s2[i])
			cont++;
		}
    printf("o numero de pontos foi:\n%d\n", cont);
}

void gera_filho(char filho[]){
	int i,  aux = 0;
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	for (i=0; i<26; i++){
			aux = rand() % 100;
			if (aux < 5){
				filho[i] =  letras[ rand() % strlen(letras)];
			}
	}
	printf("A frase gerada e:\n%s\n", filho);
	
}
