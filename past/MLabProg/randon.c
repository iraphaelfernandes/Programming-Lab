#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int i = 0;
	srand ( time(NULL) );
	char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char frase[25];
	for (i=0; i< 26; i++){
		frase[i] = letras[ rand() % strlen(letras)];
	}
	printf("\nA frase gerada e:\n%s\n", frase);

		
		
	return 0;
}

