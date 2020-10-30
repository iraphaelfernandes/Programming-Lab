#include <stdio.h>
#define MAXLINHA 3 				/*tamanho máximo da linha entrada*/

int lelinha (char linha [], int maxlinha);	
//tamanho da linha 
//linha atual,		tamanho maximo de linha suportado

void copia (char para [], char de []);
/* imprime maior linha entrada */

main (){
	int tam; /* tamanho atual da linha */
	int max; /* tamanho máximo visto até agora */
	char linha [MAXLINHA]; /* linha atual */
	char maior [MAXLINHA]; /* maior linha guardada */
	max = 0;

	while ((tam = lelinha (linha,MAXLINHA)) > 0)	//enquanto tamanho for maior q 0
		if (tam > max) {		// executa se a lida for maior que a atual
			max = tam;
			copia (maior, linha);
		}
	//if (max > 0) /* entrada tinha uma linha */
		printf ("%s\n", maior);
	return 0;
}



/* lelinha: lê uma linha em s, retorna tamanho */
int lelinha (char s [], int lim){
	int c, i;
	for(i=0; i<lim-1&&(c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
		if (c=='\n') {
			s[i]=c;
			++i;
	}
	s[i]= '\0';
	return i;
}


/* copia: copia 'de' -> 'para'; presume que 'para' é grande o suficiente */
void copia (char para [], char de []){
	int i;
	i = 0;
	while ((para [i] = de [i]) != '\0')
		++i;
}

