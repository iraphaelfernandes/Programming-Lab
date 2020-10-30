
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void stringToHex(char caracteres[], char hex[]);
int atoi(char c);
char converteEmLetra(int n);

int main()
{
	char caract[] = "ABCDeFgHAbCdefGHABCDefghabcDEFGh";
	char hex[32] = {'\0'};
	stringToHex(caract, hex);
	printf("Deve retornar: f5a3f01e real: %s\n", hex);
	return 0;
}

void stringToHex(char caracteres[], char hex[])
{
	int i,j, num = 0;
	char bin[32] = {'\0'};
	for(i=0; caracteres[i] != '\0'; i++){
		if (isupper(caracteres[i]) == 0) {
			bin[i] = '0';
		} else {
			bin[i] = '1';
		}
		num = 2 * num + atoi(bin[i]);
		if (((i+1)%4) == 0)
		{
			hex[j++] = converteEmLetra(num);
			num = 0;
		}
		
	}
}

int atoi(char c)
{
	return c - '0';
}

char converteEmLetra(int n)
{
	
	if (n >= 10)
		return (n % 10) + 'a';
	return n + '0';
}

