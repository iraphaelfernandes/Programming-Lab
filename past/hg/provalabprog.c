#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX 100

void test(int c1, int c2, char msg[]);

void test(int c1, int c2, char msg[])
{
	if (c1 != c2) {
		printf("#Erro função %s: O retorno esperado era %i e o retorno foi %i \n", msg, c2, c1);	
	}
	assert(c1 == c2);
}

int main()
{
	printf("Digite uma frase: \n");
	char frase[100] = {'\0'};
	fgets(frase, MAX, stdin);
	printf("Frase digitada foi:%s \n", frase);
	printf("tamanho: %i\n", (int) strlen(frase));
	test(strcmp("oi", "oi"), 1 ,"oi deve ser igual a oi");
	return 0;
}
