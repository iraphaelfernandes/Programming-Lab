#include <stdio.h>

#define DENTRO 1 	// dentro de uma palavra
#define FORA 0 	// fora de uma palavra

// conta linhas, palavras e caracteres na entrada
int main(){
	int c,estado = 0;

	while ((c= getchar()) != EOF){	// EOF variavel interna de fim de string
		if (c == ' ' || c == '\n' || c == '\t'){
			putchar('\n');			
			estado = FORA;
		} else {
			estado = DENTRO;
			putchar(c);
		}
	}
/*
		++nc;									 
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			estado = FORA;
		else if (estado == FORA) {
			estado = DENTRO;
			++np;		
			}
*/
		
		//printf("%d %d %d\n",nl,np,nc);	

	return 0;
}
