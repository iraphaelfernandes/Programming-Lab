#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000
#define ALERT 100

void inverter(char frase[], char frase_inversa[]);
void invertePalavra(char palavra[]);
int deveSerInvertida(char palavra[]);
int lelinha (char s [], int lim);

int main()
{
	printf("Para o programa ser executado, pressione ctrl + D \n");
	printf("Digite a linha que você deseja inverter:");
	char entrada[MAX] = {'\0'};
	char frase_inversa[MAX] = {'\0'};
	lelinha(entrada, MAX);
	inverter(entrada, frase_inversa);
	printf("\nA frase invertida é: \n%s", frase_inversa);
	return 0;
}

void inverter(char frase[], char frase_inversa[])
{
	int i,j = 0, k = 0, palavras = 0;
	char palavra[MAX];
	for(i=0;frase[i] != '\0';i++,k++)
	{
		if (isalnum(frase[i]))
		{
			palavra[j++] = frase[i];
		} else {
			palavra[j] = '\0';
			
			if (deveSerInvertida(palavra) == 1) {
				invertePalavra(palavra);
			}
			
			strcat(frase_inversa, palavra);
			
			if (frase[i] == ' ' || frase[i] == '\t') {
				palavras++;
			}
			
			if (frase[i] == '\n') {
				palavras = 0;
			}
			
			frase_inversa[k] = frase[i];
			
			if (palavras == 5) {
				strcat(frase_inversa, "\n");
				k++;
				palavras = 0;
			}
			
			j = 0;
		}
	}
	
	// Adiciona ultima palavra caso não termine por ponto ou espaço
	if(j > 0){
		palavra[j] = '\0';
		if (deveSerInvertida(palavra) == 1) {
			invertePalavra(palavra);
		}
		strcat(frase_inversa, palavra);
	}
	
}

void invertePalavra(char palavra[])
{
	int i, tam = strlen(palavra);
    for(i = 0; i < tam / 2; i++) {
		char tmp = palavra[i]; 
		palavra[i] = palavra[tam - i - 1];
		palavra[tam - i - 1] = tmp;
    }
}

int deveSerInvertida(char palavra[])
{
	int i;
	for(i=0;palavra[i] != '\0';i++)
	{
		if (isdigit(palavra[i])){
			return 0;
		}
	}
	return 1;
}

int lelinha (char s [], int lim)
{
	int c, i, contadorErro = 0, error = 0;
	for(i=0; i<lim-1&&(c=getchar())!=EOF; ++i, contadorErro++){
		s[i] = c;
		if (contadorErro > ALERT) {
			error = 1;
		}
		if (c == '\n') {
			contadorErro = 0;
		}
	}
		
	if (c=='\n') {
		s[i]=c;
		++i;
	}
	
	if (error) {
		printf("#Error: A linha possui mais de 100 caracteres!");
	}
	

	s[i]= '\0';
	return i;
}

