#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void gera_frase(char s1[]);
int compara_string(char s1[], char s2[]);
void gera_filho(char s1[]);
void involucao(char s1[], char s2[]);

int main()
{
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	char frase[26];
	gera_frase(frase);
	printf("A pontuacao inicial e:\n%d\n", compara_string(frase,meta));
	printf("-------------------------\n");
	gera_filho(frase);
	return 0;
}

void gera_frase(char frase[]){
	int i = 0;
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	for (i=0; i< 26; i++){
		frase[i] = letras[ rand() % strlen(letras)];
	}
	frase[i] = '\0';
	printf("A frase gerada e:\n%s\n", frase);	
}
	
int compara_string(char s1[], char s2[]){
	int cont = 0;
	int i = 0;
    for (i=0; i< 26; i++){
			if (s1[i] == s2[i])
			cont++;
		}
    return cont;
}

void involucao(char s1[], char s2[]){
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	if (compara_string(s1,meta) >= compara_string(s2,meta)){
		printf("INVOLUCAO!\n");
	}
}

char *geranfilhos(char s[])	
{
	int i = 0;
	int aux = 0;
	int j = 0;
	char s2[j][i];
	char *escolhido;
	escolhido=(char*)malloc(27*sizeof(char));
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char meta[] = "CELACANTO PROVOCA MAREMOTO";
	for (j=0; j<100; j++){
		strcpy(s2[j],s);
	for (i=0; i<26; i++){
			aux = rand() % 100;
			if (aux < 5){
				s2[j][i] =  letras[ rand() % strlen(letras)];
			}
	}
		printf("O filho(%d) gerado e:\n%s\n", j, s2[j]);
		if (compara_string(s2[j],meta) > compara_string(escolhido,meta)){
			strcpy(escolhido, s2[j]);
		}
	}
	return (escolhido);
}
	

void gera_filho(char s[]){
	char escolhido[27];
	//int cria = 0;
	srand ( time(NULL) );
	strcpy(escolhido,"0000000000000000000000000");
	geranfilhos(s);
	printf("A nova mae sera:\n%s\n", geranfilhos(s));
	//printf("Que e o filho numero:\n%d\n", cria);
	//printf("Com a pontuacao de:\n%d\n", compara_string(maior,meta));
	involucao(s,escolhido);
}
